/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:05 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:20:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	counter;

	counter = 0;
	if (s == NULL)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[counter] != '\0' && counter < len)
	{
		dest[counter] = s[start];
		counter++;
		start++;
	}
	dest[counter] = '\0';
	return (dest);
}
