/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:37:07 by amamy             #+#    #+#             */
/*   Updated: 2019/09/04 01:54:50 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"
#include <stdio.h>

static int	save_link(t_room *r, t_room **ids)
{
	t_room	*tmp;

	tmp = ids[0];
}

static int	room_exist(t_farm *f, char *room, t_room **ids, int mode)
{
	int	i;

	i = 0;
	while (i < r->room_nb)
	{
		if (ft_strcmp(room, id_table[i++]->name) == 0)
		{
			ids[mode] = id_table[i - 1];
			return (1);
		}
	}
	return (0);
}

static char	*get_rooms_name(char *dash, int mode)
{
	(void)dash;
	(void)mode;
	return ("CHAAATTTE");
}

int	get_links(t_farm *f, t_room *r)
{
	char	*line;
	char	*dash;
	char	*room[2];
	int		ret;
	t_room	**ids;

	(void)r;
	if (!(ids = ft_memalloc(sizeof(*t_room) * 2)))
		return (-1);
	ret = get_next_line(0, &line);
	while (ret > 0 || (dash = ft_strchr(line, '-')) != NULL)
		if (((room[0] = get_rooms_name(dash, 1)) == NULL) 		\
			|| (room_exist(f, room[0], 0) != 1)					\
			|| ((room[1] = get_rooms_name(dash, 2)) == NULL)	\
			|| (room_exist(f, room[1], 1) != 1))
			return (-1);



	return (0);
}
