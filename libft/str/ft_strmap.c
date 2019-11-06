/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:35:21 by amamy             #+#    #+#             */
/*   Updated: 2018/11/19 16:02:42 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	counter;
	char	*str;

	counter = 0;
	if (s == NULL)
		return (0);
	if (f == NULL)
		return (0);
	if (!(str = ft_strdup(s)))
		return (0);
	while (str[counter] != '\0')
	{
		str[counter] = (*f)(s[counter]);
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
