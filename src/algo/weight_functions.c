/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:48:06 by fcahill           #+#    #+#             */
/*   Updated: 2019/11/02 20:48:09 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_weights(t_farm *f)
{
	int i;

	i = -1;
	while (++i < f->room_nb)
		f->id_table[i]->weight = __INT_MAX__;
	f->start->weight = 0;
}

static int	compare_weights(t_room *next, t_room *current, t_queue *q)
{
	int pos;

	if (q->flow[current->id][next->id] == 1)
		return (0);
	if (q->flow[current->id][next->id] == -1)
		pos = current->weight - 1;
	else
		pos = current->weight + 1;
	if (pos < next->weight && next->weight != __INT_MAX__)
	{
		next->weight = pos;
		return (1);
	}
	return (0);
}

static int	check_loops(t_room *current, t_room *next, t_queue *q, t_farm *f)
{
	int i;

	i = q->prev[current->id];
	while (i != f->end->id && i != f->start->id)
	{
		if (i == next->id)
			return (1);
		if (i == current->id)
			return (1);
		if (i == q->prev[next->id])
			return (1);
		i = q->prev[i];
	}
	return (0);
}

int			check_weights(t_room *next, t_room *current, t_queue *q, t_farm *f)
{
	if (next == f->start || current == f->start || next == current)
		return (0);
	if (check_loops(current, next, q, f) == 1)
		return (0);
	if (compare_weights(next, current, q) == 0)
		return (0);
	if ((f->id_table[q->prev[next->id]] != f->start) &&
		(check_loops(f->id_table[q->prev[next->id]], next, q, f) == 0)
		&& (compare_weights(f->id_table[q->prev[next->id]], next, q) == 1))
		q->prev[q->prev[next->id]] = next->id;
	q->prev[next->id] = current->id;
	return (1);
}
