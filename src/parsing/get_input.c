/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/10/29 01:33:26 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** creates_table :
** According to the id assigned in init_room, creates a tables matching ids and
** pointers to the room assigned.
*/

static int	creates_table(t_room *r, t_farm *f)
{
	if (f->start == NULL || f->end == NULL)
	{
		ft_memdel((void*)&f->line);
		return (-1);
	}
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

static void	usage(void)
{
	ft_printf("INPUT ERROR\n");
	ft_putstr("\n\nUsage :\nLem-in reads from the standard input.\n\n");
	ft_putstr("1 - The 1st line is an int between 1 & INT_MAX indicating ");
	ft_putstr("ant quantity.\n\n2 - Below this we list the rooms \n\t\t- ");
	ft_putstr("syntax : name Y X (Y and X represent coordinates).\n\n");
	ft_putstr("3. The program needs to know the starting and ending rooms.");
	ft_putstr(" You can specify them with the ##start and ##end commands.\n");
	ft_putstr("\tEach command is written on a single line ");
	ft_putstr("the line immediately after it will be start or end.\n\n");
	ft_putstr("4 - list of links \n\t\t- syntax : ");
	ft_putstr("Room1-Room2 ");
	ft_putstr("(Meaning Room1 and Room2 are linked).\n\n");
	ft_putstr("5 - Input must end with a single \\n.\n\n");
	ft_putstr("Example :\n\n");
	ft_putstr("13\n");
	ft_putstr("##start\nStarting_room 0 0\n##end\nEnding_room 1 1\n");
	ft_putstr("Room1 2 2\nRoom2 3 3\nRoom3 4 4\n");
	ft_putstr("Starting_room-Room1\n");
	ft_putstr("Room1-Room2\n");
	ft_putstr("Room2-Room3\n");
	ft_putstr("Room3-Ending_room\n\n");
}

/*
** get_quantity_ants :
** Read the first line on stdin and checks if it's a valid ant's number.
** Store this number in the farm's structure.
*/

static int	get_quantity_ants(t_farm *f)
{
	int			i;
	char		*line;
	int			ret;
	long long	t;

	i = 0;
	line = NULL;
	if ((ret = gnl_store(0, &line, f, GET_ANTS_LINKS) >= 0) && line)
	{
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i++]) != 1)
			{
				ft_memdel((void*)&line);
				return (-1);
			}
		}
		if ((t = ft_long_atoi(line)) == 0 || t > __INT_MAX__ || t < __INT_MIN__)
			return (-1);
		f->ant_nb = t;
	}
	else
		return (-1);
	ft_memdel((void*)&line);
	return (0);
}

int			create_link_list(t_farm *f)
{
	int			i;
	int			j;
	int			k;

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
	t_input		*start;

	if (!(start = ft_memalloc(sizeof(t_input))))
		return (-1);
	f->input = start;
	f->input_start = start;
	if (get_quantity_ants(f) != 0 || get_room(r, f) != 0 \
		|| creates_table(r, f) != 0 || get_links(f) != 0 \
		|| create_link_list(f) != 0)
	{
		usage();
		return (-1);
	}
	return (0);
}
