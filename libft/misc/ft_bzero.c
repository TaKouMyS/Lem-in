/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:11:18 by amamy             #+#    #+#             */
/*   Updated: 2018/11/11 17:44:59 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*strs;
	size_t			counter;

	strs = (unsigned char*)s;
	counter = 0;
	while (counter < n)
	{
		strs[counter] = 0;
		counter++;
	}
	return (strs);
}
