/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:32:23 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/29 02:19:59 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_last_ant(t_farm *f, int *path)
{
	int	j;

	j = 0;
	while (path[j] != f->end->id)
		++j;
	while (j != 0 && f->id_table[path[j]]->empty == -1)
		--j;
	return (j + 1);
}

static int	reach_finish(int *path, t_farm *f, int j, int *x)
{
	if (path[j] == f->end->id)
	{
		x[0] = check_print_space(x[0]);
		ft_printf("L%d-%s", f->id_table[path[j - 1]]->empty,
			f->id_table[path[j]]->name);
		if (j >= 1)
			f->id_table[path[j - 1]]->empty = -1;
		return (1);
	}
	return (0);
}

static void	move_the_ant(int *path, t_farm *f, int j, int *x)
{
	if (f->id_table[path[j]]->empty == -1 \
		&& j > 1 && f->id_table[path[j - 1]]->empty != -1)
	{
		x[0] = check_print_space(x[0]);
		f->id_table[path[j]]->empty = f->id_table[path[j - 1]]->empty;
		f->id_table[path[j - 1]]->empty = -1;
		ft_printf("L%d-%s", f->id_table[path[j]]->empty,
			f->id_table[path[j]]->name);
	}
}

static void	move_ants_on_path(t_farm *f, int *path, int *finished_ants, int *x)
{
	int		j;

	j = find_last_ant(f, path);
	while (j != 0)
	{
		if ((reach_finish(path, f, j, x)) == 1)
			++finished_ants[0];
		else if (finished_ants[0] < f->ant_nb)
			move_the_ant(path, f, j, x);
		--j;
	}
}

int			send_ants(t_farm *f, t_path *paths, int mv_ants, int x)
{
	int		finished_ants;
	int		i;
	t_path	*path;

	mv_ants = 0;
	finished_ants = 0;
	while (finished_ants < f->ant_nb)
	{
		i = -1;
		path = paths;
		x = 0;
		while (++i < paths->max)
		{
			move_ants_on_path(f, path->path, &finished_ants, &x);
			if (mv_ants < f->ant_nb && paths->division[i] > 0)
			{
				x = check_print_space(x);
				mv_ants = send_new_ant(f, path->path, mv_ants, &finished_ants);
				--paths->division[i];
			}
			path = path->next;
		}
		ft_putchar('\n');
	}
	return (0);
}
