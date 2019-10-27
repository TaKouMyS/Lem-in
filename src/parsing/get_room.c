/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:22:19 by amamy             #+#    #+#             */
/*   Updated: 2019/10/28 00:54:08 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem-in.h"

/*
** room_check_coo :
** checks if coordonates are numbers.
*/

static int	room_check_coo(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(line, ' ') + 1;
	while (tmp[i] != ' ' && tmp[i] != '\0')
		if (ft_isdigit(tmp[i++]) != 1)
			return (-1);
	if (tmp[i++] != ' ')
		return (-1);
	while (tmp[i] != '\0' && i <= 20)
		if (ft_isdigit(tmp[i++]) != 1)
			return (-1);
	return (0);
}

/*
** room_check_syntax :
** Receive a supposed room, check if the syntax is correct.
** Sends it to check if coordonates are integers.
** Syntax : name coo coo
** If line is a comment, sends it for checks.
*/

static char	*room_check_syntax(char *line)
{
	int		sp;
	int		i;
	char	*tmp;

	i = 0;
	sp = 0;
	tmp = line;
	if (line[0] != '#')
	{
		while (sp <= 3 && tmp != NULL)
			if (((tmp = ft_strchr(tmp, ' ')) != NULL) && tmp++)
				sp++;
		if (sp != 2 || line[0] == 'L' || room_check_coo(line) != 0)
		{
			ft_memdel((void*)&line);
			return (NULL);
		}
	}
	return (line);
}

/*
** ==================== check_comment ====================
** Receives a string starting with '#' if not ##start or ##end, just return (0).
** If command start or end, checks if we already have a start or end.
*/

static int	check_comment(t_farm *f, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (f->start != NULL)
			return (-1);
		else
		{
			f->flags |= START;
			f->flags &= ~END;
		}
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (f->end != NULL)
			return (-1);
		else
		{
			f->flags |= END;
			f->flags &= ~START;
		}
	}
	return (0);
}


/*
** ==================== dash_comment ====================
** mode 0 : if the given line is NOT a link or is a comment return (0)
** mode 1 : if the given line not a link and is NOT a comment return (0)
*/

static int	dash_comment(char *line, int mode)
{
	if (mode == 0)
	{
		if ((ft_strchr(line, '-') == NULL) || line[0] == '#')
			return (0);
		else
			return (-1);
	}
	else if (mode == 1)
	{
		if ((ft_strchr(line, '-') != NULL && line[0] != '#'))
			return (0);
		else
			return (-1);
	}
	return (0);
}

/*
** get_room :
** Read stdin for rooms. Check room syntax and store them.
*/

int			get_room(t_room *r, t_farm *f)
{
	char	*line;
	int		ret;
	long	id;

	id = 0;
	ret = gnl_store(0, &line, f, GET_ROOMS);
	while (ret > 0 && line && dash_comment(line, 0) != -1)
	{
		if (line && line[0] == '#')
		{
			if (check_comment(f, line) == -1)
				return (error_free_line(line));
		}
		else if (line && ft_strchr(line, '-') == NULL)
			if ((!(line) || (line = room_check_syntax(line)) == NULL) 	\
			|| (r = new_room(f, r, line, id++)) == NULL)
				return (error_free_line(line));
		ft_memdel((void*)&line);
		ret = gnl_store(0, &line, f, GET_ROOMS);
		if (line && dash_comment(line, 1) != -1 && ((f->line = line)))
			return (0);
	}
	ft_memdel((void*)&line);
	return ((ret > 0) ? 0 : -1);
}