/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:26:32 by amamy             #+#    #+#             */
/*   Updated: 2018/11/25 19:34:50 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nb_words(const char *str, char c)
{
	size_t	run;
	size_t	nb_words;

	if (str == 0)
		return (0);
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
