/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:49:02 by amamy             #+#    #+#             */
/*   Updated: 2018/11/17 12:10:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*source;

	cnt = 0;
	source = (unsigned char*)s;
	while (cnt < n)
	{
		if (*source == (unsigned char)c)
			return (source);
		source++;
		cnt++;
	}
	return (NULL);
}
