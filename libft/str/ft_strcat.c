/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:41:30 by amamy             #+#    #+#             */
/*   Updated: 2018/11/13 21:54:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	counter;
	size_t	end_dest;

	end_dest = ft_strlen(dest);
	counter = 0;
	while (src[counter] != '\0')
	{
		dest[end_dest] = src[counter];
		counter++;
		end_dest++;
	}
	dest[end_dest] = '\0';
	return (dest);
}
