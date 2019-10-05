/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:12:16 by amamy             #+#    #+#             */
/*   Updated: 2019/10/05 04:39:48 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem-in.h"

static int  is_com_start_end(char *line)
{
    if (ft_strcmp(line, "##start") == 0)
        return (-1);
    if (ft_strcmp(line, "##end") == 0)
        return (-1);
    return (0);
}

static int store(t_farm *f, char *line, int ret)
{
    t_input *new;
    t_input *tmp;
    
    tmp = f->input;
    if (ret > 0)
    {
        f->input->line = ft_strdup(line);
        if (!(new = ft_memalloc(sizeof(t_input))))
            return (-1);
        f->input->next = new;
        f->input = new;
    }
    return (0);
}

static int  read_from_ants_links(t_farm *f, char **line,int ret, int fd)
{
        if (is_com_start_end(line[0]) == -1 || store(f, line[0], ret) == -1)
            return (-1);
        while (ret > 0 && line[0] && line[0][0] == '#')
        {
            ret = get_next_line(fd, line);
            if (is_com_start_end(line[0]) == -1 || store(f, line[0], ret) == -1)
                return (-1);
        }
    return (ret);
}

int gnl_store(int fd, char **line, t_farm *f, int origin)
{
    int ret;

    ret = get_next_line(fd, line);
    if (ret > 0 && line[0] && line[0][0] == '#' && origin == GET_ANTS_LINKS)
    {
        if ((ret = read_from_ants_links(f, &line[0], ret, fd)) == -1)
            return (-1);
    }
    else
        if (!(store(f, line[0], ret) == 0))
            return (-1);
    return (ret);
}