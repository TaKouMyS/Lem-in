/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/10/08 23:41:36 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"
#include <stdio.h>


/*
** ==================== is_start_end_linked ====================
** When input is done, check if startand end have links, if not, return error.
*/

//not used, to be remove
// static int	is_start_end_linked(t_farm *f)
// {
// 	int	i;
// 	int	start;
// 	int	end;

// 	i = 0;
// 	start = 0;
// 	end = 0;
// 	while (i < f->room_nb)
// 	{
// 		if (f->links[f->start->id][i] == 1)
// 			start = 1;
// 		if (f->links[f->end->id][i++] == 1)
// 			end = 1;
// 		if (start == 1 && end == 1)
// 			return (0);
// 	}
// 	return (-1);
// }

/*
** creates_table :
** According to the id assigned in init_room, creates a tables matching ids and
** pointers to the room assigned.
*/

static int	creates_table(t_room *r, t_farm *f)
{
	while (r->next)
		r = r->next;
	f->room_nb = r->id + 1;
	if (!(f->id_table = ft_memalloc(sizeof(t_room*) * (f->room_nb + 1))))
		return (-1);
	while (r->prev)
	{
		f->id_table[r->id] = r;
		r = r->prev;
	}
	f->id_table[r->id] = r;
	return (0);
}

/*
** get_quantity_ants :
** Read the first line on stdin and checks if it's a valid ant's number.
** Store this number in the farm's structure.
*/

static int	get_quantity_ants(t_farm *f)
{
	int		i;
	char	*line;
	int		ret;

	i = 0;
	line = NULL;
	if ((ret = gnl_store(0, &line, f, GET_ANTS_LINKS) >= 0) && line)
	{
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i++]) != 1)
			{
				ft_printf("ants\n");
				ft_memdel((void*)&line);
				return (-1);
			}
		}
		f->ant_nb = ft_atoi(line);
	}
	else
		return (-1);
	ft_memdel((void*)&line);
	return (0);
}

/*
** get_input :
** Launch the functions that get and check input.
*/

int			get_input(t_farm *f, t_room *r)
{
	t_input	*start;

	if (!(start = ft_memalloc(sizeof(t_input))))
		return (-1);
	f->input = start;
	f->input_start = start;
	ft_printf("%s\n", "get_input");
	if (get_quantity_ants(f) != 0 || get_room(r, f) != 0 \
		|| creates_table(r, f) != 0 || get_links(f) != 0)  \
		// || is_start_end_linked(f) != 0)
			return (-1);
	return (0);
}