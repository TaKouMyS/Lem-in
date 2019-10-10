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

#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
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
void	print_paths(int **paths, t_farm *f, int max_paths)
{
	int i;
	int j;

	i = 0;
	while (i < max_paths)
	{
		j = 0;
		while (paths[i][j] != f->end->id)
		{
			printf("%s ", f->id_table[paths[i][j]]->name);
			++j;
		}
		printf("%s ", f->id_table[paths[i][j]]->name);
		putchar('\n');
		++i;
	}
}

int		solve(t_farm *f, int length, int start)
{
	t_queue q;
	int		**paths;

	if (initialise_queue(&q, length, start) < 0)
<<<<<<< HEAD
        return (-1);
    f->max_paths = edmondskarp(&q, f, &paths);
//	printf("f->max, %d\n", f->max_paths);
	print_paths(paths, f, f->max_paths);
=======
	{
		ft_printf("MALLOC ERROR\n");
		free_queue(&q);
		return (-1);
	}
	f->max_paths = edmondskarp(&q, f, &paths);
	if (f->max_paths == -1)
	{
		ft_printf("NO PATH FOUND\n");
		free_queue(&q);
		return (-1);
	}
//	printf("f->max = %d\n", f->max_paths);
//	print_paths(paths, f, f->max_paths);
>>>>>>> fcahill
	send_ants(f, paths, f->max_paths, f->ant_nb);
	return (0);
}
