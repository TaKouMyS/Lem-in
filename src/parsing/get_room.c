/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:22:19 by amamy             #+#    #+#             */
/*   Updated: 2019/09/01 21:17:49 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** room_check_coo :
** checks if coordonates are numbers.
*/

static int	room_check_coo(char *line)
{
	char *tmp;
	int	i;

	i = 0;
	tmp = ft_strchr(line, ' ') + 1;
	while (tmp[i] != ' ' && tmp[i] != '\0')
		if (ft_isdigit(tmp[i++]) != 1)
			return (-1);
	if (tmp[i++] != ' ')
		return (-1);
	while (tmp[i] != '\0' && i <= 20 )
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

char			*room_check_syntax(char *line, t_farm *f)
{
	int	sp;
	int	i;
	char *tmp;

	tmp = line;
	i = 0;
	sp = 0;
	if (line[0] != '#')
	{
		while (sp <= 3 && tmp != NULL)
		{
			if (((tmp = ft_strchr(tmp, ' ')) != NULL) && tmp++)
				sp++;
		}
		if (sp != 2 || line[0] == 'L' || room_check_coo(line) != 0)
		{
			ft_memdel((void*) &line);
			return (NULL);
		}
	}
	else
		if ((line = check_comment(line, f)) == NULL)
			return (NULL);
	return (line);
}

/*
** get_room :
** Read stdin for rooms. Check room syntax and store them.
*/

int			get_room(t_room *r, t_farm *f)
{
	char *line;
	int		name_size;

	name_size = 0;
	get_next_line(0, &line);
	while (ft_strchr(line, '-') == NULL)
	{
		if ((!(line) || (line = room_check_syntax(line, f)) == NULL))
			return (-1);
		if ((r = new_room(r, f)) == NULL)
			return (-1);
		// ft_printf("Line : |%s|\n", line);
		while (line[name_size] != ' ') // need to add && line[name_size] != '\0'
			name_size++;
		if (!(r->name = ft_strndup(line, name_size)))
			return (-1);
		ft_memdel((void*)&line);
		get_next_line(0, &line);
	}
	ft_memdel((void*)&line);
	return (0);
}
