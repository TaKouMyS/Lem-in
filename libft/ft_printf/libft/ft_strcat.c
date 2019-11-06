/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:19:27 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/20 16:19:36 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	counter;
	size_t	end_dest;

	end_dest = ft_strlen(dest);
	counter = 0;
	while (src[counter] != '\0')
	{
		dest[end_dest] = src[counter];
		counter++;
		end_dest++;
	}
	dest[end_dest] = '\0';
	return (dest);
}
