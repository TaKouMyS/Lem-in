/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:30:43 by amamy             #+#    #+#             */
/*   Updated: 2019/09/03 19:10:08 by amamy            ###   ########.fr       */
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
	t_room	*tmp_r;

	while (r->next)
	{
		tmp_r = r->next;
		ft_memdel((void*)&r->name);
		ft_memdel((void*)&r->links);
		ft_memdel((void*)&r);
		r = tmp_r;
	}
	ft_memdel((void*)&r->name);
	ft_memdel((void*)&r->links);
	ft_memdel((void*)&r);
	ft_memdel((void*)&f->id_table);
	ft_memdel((void*)&f);
}
