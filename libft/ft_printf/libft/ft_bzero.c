/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:11:18 by amamy             #+#    #+#             */
/*   Updated: 2019/03/20 16:17:01 by lgaultie         ###   ########.fr       */
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
