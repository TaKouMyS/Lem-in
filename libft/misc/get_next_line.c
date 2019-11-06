/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:28:19 by amamy             #+#    #+#             */
/*   Updated: 2019/09/01 19:20:00 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_str(const int fd, char **str)
{
	char		buf[BUFF_SIZE + 1];
	ssize_t		size;
	char		*save_str;

	size = 1;
	while (size > 0 && !(ft_strchr(*str, '\n')))
	{
		size = read(fd, buf, BUFF_SIZE);
		if (size > 0)
		{
			buf[size] = '\0';
			save_str = *str;
			if (!(*str = ft_strjoin(save_str, buf)))
				return (NULL);
			ft_memdel((void*)&save_str);
		}
		else if (size == -1)
			return (NULL);
	}
	return (*str);
}

static char	*ft_stock_line(char **str)
{
	ssize_t		cnt;
	char		*save_str;
	char		*newline;

	cnt = 0;
	save_str = NULL;
	while (((*str)[cnt] != '\n' && (*str)[cnt] != '\0'))
		cnt++;
	if ((*str)[cnt] == '\n')
	{
		if (!(newline = ft_strndup(*str, cnt)))
			return (NULL);
		save_str = *str;
		if (!(*str = ft_strdup(save_str + cnt + 1)))
			return (NULL);
		ft_memdel((void*)&save_str);
	}
	else if (!(newline = ft_strdup(*str)))
		return (NULL);
	if (*str == NULL || save_str == NULL)
	{
		ft_memdel((void*)&*str);
		*str = NULL;
	}
	return (newline);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buf[BUFF_SIZE];

	if (!line || read(fd, buf, 0) == -1 || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!str)
		str = ft_strnew(0);
	if (((str = (ft_read_str(fd, &str))) == NULL))
	{
		ft_memdel((void*)&str);
		return (-1);
	}
	if (*str)
	{
		if (!(*line = ft_stock_line(&str)))
		{
			ft_memdel((void*)&str);
			return (-1);
		}
		ft_memdel((void*)&str);
		return (1);
	}
	ft_memdel((void*)&str);
	return (0);
}
