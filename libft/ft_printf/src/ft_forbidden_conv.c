/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forbidden_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:05:19 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 16:05:38 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_search_forbidden_conv(char *str)
{
	int		x;

	x = 0;
	while (str[x] != '\0' && str[x] != '%')
	{
		if (str[x] == '+' || str[x] == '-' || str[x] == '#' || str[x] == ' ' \
			|| str[x] == '.')
			x++;
		if ((str[x] >= 'a' && str[x] <= 'z') && str[x] != 'c' && str[x] != 's' \
			&& str[x] != 'p' && str[x] != 'd' && str[x] != 'i' \
			&& str[x] != 'o' && str[x] != 'u' && str[x] != 'x' \
			&& str[x] != 'f' && str[x] != 'l' && str[x] != 'h')
		{
			free(str);
			return (NULL);
		}
		if ((str[x] >= 'A' && str[x] <= 'Z') && str[x] != 'L' \
			&& str[x] != 'X' && str[x] != 'U')
		{
			free(str);
			return (NULL);
		}
		x++;
	}
	return (str);
}
