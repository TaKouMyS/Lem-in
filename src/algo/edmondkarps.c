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
#include "lem-in.h"


int		find_neg_flow(t_queue *q, t_room *r)
{
	int i;

	i = 0;
	if (q->visited[r->links[i]] != 1 && q->flow[r->id][r->links[i]] == -1) //if there is a link and we have not visited the link
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

int		find_flow(t_queue *q, t_room *r, int prev_flow)
{
	int		j;

	j = 0;

//	if (prev_flow == 0 && find_neg_flow(q, r) == 1)
//		return (0);
	while (j < r->links_nb)
	{
//	printf("\ttrying %d, visited = %d flow = %d\n", r->links[j], q->visited[r->links[j]], q->flow[r->id][r->links[j]]); //if there is a link and we have not visited the link
		if (q->visited[r->links[j]] != 1 //if there is a link and we have not visited the link
			&& q->flow[r->id][r->links[j]] != 1)
		{
	//		printf("\tgot in\n");
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
        if (q->flow[p][s] == 0) //if there's no flow mark forward/reverse flow as 1/-1
        { 
//			ft_printf("flow %s %s to 1 / -1\n", f->id_table[p]->name, f->id_table[s]->name);
			q->flow[p][s] = -1;
			q->flow[s][p] = 1;
		}                              	
        else if (q->flow[p][s] == -1 || q->flow[p][s] == 1) //if there is flow, neutralise to zero
        { 
//			ft_printf("flow %s %s to 0\n", f->id_table[p]->name, f->id_table[s]->name);
			q->flow[p][s] = 0;
			q->flow[s][p] = 0;
		}
		p = s; //check next node
	}
}
int is_flow_saturated(t_farm *f, t_queue *q)
{
	int i;

	i = 0;
	while (i < f->start->links_nb)
	{
	//	printf("flow %d to %d = %d\n", f->start->id, f->start->links[i], q->flow[f->start->id][f->start->links[i]]);
		if (q->flow[f->start->id][f->start->links[i]] == 0)
			return (0);
		++i;
	}

	return (1);
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
	//	printf("node = %d ", node);
		find_flow(q, f->id_table[node], prev_flow);
    }
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
			ft_printf("flow from %s to %s = %d\n", f->id_table[i]->name, f->id_table[j]->name, q->flow[i][j]);
			++j;
		}
		++i;
	}
	ft_putchar('\n');
			printf("\n..............\n");
	return (0);
}

int		edmondskarp(t_queue *q, t_farm *f, t_list **path_list)
{
	int		max;
	int		i;

	*path_list = ft_lstnew(NULL, 0);
	i = 0;
	f->max_paths = 0;
	while (is_flow_saturated(f, q ) == 0)
	{
		optimise_flow(f, q);
	//	printf("flow ");
		save_flow(q, f);
//		mark_path(f, q);
	//	printflow(q, f);
		save_paths(q, f, path_list);
	//	printflow(q, f);

	//	clear_queue(q);
		//++f->max_paths;
	}
//	printf("max= %d", f->max_paths);
	//printflow(q, f);
//	reset_queue(q, f->start->id, f->end->id);
//	if ((max = count_paths(q, f)) <= 0)
//		return (-1);
//	clear_queue(q);
//	*paths = save_paths(q, f, max);
	return (f->max_paths);
}
