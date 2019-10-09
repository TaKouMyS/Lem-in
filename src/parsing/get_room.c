/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:22:19 by amamy             #+#    #+#             */
/*   Updated: 2019/10/09 17:47:56 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** ==================== check_start_end ====================
** If the line passed equals ##start or ##end and we've already has some,
** return an error.
*/

static int	check_start_end(char *line, t_farm *f)
{
	if (ft_strcmp(line, "##start") == 0 && f->flags & START)
		return (-1);
	if (ft_strcmp(line, "##end") == 0 && f->flags & END)
		return (-1);
	return (0);
}

/*
** room_check_coo :
** checks if coordonates are numbers.
*/

static int	room_check_coo(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(line, ' ') + 1;
	while (tmp[i] != ' ' && tmp[i] != '\0')
		if (ft_isdigit(tmp[i++]) != 1)
			return (-1);
	if (tmp[i++] != ' ')
		return (-1);
	while (tmp[i] != '\0' && i <= 20)
		if (ft_isdigit(tmp[i++]) != 1)
			return (-1);
	return (0);
}

/*
** room_check_syntax :
** Receive a supposed room, check if the syntax is correct.
** Sends it to check if coordonates are integers.
** Syntax : name coo coo
** If line is a comment, sends it for checks.
*/

static char		*room_check_syntax(char *line)
{
	int		sp;
	int		i;
	char	*tmp;

	i = 0;
	sp = 0;
	tmp = line;
	if (line[0] != '#')
	{
		while (sp <= 3 && tmp != NULL)
			if (((tmp = ft_strchr(tmp, ' ')) != NULL) && tmp++)
				sp++;
		if (sp != 2 || line[0] == 'L' || room_check_coo(line) != 0)
		{
			ft_memdel((void*)&line);
			return (NULL);
		}
	}
	return (line);
}

/*
** init_room :
** Get the room's name, write it in the room's node and assigns a unic id to
** the room (first is 0, second is 1, etc...).
*/

static int	init_room(t_farm *f, t_room *r, char *line, int id)
{
	int		name_size;

	name_size = 0;
	while (line[name_size] != ' ')
		name_size++;
	if (!(r->name = ft_strndup(line, name_size)))
		return (-1);
	r->id = id;
	r->empty = -1;
	if (f->flags & START)
	{
		if (f->start)
			return (-1);
		f->start = r;
		f->flags &= ~START;
	}
	if (f->flags & END)
	{
		if (f->end)
			return (-1);
		f->end = r;
		f->flags &= ~END;
	}
	return (0);
}

/*
** get_room :
** Read stdin for rooms. Check room syntax and store them.
*/

int			get_room(t_room *r, t_farm *f)
{
	char	*line;
	int		ret;
	int		id;

	id = 0;
	ret = gnl_store(0, &line, f, GET_ROOMS);
	while (ret > 0 && line && ((ft_strchr(line, '-') == NULL) || line[0] == '#'))
	{
		if (line && line[0] == '#')
			line = is_comment(f, ret, line);
		if (line && ft_strchr(line, '-') == NULL)
		{
			if ((!(line) || check_start_end(line, f) != 0 			\
			|| (line = room_check_syntax(line)) == NULL) 	\
			|| (r = new_room(r)) == NULL || init_room(f, r, line, id++) != 0)
				return (error_free_line(line));
		}
		else if (line && ft_strchr(line, '-') != NULL && ((f->line = line)))
				return (0);
		ft_memdel((void*)&line);
		ret = gnl_store(0, &line, f, GET_ROOMS);
	}
	ft_memdel((void*)&line);
	return ((ret > 0) ? 0 : -1);
}
