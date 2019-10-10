/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:37:07 by amamy             #+#    #+#             */
/*   Updated: 2019/10/05 03:20:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** ==================== init_links ====================
** Create a squared matrice the size matching rooms number.
*/

static int	init_links(t_farm *f, char **room)
{
	int	i;

	i = 0;
	room[1] = NULL;
	room[2] = NULL;
	if (!(f->links = ft_memalloc(sizeof(int*) * (f->room_nb + 1))))
		return (-1);
	while (i < f->room_nb + 1)
		if (!(f->links[i++] = ft_memalloc(sizeof(int) * (f->room_nb + 1))))
			return (-1);
	return (0);
}

/*
** ==================== save_links ====================
** Save links into link's matrice.
*/

static void	save_links(t_farm *f, t_room **ids)
{
	f->links[ids[0]->id][ids[1]->id] = 1;
	f->links[ids[1]->id][ids[0]->id] = 1;
}

/*
** ==================== room_exist ====================
** Check if the room has been stored previously.
*/

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

/*
** ==================== get_rooms_name ====================
** Mode 1 : get the name of the first room
** Mode 2 : get the name of the second room
** Return the name.
*/

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

/*
** ==================== get_links ====================
** Read stdin, get rooms name, check if they exist and if they do,
** save the link.
*/

int			get_links(t_farm *f)
{
	int		ret;
	char	*line;
	char	*room[3]; //changed from 2 to 3 stack buffer overflow
	t_room	*ids[2];

	if (init_links(f, room) == -1)
		return (-1);
	ret = 1;
	if (f->line)
			line = f->line;
	else
		ret = gnl_store(0, &line, f, GET_ANTS_LINKS);
	while (ret > 0)
	{
		if ((!(line)) || ((room[0] = get_rooms_name(line, 1)) == NULL)	\
			|| (room_exist(f, room[0], ids, 0) != 1)						\
			|| ((room[1] = get_rooms_name(line, 2)) == NULL)			\
			|| (room_exist(f, room[1], ids, 1) != 1))
			{
			ft_printf("get_links");
			return (free_links(line, room, -1));
			}
		save_links(f, ids);
		free_links(line, room, 0);
		ret = gnl_store(0, &line, f, GET_ANTS_LINKS);
	}
	
	// links printing ; debug
	
	ft_printf("links :\n");
	int j = 0;
	int i = 0;
	printf("room nb = %d\n", f->room_nb);

	while (i < f->room_nb)
	{
		ft_printf("%d ", i);
		++i;
	}
	ft_printf("\n................\n");
	i = 0;
	while (i < f->room_nb)
	{
		j = 0;
		while (j < f->room_nb)
		{
			ft_printf("%d ", f->links[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}

	return ((ret >= 0) ? 0 : -1);
}
