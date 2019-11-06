/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:17:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/20 16:17:38 by lgaultie         ###   ########.fr       */
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
