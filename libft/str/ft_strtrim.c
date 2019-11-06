/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:48:07 by amamy             #+#    #+#             */
/*   Updated: 2018/11/25 20:10:23 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen_blank(char const *str)
{
	size_t	size;
	size_t	counter;

	size = 0;
	counter = ft_strlen(str) - 1;
	while ((str[counter] == ' ' || str[counter] == '\t'
		|| str[counter] == '\n') && counter != 0)
		counter--;
	if (counter == 0)
		return (0);
	size = counter;
	counter = 0;
	while (str[counter] != '\0' && (str[counter] == ' '
		|| str[counter] == '\t' || str[counter] == '\n')
		&& counter <= ft_strlen(str))
		counter++;
	size = size - (counter - 1);
	return (size);
}

char			*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	counter;
	char	*dest;

	if (s == NULL)
		return (NULL);
	size = ft_strlen_blank(s);
	counter = 0;
	while (s[counter] != '\0' && (s[counter] == ' '
		|| s[counter] == '\t' || s[counter] == '\n') && counter <= ft_strlen(s))
		counter++;
	dest = ft_strsub(s, counter, size);
	return (dest);
}
