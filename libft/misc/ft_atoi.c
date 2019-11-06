/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:24:21 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:15:20 by amamy            ###   ########.fr       */
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
	while (nptr[cnt] >= '0' && nptr[cnt] <= '9')
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
