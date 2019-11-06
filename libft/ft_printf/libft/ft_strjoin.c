/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:38:03 by amamy             #+#    #+#             */
/*   Updated: 2019/04/06 17:04:25 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;
	int		one;
	int		two;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	one = ft_strlen(s1);
	two = ft_strlen(s2);
	size = one + two;
	if (!(dest = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	dest = ft_strcpy(dest, s1);
	dest = ft_strcat(dest, s2);
	return (dest);
}
