/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:01:30 by amamy             #+#    #+#             */
/*   Updated: 2019/10/10 02:19:10 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

int		is_comment(t_farm *f, char *line)
{
	if (ft_strcmp(line, "##start") == 0) 
	{
		if (f->start != NULL)
			return (-1);
		else
		{
			f->flags |= START;
			f->flags &= ~END;
		}
	}
	else if (ft_strcmp(line, "##end") == 0) 
	{
		if (f->end != NULL)
			return (-1);
		else
		{
			f->flags |= END;
			f->flags &= ~START;
		}
	}
	return (0);
}


int			create_link_list(t_farm *f)
{
	int		i;
	int		j;
	int		k;
	t_room*	room;

	i = 0;
	j = 0;
	k = 0;
	room = f->id_table[i];
	while (i < f->room_nb)
	{
		if (!(room->links = ft_memalloc(sizeof(int) * (room->links_nb + 1))))
			return (-1);
		while (j < f->room_nb)
		{
			if (f->links[i][j] == 1)
				room->links[k++] = j++;
		}
	}
	return (0);
}