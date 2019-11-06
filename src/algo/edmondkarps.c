/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmondkarps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:20 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/29 02:27:27 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Here we check if there is a potential negative flow to explore from the
** parent node. I.e. a path breaking flow. If there is we return 1, and
** ignore the positive flowing child nodes for now. We also check weights
** of visited child nodes.
*/

static int	find_neg_flow(t_queue *q, t_room *r, t_farm *f)
{
	int		i;

	i = 0;
	while (i < r->links_nb)
	{
		if (f->id_table[r->links[i]]->weight != __INT_MAX__)
			check_weights(f->id_table[r->links[i]], r, q, f);
		if (q->visited[r->links[i]] != 1 && q->flow[r->id][r->links[i]] == -1)
		{
			q->queue[q->position] = r->links[i];
			q->prev[r->links[i]] = r->id;
			q->visited[r->links[i]] = 1;
			++q->position;
			f->id_table[r->links[i]]->weight = r->weight - 1;
			return (1);
		}
		++i;
	}
	return (0);
}

/*
** As our current goal is to explore the maximum quantity of paths to find
** the best combined path solution, we initially see if there is a negative flow
** (i.e. a path we can traverse inversely), and if there is we choose that flow.
** If there isn't, we compare the weights between parent and child node, if
** the node has been visited before. If the child node has not been visited,
** we set it's weight (the weight of the parent node + 1, or - 1, depending on
** the direction of the flow) and add it to the queue for investigation.
*/

static int	find_flow(t_queue *q, t_room *r, int prev_flow, t_farm *f)
{
	int		j;

	j = 0;
	if (prev_flow == 0 && find_neg_flow(q, r, f) == 1)
		return (0);
	while (j < r->links_nb)
	{
		if (f->id_table[r->links[j]]->weight != __INT_MAX__)
			check_weights(f->id_table[r->links[j]], r, q, f);
		if (q->visited[r->links[j]] != 1
			&& q->flow[r->id][r->links[j]] != 1)
		{
			q->queue[q->position] = r->links[j];
			q->prev[r->links[j]] = r->id;
			q->visited[r->links[j]] = 1;
			++q->position;
			if (q->flow[r->id][r->links[j]] == 0)
				f->id_table[r->links[j]]->weight = r->weight + 1;
			else
				f->id_table[r->links[j]]->weight = r->weight - 1;
		}
		++j;
	}
	return (0);
}

/*
** Starting at end, we save the flow between a node and it's previous node,
** until we reach start, and have completed the path. As all of our edges
** have a potential value of 1, it is a question of adding or subtracting 1
** depending on the previous flow value between nodes.
*/

static void	save_flow(t_queue *q, t_farm *f)
{
	int		p;
	int		s;

	p = f->end->id;
	while (p != f->start->id)
	{
		s = q->prev[p];
		if (q->flow[p][s] == 0)
		{
			q->flow[p][s] = -1;
			q->flow[s][p] = 1;
		}
		else if (q->flow[p][s] == -1 || q->flow[p][s] == 1)
		{
			q->flow[p][s] = 0;
			q->flow[s][p] = 0;
		}
		p = s;
	}
}

/*
** Starting at ths start node, we explore the nodes in the queue, taking note
** of the flow from the parent to child node. Again, if at the end of the queue
** we have not visited end, we have not found a path and return -1.
*/

static int	optimise_flow(t_farm *f, t_queue *q)
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
		node = q->queue[i];
		if (i > 0)
			prev_flow = q->flow[q->prev[node]][node];
		find_flow(q, f->id_table[node], prev_flow, f);
	}
	if (q->prev[f->end->id] == -1)
		return (-1);
	return (0);
}

/*
** This is an adapted implementation of the edmonds-karp algorithm. We find
** a solution set of paths, adjust the flows and save the flows, and compare
** the new solution set to our previous set, saving the shortest solution
** and freeing the other. If t variable (intially 0), remains 0, this
** signals no solution set was found, and we return -1.
*/

int			edmondskarp(t_queue *q, t_farm *f, t_path **p, int t)
{
	t_path	*new;

	*p = ft_new_path(NULL, 0);
	(*p)->longest = 0;
	set_weights(f);
	while (optimise_flow(f, q) == 0 && (t = 1))
	{
		new = ft_new_path(NULL, 0);
		new->longest = 0;
		save_flow(q, f);
		set_to_n(&q->visited, q->length, 0);
		reset_queue(q, f->start->id, f->end->id);
		save_paths(q, f, &new);
		if (new->len == -1)
			return (-1);
		if ((*p)->longest == 0 || (*p)->longest > new->longest)
		{
			free_path((*p));
			*p = new;
		}
		else
			free_path(new);
		clear_queue(q);
	}
	return ((t == 1) ? 0 : -1);
}
