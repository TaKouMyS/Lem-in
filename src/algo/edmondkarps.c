/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmondkarps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:20 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/10 17:31:21 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"



int		find_flow(t_queue *q, t_room *r, int prev_flow)
{
	int		j;

	j = 0;

                                                                                                                                   
	while (j < r->links_nb)
	{
		//printf("parent = %d j = %d, connections = %d, visited = %d, flow = %d\n", node, j, map[node][j], q->visited[j], q->flow[node][j]);
		if (q->visited[r->links[j]] == 0 && q->flow[r->id][r->links[j]] != 1) //if there is a link and we have not visited the link
		{
			//printf("parent = %d, neighbour = %d\n", node, j);
			q->queue[q->position] = r->links[j]; // add to end of queue
            q->prev[r->links[j]] = r->id; //note from which node we linked this node
			q->visited[r->links[j]] = 1; //mark it as visited
            ++q->position; //move up the end of queue marker
        }
        ++j;
    }
    return (0);
}

void	save_flow(t_queue *q, t_farm *f)
{
	int		p;
	int		s;
	p = f->end->id;
	while (p != f->start->id)
	{
		s = q->prev[p];
	//	printf("s = %d\n", s);
        if (q->flow[p][s] == 0) //if there's no flow mark forward/reverse flow as 1/-1
        { 
			q->flow[p][s] = -1;
			q->flow[s][p] = 1;
		}                              	
        else if (q->flow[p][s] == -1 || q->flow[p][s] == 1) //if there is flow, neutralise to zero
        { 
			q->flow[p][s] = 0;
			q->flow[s][p] = 0;
		}
		p = s; //check next node
	}
}

int		optimise_flow(t_farm *f, t_queue *q)
{
    int		i;
    int		node;
	int		prev_flow;
    i = -1;
	clear_queue(q);
	reset_queue(q, f->start->id, f->end->id);
	prev_flow = 0;
    while (++i < q->length && q->visited[f->end->id] != 1 && q->queue[i] >= 0)
    {
        node = q->queue[i]; //sets node to the next node in the queue
		if (i > 0)
			prev_flow = q->flow[q->prev[node]][node];
	//	printf("prev_flow = %d\n", prev_flow);
		find_flow(q, f->id_table[node], prev_flow);
	//	printf("node= %d\n", node);
    }
    if (q->visited[f->end->id] == 0) //if while path finding we did not reach the end, we failed
	    return(-1);
    return (0);
}

int		printflow(t_queue *q, t_farm *f)
{
	int		i;
	int		j;

	i = 0;
	while (i < q->length)
	{
		j = 0;
		while (j < q->length)
		{
			//ft_printf("flow from %d to %d = %d\n", i, j, q->flow[i][j]);
			++j;
		}
		++i;
	}
	return (0);
}

int		edmondskarp(t_queue *q, t_farm *f, int ***paths)
{
	int		max;
	int		i;

	i = 0;
	max = 0;
	while (optimise_flow(f, q) == 0)
		save_flow(q, f);
	//printflow(q, f);
	reset_queue(q, f->start->id, f->end->id);
	if ((max = count_paths(q, f)) <= 0)
		return (-1);
	clear_queue(q);
	*paths = save_paths(q, f, max);
	return (max);
}
