/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:43:25 by amamy             #+#    #+#             */
/*   Updated: 2018/11/15 14:06:35 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	end_dest;
	size_t	len_dest;

	len_dest = ft_strlen(dst);
	end_dest = ft_strlen(dst);
	counter = 0;
	if (size < len_dest)
		return (ft_strlen(src) + size);
	while (src[counter] && ((len_dest + counter + 1) < size))
	{
		dst[end_dest] = src[counter];
		counter++;
		end_dest++;
	}
	dst[end_dest] = '\0';
	return (ft_strlen(src) + len_dest);
}
