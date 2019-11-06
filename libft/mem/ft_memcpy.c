/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:55:11 by amamy             #+#    #+#             */
/*   Updated: 2018/11/17 10:48:01 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*dsts;
	unsigned char	*srcs;

	dsts = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	counter = 0;
	while (counter < n)
	{
		dsts[counter] = srcs[counter];
		counter++;
	}
	return (dsts);
}
