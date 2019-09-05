/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:22:19 by amamy             #+#    #+#             */
/*   Updated: 2019/09/06 01:12:21 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

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
	char *tmp;
	int	i;

	i = 0;
	tmp = ft_strchr(line, ' ') + 1;
	while (tmp[i] != ' ' && tmp[i] != '\0')
		if (ft_isdigit(tmp[i++]) != 1)
			return (-1);
	if (tmp[i++] != ' ')
		return (-1);
	while (tmp[i] != '\0' && i <= 20 )
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

char			*room_check_syntax(char *line, t_farm *f)
{
	int	sp;
	int	i;
	char *tmp;
	char *next_line;

	i = 0;
	sp = 0;
	tmp = line;
	if (line[0] != '#')
	{
		while (sp <= 3 && tmp != NULL)
			if (((tmp = ft_strchr(tmp, ' ')) != NULL) && tmp++)
				sp++;
		if (sp != 2 || line[0] == 'L' || room_check_coo(line) != 0)
			return (NULL);
	}
	else
		if (get_next_line(0, &next_line) <= 0 \
			|| ((line = check_comment(line, next_line, f)) == NULL))
			return (NULL);
	return (line);
}

/*
** init_room :
** Get the room's name, write it in the room's node and assigns a unic id to
** the room (first is 0, second is 1, etc...).
*/

static int	init_room(t_room *r, char *line, int id)
{
	int		name_size;

	name_size = 0;
	while (line[name_size] != ' ') // need to add && line[name_size] != '\0'?
		name_size++;
	if (!(r->name = ft_strndup(line, name_size)))
		return (-1);
	r->id = id;
	ft_printf("name : |%s|	id : %d\n", r->name, id);
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
	ret = get_next_line(0, &line);
	while (ret > 0 && ft_strchr(line, '-') == NULL)
	{
		if ((!(line) || check_start_end(line, f) != 0 			\
			|| (line = room_check_syntax(line, f)) == NULL) 	\
			|| (r = new_room(r, f)) == NULL || init_room(r, line, id) != 0)
		{
			ft_memdel((void*)&line);
			return (-1);
		}
		id++;
		ft_memdel((void*)&line);
		ret = get_next_line(0, &line);
	}
	if (ft_strchr(line, '-') != NULL)
		f->line = line;
	else
		ft_memdel((void*)&line);
	if (ret <= 0)
		return (-1);
	return (0);
}
