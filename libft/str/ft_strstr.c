/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:58:47 by amamy             #+#    #+#             */
/*   Updated: 2018/11/16 11:25:54 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	counter;
	size_t	needle_c;

	counter = 0;
	needle_c = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[counter])
	{
		needle_c = 0;
		while (haystack[counter + needle_c] == needle[needle_c])
		{
			needle_c++;
			if (needle[needle_c] == '\0')
				return (((char*)&haystack[counter]));
		}
		counter++;
	}
	return (NULL);
}
