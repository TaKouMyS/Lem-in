/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:24:56 by amamy             #+#    #+#             */
/*   Updated: 2018/11/14 15:10:25 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	counter;
	char	*source;
	int		found;

	source = (char*)s;
	counter = 0;
	found = 0;
	if (source[counter] == c)
		return (&source[counter]);
	while (source[counter] != '\0' && source[counter] != c)
	{
		counter++;
	}
	if (source[counter] == c)
		found = 1;
	return ((found == 1) ? (&source[counter]) : (NULL));
}
