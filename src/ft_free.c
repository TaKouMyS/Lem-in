/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:30:43 by amamy             #+#    #+#             */
/*   Updated: 2019/10/29 01:43:37 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** ==================== free_links ====================
** Used in get_links to free temporary data if error detected.
** Free stored ids and line.
*/

int		ft_delete_line(char *line)
{
	ft_memdel((void *)&line);
	return (-1);
}

int		free_links(char *line, char **rooms, int ret)
{
	ft_memdel((void*)&rooms[0]);
	ft_memdel((void*)&rooms[1]);
	ft_memdel((void*)&line);
	return (ret);
}

void	ft_free_input(t_input *input, t_input *start)
{
	t_input *tmp;

	input = start;
	while (input->line)
	{
		tmp = input;
		ft_memdel((void*)&input->line);
		input = input->next;
		ft_memdel((void*)&tmp);
	}
	ft_memdel((void*)&input);
}

/*
** ft_free :
** free all stuff.
** Receive a pointeur to the first link of the chain r.
*/

int		ft_free_lemin(t_farm *f, t_room *r)
{
	int		i;
	t_room	*tmp;

	i = 0;
	while (i < f->room_nb)
		ft_memdel((void*)&f->links[i++]);
	while (r)
	{
		tmp = r->next;
		ft_memdel((void*)&r->name);
		ft_memdel((void*)&r->links);
		ft_memdel((void*)&r);
		r = tmp;
	}
	ft_memdel((void*)&f->id_table);
	ft_memdel((void*)&f->links[i]);
	ft_memdel((void*)&f->links);
	ft_free_input(f->input, f->input_start);
	ft_memdel((void*)&f);
	return (-1);
}

int		error_free_line(char *line)
{
	ft_memdel((void*)&line);
	return (-1);
}
