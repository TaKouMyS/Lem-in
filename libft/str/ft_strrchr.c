/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:15:55 by amamy             #+#    #+#             */
/*   Updated: 2018/11/15 16:43:11 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;
	char	*source;

	source = (char*)s;
	counter = ft_strlen(s);
	if (c == '\0')
		return (&source[counter]);
	counter--;
	while (counter >= 0 && source[counter] != c)
		counter--;
	if (source[counter] == c)
		return (&source[counter]);
	return (NULL);
}
