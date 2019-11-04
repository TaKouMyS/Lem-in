/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:29:51 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/29 02:48:51 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		solve(t_farm *f, int length, int start)
{
	t_queue	q;
	t_path	*path_list;

	if (initialise_queue(&q, f) < 0)
	{
		ft_printf("MALLOC ERROR\n");
		free_queue(&q);
		return (-1);
	}
	if (edmondskarp(&q, f, &path_list, 0) == -1)
	{
		ft_printf("NO PATH FOUND\n");
		free_queue(&q);
		free_path(path_list);
		return (-1);
	}
	send_ants(f, path_list, f->ant_nb, 0);
	free_path(path_list);
	free_queue(&q);
	return (0);
}
