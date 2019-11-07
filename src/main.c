/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/11/07 16:08:20 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	write_input(t_farm *f)
{
	f->input = f->input_start;
	while (f->input->line)
	{
		ft_putstr(f->input->line);
		ft_putstr("\n");
		f->input = f->input->next;
	}
}

int			main(void)
{
	t_farm	*f;
	t_room	*r;

	if (!(f = ft_memalloc(sizeof(t_farm))))
		return (-1);
	if (!(r = ft_memalloc(sizeof(t_room))))
		return (ft_free_lemin(f, r));
	f->first_room = r;
	if (get_input(f, r) == -1)
		return (ft_free_lemin(f, r));
	write_input(f);
	ft_putchar('\n');
	solve(f, f->room_nb, f->start->id);
	ft_free_lemin(f, r);
	return (0);
}
