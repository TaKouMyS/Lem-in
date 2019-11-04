/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_functions_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 23:51:08 by fcahill           #+#    #+#             */
/*   Updated: 2019/11/01 23:51:10 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	send_new_ant(t_farm *f, int *p, int mov, int *fin)
{
	int		i;

	i = 0;
	if (mov <= f->ant_nb && f->id_table[p[1]]->empty == -1)
	{
		++mov;
		f->id_table[p[1]]->empty = mov;
		if (p[1] == f->end->id)
			++fin[0];
		ft_printf("L%d-%s", mov, f->id_table[p[1]]->name);
		++i;
	}
	return (mov);
}

int	check_print_space(int x)
{
	if (x != 0)
		ft_putchar(' ');
	x = 1;
	return (x);
}

int	*get_path_lengths(t_farm *f, t_path *paths, int *total)
{
	int		i;
	int		*steps;
	t_path	*path;

	i = 0;
	path = paths;
	if (!(steps = (int *)ft_memalloc(sizeof(int) * f->max_paths)))
		return (NULL);
	while (i < f->max_paths)
	{
		steps[i] = path->len;
		total[0] = total[0] + steps[i];
		++i;
		path = path->next;
	}
	return (steps);
}
