/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:01:30 by amamy             #+#    #+#             */
/*   Updated: 2019/10/04 07:10:07 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** ==================== check_stack_cmd ====================
** If ##start follows ##end or the other way arround, return error.
*/

static int	check_stack_cmd(char *line, char *tmp)
{
	if ((ft_strcmp(tmp, "##start") == 0 && ft_strcmp(line, "##end") == 0) \
		|| (ft_strcmp(tmp, "##end") == 0 \
		&& ft_strcmp(line, "##start") == 0))
		return (-1);
	return (0);
}

/*
** ==================== raise_flag ====================
** If line equal ##start or ##end, raise mathcing flag.
*/

static void	raise_flag(t_farm *f, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		f->flags |= START;
	else if (ft_strcmp(line, "##end") == 0)
		f->flags |= END;
	return ;
}

/*
** ==================== is_comment ====================
** Receives a line which starts by #. As long as the next line starts by #
*/

char		*is_comment(t_farm *f, int ret, char *line)
{
	while (ret > 0 && line && line[0] == '#')
	{
		if (line && line[1] == '#')
			if ((ft_strcmp(line, "##start") == 0) \
			|| (ft_strcmp(line, "##end") == 0))
				raise_flag(f, line);
		ret = gnl_store(0, &line, f, GET_ROOMS);
	}
	return (line);
}
