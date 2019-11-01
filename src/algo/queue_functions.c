/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:18:03 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/29 02:01:35 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		set_to_n(int **set, int length, int n)
{
	int i;

	i = -1;
	while (++i < length)
		set[0][i] = n;
	return (0);
}

int		initialise_queue(t_queue *q, int length, int start)
{
	int i;

	i = 0;
	q->length = length;
	q->queue = NULL;
	q->prev = NULL;
	q->flow = NULL;
	q->visited = NULL;
	if (!(q->queue = ft_memalloc(sizeof(int) * length)))
		return (-1);
	if (!(q->prev = ft_memalloc(sizeof(int) * length)))
		return (-1);
	if (!(q->visited = ft_memalloc(sizeof(int) * length)))
		return (-1);
	if (!(q->flow = ft_memalloc(sizeof(int *) * q->length)))
		return (-1);
	while (i < q->length)
	{
		if (!(q->flow[i++] = ft_memalloc(sizeof(int) * q->length)))
			return (-1);
	}
	set_to_n(&q->queue, length, -1);
	set_to_n(&q->prev, length, -1);
	reset_queue(q, start, -1);
	return (0);
}

void	reset_queue(t_queue *q, int start, int end)
{
	q->queue[0] = start;
	q->visited[start] = 1;
	q->position = 1;
	if (end >= 0)
		q->visited[end] = 0;
}

void	clear_queue(t_queue *q)
{
	set_to_n(&q->prev, q->length, -1);
	set_to_n(&q->queue, q->length, -1);
}

void	free_queue(t_queue *q)
{
	int	i;

	i = 0;
	while (i < q->length)
	{
		ft_memdel((void*)&q->flow[i]);
		++i;
	}
	if (q->flow != NULL)
		free(q->flow);
	if (q->prev != NULL)
		free(q->prev);
	if (q->queue != NULL)
		free(q->queue);
	if (q->visited != NULL)
		free(q->visited);
}
