/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:21:56 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:20:52 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *str, char c)
{
	size_t	run;
	size_t	nb_words;

	nb_words = 0;
	run = 0;
	while (str[run] != '\0')
	{
		if (str[run] == c)
			run++;
		if (str[run] != c && str[run] != '\0')
		{
			nb_words++;
			while (str[run] != c && str[run] != '\0')
				run++;
		}
	}
	return (nb_words);
}

static char		**ft_create_array(char **array, char const *str, char c)
{
	size_t	run;
	size_t	size;
	size_t	line;

	run = 0;
	size = 0;
	line = 0;
	while (str[run] != '\0')
	{
		if (str[run] == c)
			run++;
		if (str[run] != c)
		{
			while (str[run] != c && str[run] != '\0')
			{
				run++;
				size++;
			}
			if (!(array[line] = (char*)malloc(sizeof(char) * (size + 1))))
				return (NULL);
			size = 0;
			line++;
		}
	}
	return (array);
}

static char		**ft_fill(char **array, char const *str, char c)
{
	size_t	run;
	size_t	counter;
	size_t	line;

	counter = 0;
	run = 0;
	line = 0;
	while (str[run] != '\0')
	{
		if (str[run] == c)
			run++;
		if (str[run] != c)
		{
			while (str[run] != c && str[run] != '\0')
			{
				array[line][counter] = str[run];
				run++;
				counter++;
			}
			array[line][counter] = '\0';
			counter = 0;
			line++;
		}
	}
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	if (!(ft_create_array(array, s, c)))
		return (NULL);
	ft_fill(array, s, c);
	array[ft_count_words(s, c)] = 0;
	return (array);
}
