/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:29:51 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/10 17:29:56 by fcahill          ###   ########.fr       */
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
void	print_paths(t_list *paths, t_farm *f)
{
	t_list *tracker;
	int i;
	size_t j;

	i = 0;
	tracker = paths;
	while (tracker->content != NULL)
	{
		j = 0;
		while( tracker != NULL && ((int *)tracker->content)[j] != f->end->id)
		{
			ft_printf("%d ", ((int *)tracker->content)[j]);
			++j;
		}
		ft_printf("%d\n", ((int *)tracker->content)[j]);
		tracker = tracker->next;
		++i;
	}
}

int		solve(t_farm *f, int length, int start)
{
	t_queue q;
	int		**paths;
	t_list *path_list;

	if (initialise_queue(&q, length, start) < 0)
	{
		ft_printf("MALLOC ERROR\n");
		free_queue(&q);
		return (-1);
	}
	f->max_paths = edmondskarp(&q, f, &path_list);
	if (f->max_paths == -1)
	{
		ft_printf("NO PATH FOUND\n");
		free_queue(&q);
		return (-1);
	}
	verify_paths(f, &q, path_list);
//	printf("f->max = %d\n", f->max_paths);
//	print_paths(path_list, f);
	send_ants(f, path_list, f->max_paths, f->ant_nb);
	return (0);
}
