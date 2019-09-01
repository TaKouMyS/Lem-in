/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:01:30 by amamy             #+#    #+#             */
/*   Updated: 2019/09/01 21:06:28 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** check_comment :
** Receive a comment.
** If it is a command, get next line and if correct, raises matching flag.
*/

char	*check_comment(char *line, t_farm *f)
{
	char *tmp;

	if (line[1] != '#')
		return (line);
	else if (line[1] == '#')
	{
		tmp = ft_strdup(line);
		if ((ft_strcmp(line, "##start") == 0 && f->start == NULL) \
			|| (ft_strcmp(line, "##end") == 0 && f->end == NULL))
			{
				ft_memdel((void*)&line);
				get_next_line(0, &line);
				if ((!(line)) || (line = room_check_syntax(line, f)) == NULL)
				{
					ft_memdel((void*)&tmp);
					return (NULL);
				}
				if (ft_strcmp(tmp, "##start\n") == 0)
					f->flags |= START;
				else if (ft_strcmp(tmp, "##end\n") == 0)
					f->flags |= END;
			}
	}
	ft_memdel((void*)&tmp);
	return (line);
}
