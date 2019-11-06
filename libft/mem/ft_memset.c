/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:11:18 by amamy             #+#    #+#             */
/*   Updated: 2018/11/11 17:45:38 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*strs;
	size_t			counter;

	strs = (unsigned char*)s;
	counter = 0;
	while (counter < len)
	{
		strs[counter] = c;
		counter++;
	}
	return (strs);
}
