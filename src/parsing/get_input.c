/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/10/28 02:18:12 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

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

static int	usage(char *line, int mode)
{
	ft_putstr("\n\nUsage :\nLem-in reads standard entry.\n\n");
	ft_putstr("1 - First line is the ant's number.\n\n");
	ft_putstr("2 - Then list rooms - syntax :\nname Y X\n");
	ft_putstr("(Where Y and X are number meanings coordonates).\n");
	ft_putstr("The programm needs to know the starting and ending rooms.\n");
	ft_putstr("You can specify them with ##start and ##end commands.\n");
	ft_putstr("Those commande are written on one line, ");
	ft_putstr("the next line will be start or end.\n\n");
	ft_putstr("3 - list of links - syntax :\n");
	ft_putstr("Room1-Room2\n");
	ft_putstr("(Means Room1 and Room2 are linked).\n\n");
	ft_putstr("Example :\n\n");
	ft_putstr("13\n");
	ft_putstr("##start\nStarting_room 0 0\n##end\nEnding_room 1 1\n");
	ft_putstr("Room1 2 2\nRoom2 3 3\nRoom3 4 4\n");
	ft_putstr("Starting_room-Room1\n");
	ft_putstr("Room1-Room2\n");
	ft_putstr("Room2-Room3\n");
	ft_putstr("Room3-Ending_room\n\n\n");
	if (mode == 1)
		ft_memdel((void*)&line);
	return (-1);
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
	long	tmp;

	i = 0;
	line = NULL;
 	if ((ret = gnl_store(0, &line, f, GET_ANTS_LINKS) >= 0) && line)
	{
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i++]) != 1)
				return (usage(line, 1));
		}
		if ((tmp = ft_atoi_long(line)) > __INT_MAX__)
			return (usage(line, 1));
		f->ant_nb = tmp;
	}
	else
		return (usage(line, 0));
	ft_memdel((void*)&line);
	return (0);
}

int			create_link_list(t_farm *f)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < f->room_nb)
	{
		if (!(f->id_table[i]->links = ft_memalloc(sizeof(int) * \
		(f->id_table[i]->links_nb + 1))))
			return (-1);
		while (j < f->room_nb)
		{
			if (f->links[i][j] == 1)
				f->id_table[i]->links[k++] = j;
			j++;
		}
		k = 0;
		j = 0;
		i++;
	}
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
	if (get_quantity_ants(f) != 0 || get_room(r, f) != 0 \
		|| creates_table(r, f) != 0 || get_links(f) != 0 \
		|| create_link_list(f) != 0)
			return (-1);
	return (0);
}
