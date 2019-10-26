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


int		find_neg_flow(t_queue *q, t_room *r, t_farm *f)
{
	int i;

	i = 0;
	while (i < r->links_nb)
	{
		if (q->visited[r->links[i]] != 1 && q->flow[r->id][r->links[i]] == -1) //if there is a link with negative flow we have not visited this iteration
		{
			q->queue[q->position] = r->links[i]; // add to end of queue
            q->prev[r->links[i]] = r->id; //note from which node we linked this node
			q->visited[r->links[i]] = 1; //mark it as visited
            ++q->position; //move up the end of queue marker
			f->id_table[r->links[i]]->weight = r->weight - 1;
		//	printf("%s weight - %d\n", f->id_table[r->links[i]]->name, f->id_table[r->links[i]]->weight);
			return (1);
        }
		++i;
	}
	return (0);
}
int	compare_weights(t_room *next, t_room *current, t_queue *q, t_farm *f)
{

	int pos;

	if (q->flow[current->id][next->id] != 0)
		pos = current->weight - 1;
	else
		pos = current->weight + 1;
//		printf("\t\t%s poss = %d, (%s) mnow = %d \n", next->name, current->weight + 1, current->name, next->weight);
	if (pos < next->weight && next->weight != 2147483647)
	{
		
		next->weight = pos;
		if (next !=  f->start)
		{
			q->flow[f->id_table[q->prev[next->id]]->id][next->id] = 0;
			q->flow[next->id][f->id_table[q->prev[next->id]]->id] = 0;
			if (q->flow[current->id][next->id] == -1)
			{
				q->flow[current->id][next->id] = 0;
				q->flow[next->id][next->id] = 0;
			}
			else
			{
				{
					q->flow[current->id][next->id] = 1;
					q->flow[next->id][next->id] = -1;
				}
			}
			compare_weights(f->id_table[q->prev[next->id]], next, q, f);
			q->prev[next->id] = current->id;
		}
		return (1);
	}
	return (0);
}

int		find_flow(t_queue *q, t_room *r, int prev_flow, t_farm *f)
{
	int		j;

	j = 0;

	//if we are coming from a flow of zero see if there's a negative flow available to us// if so add to queue and continue. If not we find other neighbousrs. 
//	if (f->id_table[r->links[j]]->weight != 2147483647)		
//			compare_weights(f->id_table[r->links[j]], r, q, f);
	if (prev_flow == 0 && find_neg_flow(q, r, f) == 1)
		return (0);
		f->start->weight = 0;
	while (j < r->links_nb)
	{

//	printf("root = %s, visiting %s, flow = %d\n", r->name, f->id_table[r->links[j]]->name, q->flow[r->id][r->links[j]]);
		if (q->visited[r->links[j]] != 1 //if there is a link and we have not visited the link
			&& q->flow[r->id][r->links[j]] != 1)
		{
			
			q->queue[q->position] = r->links[j]; // add to end of queue
            q->prev[r->links[j]] = r->id; //note from which node we linked this node
			q->visited[r->links[j]] = 1; //mark it as visited
            ++q->position; //move up the end of queue marker
			if (q->flow[r->id][r->links[j]] == 0)
				f->id_table[r->links[j]]->weight = r->weight + 1;
			else
				f->id_table[r->links[j]]->weight = r->weight - 1;
	//		printf("%s weight - %d prev = %s\n", f->id_table[r->links[j]]->name, f->id_table[r->links[j]]->weight, f->id_table[q->prev[r->links[j]]]->name);
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

int		optimise_flow(t_farm *f, t_queue *q)
{
    int		i;
    int		node;
	int		prev_flow;
    i = -1;
	clear_queue(q);
	reset_queue(q, f->start->id, f->end->id);
	prev_flow = 0;
	f->start->weight = 0;
    while (++i < q->length && q->visited[f->end->id] != 1 && q->queue[i] >= 0)
    {
        node = q->queue[i]; //sets node to the next node in the queue
		if (i > 0)
			prev_flow = q->flow[q->prev[node]][node];
		find_flow(q, f->id_table[node], prev_flow, f);
    }
	if (q->prev[f->end->id] == -1)
		return (-1);
	return (0);
}
//debugging function to print flow chart. To be deleted later. 
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

void	set_weights(t_farm *f)
{
	int i;

	i = -1;
	while (++i < f->room_nb)
		f->id_table[i]->weight = 2147483647;
	f->start->weight = 0;
}

int		edmondskarp(t_queue *q, t_farm *f, t_path **path_list)
{
	int		max;
	t_path	*new;

	*path_list = ft_new_path(NULL, 0);
	(*path_list)->longest = 0;
	set_weights(f);
	while (optimise_flow(f, q) == 0)
	{
		new = ft_new_path(NULL, 0);
		new->longest = 0;
		save_flow(q, f);
		set_to_n(&q->visited, q->length, 0);
    	reset_queue(q, f->start->id, f->end->id);
		save_paths(q, f, &new);
		if (new->len == -1) //malloc error
			return (-1);
		if ((*path_list)->longest == 0 || (*path_list)->longest > new->longest)
			{
				free_path((*path_list));
				*path_list = new;
			}
		else
			free_path(new);
		clear_queue(q);
	}
	return (0);
}
