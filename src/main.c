/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/11/07 16:40:28 by amamy            ###   ########.fr       */
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
static int	parser(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
	{
		while(++i < argc)
		{
			if (ft_strcmp(argv[i], "-l") == 0)
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_farm	*f;
	t_room	*r;
	int flag;

	if ((flag = parser(argc, argv)) == -1)
		return (usage());
	if (!(f = ft_memalloc(sizeof(t_farm))))
		return (-1);
	if (!(r = ft_memalloc(sizeof(t_room))))
		return (ft_free_lemin(f, r));
	f->first_room = r;
	if (get_input(f, r) == -1)
		return (ft_free_lemin(f, r));
	write_input(f);
	ft_putchar('\n');
	solve(f, flag);
	ft_free_lemin(f, r);
	return (0);
}