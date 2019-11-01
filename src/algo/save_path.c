/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:32:10 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/29 02:45:52 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	count_steps(t_queue *q, int start, int end)
{
	int		steps;

	steps = 0;
	while (end != start)
	{
		end = q->prev[end];
		++steps;
	}
	return (steps);
}

static int		*rev_path(t_farm *f, t_queue *q)
{
	int		*rev_path;
	int		steps;
	int		i;
	int		pos;

	i = 0;
	pos = f->end->id;
	steps = count_steps(q, f->start->id, f->end->id);
	if (!(rev_path = ft_memalloc((sizeof(int)) * (steps + 1))))
		return (NULL);
	rev_path[steps] = pos;
	while (i <= steps)
	{
		rev_path[steps - i] = pos;
		pos = q->prev[pos];
		++i;
	}
	return (rev_path);
}

static void		mark_path(t_farm *f, t_queue *q)
{
	int		path;
	int		j;

	j = 0;
	path = q->prev[f->end->id];
	while (path != f->start->id)
	{
		q->visited[path] = 2;
		path = q->prev[path];
	}
	while (j < q->length)
	{
		q->prev[j] = -1;
		q->queue[j] = -1;
		if (q->visited[j] == 1)
			q->visited[j] = 0;
		++j;
	}
}

static t_path	**path_error(t_path **path)
{
	(*path)->len = -1;
	return (path);
}

t_path			**save_paths(t_queue *q, t_farm *f, t_path **path_list)
{
	int		*path;
	size_t	steps;
	t_path	*new;
	int		i;

	i = 0;
	while (bfs(f, q) == 0)
	{
		if (!(path = rev_path(f, q)))
			return (path_error(path_list));
		steps = count_steps(q, f->start->id, f->end->id);
		mark_path(f, q);
		if (!(new = ft_new_path(path, steps + 1)))
			return (path_error(path_list));
		ft_memdel((void*)&path);
		ft_add_path(*path_list, new);
		++i;
	}
	path_list = set_path(path_list, i, f);
	return (path_list);
}
