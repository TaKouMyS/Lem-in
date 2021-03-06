/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:12:16 by amamy             #+#    #+#             */
/*   Updated: 2019/11/06 11:00:10 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** ==================== is_com_start_end ====================
** Checks if the line is start or end command.
*/

static int	is_com_start_end(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (-1);
	if (ft_strcmp(line, "##end") == 0)
		return (-1);
	return (0);
}

/*
** ==================== store ====================
** Store the line in a new link of chained list.
*/

static int	store(t_farm *f, char *line, int ret)
{
	t_input *new;

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

/*
** ====================  ====================
** In case gnl_store is called when reading ants or links :
** Checks if command is ##start or ##end.
** Store the line and return the next line which is not comment.
*/

static int	read_from_ants_links(t_farm *f, char **line, int ret, int fd)
{
	while (ret > 0 && line[0] && line[0][0] == '#')
	{
		if (is_com_start_end(line[0]) == -1 || store(f, line[0], ret) == -1)
			ret = -1;
		ft_memdel((void*)line);
		if (ret != -1)
			ret = get_next_line(fd, &line[0]);
	}
	return (ret);
}

/*
** ==================== gnl_store ====================
** Read the next line on stdin and send it to storage.
** If line is comment, store it and read again until un_commented line
*/

int			gnl_store(int fd, char **line, t_farm *f, int origin)
{
	int ret;

	ret = get_next_line(fd, line);
	if (ret > 0 && line[0] && line[0][0] == '#' && origin == GET_ANTS_LINKS)
	{
		if ((ret = read_from_ants_links(f, &line[0], ret, fd)) == -1)
		{
			ft_memdel((void*)line);
			return (-1);
		}
	}
	if (!(store(f, line[0], ret) == 0))
		return (-1);
	return (ret);
}
