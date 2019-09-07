/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:01:30 by amamy             #+#    #+#             */
/*   Updated: 2019/09/07 20:03:06 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

static int	check_stack_cmd(char *line, char *tmp)
{
	if ((ft_strcmp(tmp, "##start") == 0 && ft_strcmp(line, "##end") == 0) \
		|| (ft_strcmp(tmp, "##end") == 0 \
		&& ft_strcmp(line, "##start") == 0))
		return (-1);
	return (0);
}

static int	raise_flag(t_farm *f, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		f->flags |= START;
	else if (ft_strcmp(line, "##end") == 0)
		f->flags |= END;
	return (0);
}

/*
** check_comment :
** Receive a comment.
** If it is a command, get next line and if correct, raises matching flag.
*/

char	*check_comment(char *line, char *next_line, t_farm *f)
{
	if (line[1] != '#' && (next_line = room_check_syntax(next_line, f)))
		return (next_line);
	else if (line[1] == '#')
	{
		if ((ft_strcmp(line, "##start") == 0 && !(f->flags & START)) \
			|| (ft_strcmp(line, "##end") == 0 && !(f->flags & END)))
		{
			if ((!(next_line)) || check_stack_cmd(next_line, line) != 0		\
				|| (next_line = room_check_syntax(next_line, f)) == NULL	\
				|| raise_flag(f, line) != 0)
			{
				ft_memdel((void*)&line);
				return (NULL);
			}
		}
		else if ((next_line = room_check_syntax(next_line, f)) != 0)
			return (next_line);
	}
	ft_memdel((void*)&line);
	return (next_line);
}
