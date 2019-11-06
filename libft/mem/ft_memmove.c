/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:21:56 by amamy             #+#    #+#             */
/*   Updated: 2018/11/13 15:28:17 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			counter;

	counter = 0;
	if ((unsigned char*)dst > (unsigned char*)src)
	{
		len--;
		while (len + 1 > 0)
		{
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
			len--;
		}
	}
	if ((unsigned char*)src > (unsigned char*)dst)
	{
		while (counter < len)
		{
			((unsigned char*)dst)[counter] = ((unsigned char*)src)[counter];
			counter++;
		}
	}
	return (dst);
}
