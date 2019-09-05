/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:30:43 by amamy             #+#    #+#             */
/*   Updated: 2019/09/05 01:42:11 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** ft_free :
** free all stuff.
** Receive a pointeur to the first link of the chain r.
*/

void ft_free_lemin(t_farm *f, t_room *r)
{
	int		i;

	(void)r;
	i = 0;
	while (i < f->room_nb)
	{
		ft_memdel((void*)&f->id_table[i]->name);
		ft_memdel((void*)&f->links[i]);
		ft_memdel((void*)&f->id_table[i++]);
	}
	ft_memdel((void*)&f->id_table);
	ft_memdel((void*)&f->links[i]);
	ft_memdel((void*)&f->links);
	ft_memdel((void*)&f);
}
