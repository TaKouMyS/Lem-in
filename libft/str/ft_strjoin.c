/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:38:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/26 21:06:04 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	dest = ft_strcpy(dest, s1);
	dest = ft_strcat(dest, s2);
	return (dest);
}
