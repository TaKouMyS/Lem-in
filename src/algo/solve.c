/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:29:51 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/28 02:15:08 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

//we won't need this later I think, it's just for debugging. 
void	print_map(int **map, int length)
{
	int i;
	int j;

	i = 0;
	printf("\n...........................\n");
	while (i < length)
	{
		j = 0;
		printf("%d  |", i);
		while (j < length)
		{
			printf("%d ", map[i][j]);
			++j;
		}
		putchar('\n');
		++i;
	}
	printf("...........................\n");
}

//same for debugging
void	print_paths(t_path *paths, t_farm *f)
{
	t_path *tracker;
	int i;
	size_t j;

	i = 0;
	tracker = paths;
	printf("max = %d\n", paths->max);
	while (i < paths->max)
	{
		j = 0;
		printf("ant = %d len = %d. ",  paths->division[i], tracker->len);
	//	printf("i = %d, division = %d\n", i, paths->division[i]);
		if (tracker->path != NULL)
		{
			while (tracker->path[j] != f->end->id)
			{
				ft_printf("%s ", f->id_table[tracker->path[j]]->name);
				++j;
			}
			ft_printf("%s\n", f->id_table[tracker->path[j]]->name);
		}
		tracker = tracker->next;
		++i;
	}
}

int		solve(t_farm *f, int length, int start)
{
	t_queue q;
	t_path *path_list;

	if (initialise_queue(&q, length, start) < 0)
	{
		ft_printf("MALLOC ERROR\n");
		free_queue(&q);
		return (-1);
	}
	if (edmondskarp(&q, f, &path_list) == -1)
	{
		ft_printf("NO PATH FOUND\n");
		free_queue(&q);
		return (-1);
	}
//	print_paths(path_list, f);
	send_ants(f, path_list, f->ant_nb);
	free_path(path_list);
	free_queue(&q);
	return (0);
}
