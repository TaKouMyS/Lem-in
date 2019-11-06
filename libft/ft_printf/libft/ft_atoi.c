/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:16:26 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/06 16:16:55 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	cnt;
	int		sign;
	size_t	nb;

	nb = 0;
	cnt = 0;
	sign = 1;
	while ((nptr[cnt] >= '\t' && nptr[cnt] <= '\r') || nptr[cnt] == ' ')
		cnt++;
	if (nptr[cnt] == '-')
		sign = -1;
	if (nptr[cnt] == '+' || nptr[cnt] == '-')
		cnt++;
	while (nptr[cnt] >= '0' && nptr[cnt] <= '9' && nptr[cnt] != '\0')
	{
		nb = nb * 10 + (nptr[cnt] - 48);
		if (sign == 1 && nb > __INT64_MAX__)
			return (-1);
		if (sign == -1 && nb > (size_t)__INT64_MAX__ + 1)
			return (0);
		cnt++;
	}
	return (nb * sign);
}
