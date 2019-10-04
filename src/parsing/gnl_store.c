/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:12:16 by amamy             #+#    #+#             */
/*   Updated: 2019/10/04 07:28:49 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem-in.h"

int gnl_store(int fd, char **line, t_farm *f, int origin)
{
    int     ret;
    t_input *new;
    t_input *tmp;
    ret = get_next_line(fd, line);
    ft_printf("Ori = %d\n line : |%s|\n", origin, line[0]);
    if (ret > 0 && line[0] && line[0][0] == '#' && origin == GET_ANTS_LINKS)
    {
        // ret = gnl_store(fd, line, f, GET_ANTS_LINKS);
        ret = get_next_line(fd, line);
        ft_printf("comment : |%s|\n", line[0]);
    }
    tmp = f->input;
    if (ret > 0)
    {
        f->input->line = ft_strdup(*line);
        if (!(new = ft_memalloc(sizeof(t_input))))
            return (-1);
        f->input->next = new;
        f->input = new;
        f->input->prev = tmp;
    }
    return (ret);
}