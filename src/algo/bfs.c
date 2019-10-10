/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:28 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/10 17:31:29 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"

int		find_neg_flow(t_queue *q, t_room *r)
{
	int i;

	i = 0;
	if (q->visited[r->links[i]] == 0 && q->flow[r->id][r->links[i]] == -1) //if there is a link and we have not visited the link
		{
			//printf("parent = %d, neighbour = %d\n", node, j);
			q->queue[q->position] = r->links[i]; // add to end of queue
            q->prev[r->links[i]] = r->id; //note from which node we linked this node
			q->visited[r->links[i]] = 1; //mark it as visited
            ++q->position; //move up the end of queue marker
			return (1);
        }
	return (0);
}

int		find_neighbours(t_queue *q, t_room *r, int prev_flow)
{
	int j;

	j = 0;

	if (prev_flow == 0)
		if (find_neg_flow(q, r) == 1)
			return (0);   
	while (j < r->links_nb)
	{
		if (q->visited[r->links[j]] == 0 //if there is a link and we have not visited the link
			&& q->flow[r->id][r->links[j]] == 1)
		{
			q->queue[q->position] = r->links[j]; // add to end of queue
			q->prev[r->links[j]] = r->id; //note from which node we linked this node
			q->visited[r->links[j]] = 1; //mark it as visited
			++q->position; //move up the end of queue marker
		}
		++j;
	}
	return (0);
}

int		bfs(t_farm *f, t_queue *q)
{
	int		i;
	int		node;
	int		prev_flow;

	i = -1;
	prev_flow = 0;
	reset_queue(q, f->start->id, f->end->id);
	while (++i < q->length && q->visited[f->end->id] != 1 && q->queue[i] >= 0)
	{
		node = q->queue[i]; //sets node to the next node in the queue
		if (i > 0)
			prev_flow = q->flow[q->prev[node]][node];
		find_neighbours(q, f->id_table[node], prev_flow);
	}
	if (q->visited[f->end->id] != 1)//if while path finding we did not reach the end, we failed
		return (-1);
	return (0);
}
