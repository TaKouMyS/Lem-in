/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/09/01 13:39:50 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** first_line :
** Receive the first line and checks if it's a val ant's number.
** Store this number in the farm's structure.
*/

static int	first_line(t_farm *f, char *line)
{
	int		i;

	i = 0;
	if (line)
	{
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i++]) != 1)
				return (-1);
		}
		f->ant_nb = ft_atoi(line);
	}
	else
		return (-1);
	return (0);
}

/*
** get_input :
** Read the first line on stdin and  send it for checks.
** Launch the functions that gest rooms.
*/

int			get_input(t_farm *f, t_room *r)
{
	char	*line;

	get_next_line(0, &line);
	if (first_line(f, line) != 0 || get_room(r, f, line) != 0)
		return (-1);
	return (0);
}
