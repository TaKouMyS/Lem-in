/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:28 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/29 01:51:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** This finds linked or (neighbouring) nodes and adds them to the queue
** if they are accessible (flow of 1) and they have not already been
** visited.
*/

static int		find_neighbours(t_queue *q, t_room *r)
{
	int j;

	j = 0;
	while (j < r->links_nb)
	{
		if (q->visited[r->links[j]] == 0
			&& q->flow[r->id][r->links[j]] == 1)
		{
			q->queue[q->position] = r->links[j];
			q->prev[r->links[j]] = r->id;
			q->visited[r->links[j]] = 1;
			++q->position;
		}
		++j;
	}
	return (0);
}

/*
** This is a breadth-first search function. We traverse the graph in levels,
** terminating the search when we visit end. If we visit all possible nodes
** but do not visit end, we return -1, to indicate a path was not foud.
*/

int				bfs(t_farm *f, t_queue *q)
{
	int		i;
	int		node;

	i = -1;
	set_to_n(&q->queue, q->length, -1);
	reset_queue(q, f->start->id, f->end->id);
	while (++i < q->length && q->visited[f->end->id] != 1 && q->queue[i] >= 0)
	{
		node = q->queue[i];
		find_neighbours(q, f->id_table[node]);
	}
	if (q->visited[f->end->id] != 1)
		return (-1);
	if (q->flow[f->start->id][f->end->id] == 1 && q->prev[f->end->id] == f->start->id)
		q->flow[f->start->id][f->end->id] = 0;
	return (0);
}
