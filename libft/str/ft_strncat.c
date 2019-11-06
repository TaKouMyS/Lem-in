/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:43:25 by amamy             #+#    #+#             */
/*   Updated: 2018/11/14 12:53:44 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	counter;
	size_t	end_dest;

	end_dest = ft_strlen(dest);
	counter = 0;
	while (src[counter] != '\0' && counter < n)
	{
		dest[end_dest] = src[counter];
		counter++;
		end_dest++;
	}
	dest[end_dest] = '\0';
	return (dest);
}
