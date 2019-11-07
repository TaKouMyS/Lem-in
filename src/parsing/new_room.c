/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:02:47 by amamy             #+#    #+#             */
/*   Updated: 2019/11/07 16:20:43 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** ==================== room_exist ====================
** Given the name of a room, compare it to the name of all other room.
** If a room already have this name, return (-1) and stop exectuion.
*/

static int	room_exist(char *room, t_farm *f)
{
	t_room *tmp;

	tmp = f->first_room;
	while (tmp && tmp->next != NULL)
	{
		if (room[0] == tmp->name[0])
			if (ft_strcmp(room, tmp->name) == 0)
				return (-1);
		tmp = tmp->next;
	}
	return (0);
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
	if (room_exist(r->name, f) == -1)
		return (-1);
	r->id = id;
	r->empty = -1;
	if (f->flags & START && f->start == NULL)
	{
		f->start = r;
		f->flags &= ~END;
		f->flags &= ~START;
	}
	else if (f->flags & END && f->end == NULL)
	{
		f->end = r;
		f->flags &= ~START;
		f->flags &= ~END;
	}
	return (0);
}

/*
** new_room :
** Creates a new room and link it to the chained list.
** If START or END flag is raised, store it.
*/

t_room		*new_room(t_farm *f, t_room *r, char *line, long id)
{
	t_room *new;
	t_room *tmp;

	tmp = r;
	if (id > __INT_MAX__)
		return (NULL);
	if (r->name != NULL)
	{
		if (!(new = ft_memalloc(sizeof(t_room))))
			return (NULL);
		r->next = new;
		r = new;
		r->prev = tmp;
	}
	if (init_room(f, r, line, id) == -1)
		return (NULL);
	return (r);
}
