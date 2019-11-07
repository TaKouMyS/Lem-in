/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:29:51 by fcahill           #+#    #+#             */
/*   Updated: 2019/11/07 21:04:41 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print the number of lines printed, if -l flag is present
*/

static void	print_count(int i)
{
	ft_printf("%d line", i);
	if (i != 1)
		ft_putchar('s');
	ft_putchar('\n');
}

/*
** We intialise our queueing system. If there is a malloc error, we free
** any allocated areas and return -1. We then run our edmonds karp function
** to find the optimal solution set. Should we not find a path, we print an
** error message, free the queue the allocated head of the path list, and
** return -1. Finally, if the previous two steps were successful, we send
** our ants down the paths, printing our moves to the stdout. We then free
** the queue and the solution set.
*/

int			solve(t_farm *f, int flag)
{
	t_queue	q;
	t_path	*path_list;
	int		i;

	if (initialise_queue(&q, f) < 0)
	{
		ft_printf("ERROR\n");
		free_queue(&q);
		return (-1);
	}
	if (edmondskarp(&q, f, &path_list, 0) == -1)
	{
		ft_printf("ERROR\n");
		free_queue(&q);
		free_path(path_list);
		return (-1);
	}
	i = send_ants(f, path_list, f->ant_nb, 0);
	free_path(path_list);
	free_queue(&q);
	if (flag == 1)
		print_count(i);
	return (0);
}
