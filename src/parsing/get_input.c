/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/09/02 13:39:14 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** first_line :
** Read the first line on stdin and checks if it's a valid ant's number.
** Store this number in the farm's structure.
*/

static int	first_line(t_farm *f)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if ((get_next_line(0, &line) > 0) && line)
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
	ft_memdel((void*)&line);
	return (0);
}

/*
** get_input :
** Launch the functions that get and check input.
*/

int			get_input(t_farm *f, t_room *r)
{

	if (first_line(f) != 0 || get_room(r, f) != 0)
		return (-1);
	return (0);
}
