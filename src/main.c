/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/09/08 02:04:33 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

int	main(void)
{
	t_farm	*f;
	t_room	*r;

	if (!(f = ft_memalloc(sizeof(t_farm))))
		return (-1);
	if (!(r = ft_memalloc(sizeof(t_room))))
	{
		ft_free_lemin(f, r);
		return (-1);
	}
	if (get_input(f, r) == -1)
	{
		ft_printf("ERROR\n");
		ft_free_lemin(f, r);
		return (-1);
	}
	ft_printf("start room's name :%s\n id : %d\n", f->start->name, f->start->id);
	ft_printf("end room's name :%s\n id : %d\n", f->end->name, f->end->id);
	ft_free_lemin(f, r);
	ft_putstr("No errors!\n");
	return (0);
}
