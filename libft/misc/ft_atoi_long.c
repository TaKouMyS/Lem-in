/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:31:33 by amamy             #+#    #+#             */
/*   Updated: 2019/10/29 01:37:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_long(const char *nptr)
{
	size_t	cnt;
	int		sign;
	long	nb;

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
		if (sign == 1 && nb > __LONG_MAX__)
			return (-1);
		if (sign == -1 && nb > (long)__LONG_MAX__)
			return (0);
		cnt++;
	}
	return (nb * (long)sign);
}
