/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:48:07 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:18:01 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_blank(char const *str)
{
	size_t	size;
	size_t	counter;

	size = ft_strlen(str);
	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == ' ' || str[counter] == '\t' || str[counter] == '\n')
			size--;
		counter++;
	}
	return (size);
}

char		*ft_no_space(char const *s)
{
	size_t	size;
	size_t	counter;
	size_t	counter2;
	char	*dest;

	if (s == NULL)
		return (NULL);
	size = ft_strlen_blank(s);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	counter = 0;
	counter2 = 0;
	while (s[counter] != '\0')
	{
		if (!(s[counter] == ' ' || s[counter] == '\t' || s[counter] == '\n'))
		{
			dest[counter2] = s[counter];
			counter2++;
		}
		counter++;
	}
	dest[counter] = '\0';
	return (dest);
}
