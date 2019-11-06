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

/*
** Sets all weights except the starting weight to INT MAX.
*/

void		set_weights(t_farm *f)
{
	int i;

	i = -1;
	while (++i < f->room_nb)
		f->id_table[i]->weight = __INT_MAX__;
	f->start->weight = 0;
}

/*
** Find the potential new weight, taking into account flows,
** and compare it with the current weight.
** If there's a flow of one between the two noes we return 0,
** as that means there is already a link between them.
*/

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

/*
** Check if connecting next and current would create any infinite loops.
*/

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

/*
** Checking if the current node is a better match for the next node, which
** is already in a link with a parent node. We first check neither node
** is start, and that we're not comparing the same node against itself.
** We then check that making the new link will create no infinite loops,
** and then if then compare the weights. If we are going to change the link
** in next to link with current, we first check if it could make a count parent
** node for it's soon to be abandoned parent. If so, we switch the links,
** and then make current its' parent.
*/

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
