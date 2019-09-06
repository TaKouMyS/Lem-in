/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:37:07 by amamy             #+#    #+#             */
/*   Updated: 2019/09/06 04:48:22 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

static void free_current(char *line, char **rooms)
{
	ft_memdel((void*)&rooms[0]);
	ft_memdel((void*)&rooms[1]);
	ft_memdel((void*)&line);
}

static int	init_links(t_farm *f)
{
	int	i;

	i = 0;
	if (!(f->links = ft_memalloc(sizeof(int*) * (f->room_nb + 1))))
		return (-1);
	while (i < f->room_nb + 1)
		if (!(f->links[i++] = ft_memalloc(sizeof(int) * (f->room_nb + 1))))
			return (-1);
	return (0);
}


static void	save_links(t_farm *f, t_room **ids)
{
	f->links[ids[0]->id][ids[1]->id] = 1;
	f->links[ids[1]->id][ids[0]->id] = 1;
}

static int	room_exist(t_farm *f, char *room, t_room **ids, int mode)
{
	int	i;

	i = 0;
	while (i < f->room_nb)
	{
		if (ft_strcmp(room, f->id_table[i++]->name) == 0)
		{
			ids[mode] = f->id_table[i - 1];
			return (1);
		}
	}
	return (0);
}

static char	*get_rooms_name(char *line, int mode)
{
	char	*room;
	int		room_length;

	room_length = 0;
	if (mode == 1)
		while (line[room_length] != '-' && line[room_length] != '\0')
			room_length++;
	else if (mode == 2)
	{
		line = ft_strchr(line, '-') + 1;
		while (line[room_length] != '\0')
			room_length++;
	}
	room = ft_strndup(line, room_length);
	return (room);
}

int	get_links(t_farm *f)
{
	int		ret;
	char	*line;
	char	*room[2];
	t_room	*ids[2];

	if (init_links(f) == -1)
		return (-1);
	ret = 1;
	if (f->line)
		line = f->line;
	else
		ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if ((!(line)) || ((room[0] = get_rooms_name(line, 1)) == NULL) 	\
			|| (room_exist(f, room[0], ids, 0) != 1)					\
			|| ((room[1] = get_rooms_name(line, 2)) == NULL)		\
			|| (room_exist(f, room[1], ids, 1) != 1))
			{
				free_current(line, room);
				return (-1);
			}
		save_links(f, ids);
		free_current(line, room);
		ret = get_next_line(0, &line);
	}

	// links printing ; debug
	// ft_printf("links :\n");
	// int j = 0;
	// int i = 0;
	// while (i < f->room_nb + 1)
	// {
	// 	if (i < f->room_nb)
	// 		while (j < f->room_nb)
	// 			ft_putnbr(f->links[i][j++]);
	// 	i++;
	// 	j = 0;
	// 	ft_printf("\n");
	// }

	return (0);
}
