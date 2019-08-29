/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/08/29 22:51:18 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	first_line(t_farm *f)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	if (line)
	{
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i]) != 1)
				return (-1);
		}
		if (!(f = ft_memalloc(sizeof(t_farm))))
			return (-1);
		f->ant_nb = ft_atoi(line);
	}
	else
		return (-1);
	return (0);
}

int	room_check_syntax(char *line)
{
	int	sp;
	int	i;
	char *tmp;
	int	coo[3];

	tmp = line;
	i = 0;
	sp = 0;
	if (line[0] != '#')
	{
		while (sp <= 3 && tmp != NULL)
		{
			if (tmp = ft_strchr(tmp, ' ') != NULL)
			{
				tmp++;
				sp++;
				coo[i++] = &tmp;
			}
		}
		if (sp != 2 || line[0] == 'L' || room_check_coo(int coo[3]) != 0)
			return (-1);
	}
	return (0);
}

int	get_rooms(t_room *r)
{
	char *line;

	while (ft_strcmp(line, "\n") != 0)
	{
		get_next_line(0, &line);
		if (!(ft_strncmp(line, "#", 1) == 0)

	}
}

int	get_input(t_farm *f, t_room *r)
{
	int	ret;

	if (first_line(f) != 0 || get_rooms(r) != 0)
		return (-1);
}
