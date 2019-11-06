/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:27:02 by amamy             #+#    #+#             */
/*   Updated: 2018/11/13 14:31:50 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			counter;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	counter = 0;
	if (n == 0)
		return (0);
	while (n > 1 && src1[counter] == src2[counter])
	{
		counter++;
		n--;
	}
	return (src1[counter] == src2[counter]) ? 0 : src1[counter] - src2[counter];
}
