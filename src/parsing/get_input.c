/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/08/31 22:41:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** first_line :
** Read the first line on stdin and checks if it's a val ant's number.
** Store this number in the farm's structure.
*/

static int	first_line(t_farm *f)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
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

int			get_input(t_farm *f, t_room *r)
{
	if (first_line(f) != 0 || get_room(r, f) != 0)
		return (-1);
	return (0);
}
