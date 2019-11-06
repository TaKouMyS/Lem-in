/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:31:02 by amamy             #+#    #+#             */
/*   Updated: 2018/11/13 21:24:56 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t counter;

	counter = 0;
	while (src[counter] != '\0' && counter < len)
	{
		dst[counter] = src[counter];
		counter++;
	}
	while (counter < len)
	{
		dst[counter] = '\0';
		counter++;
	}
	return (dst);
}
