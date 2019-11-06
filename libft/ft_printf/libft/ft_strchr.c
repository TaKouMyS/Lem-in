/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:36:46 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/22 14:37:28 by lgaultie         ###   ########.fr       */
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
