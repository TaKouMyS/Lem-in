/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:03:39 by amamy             #+#    #+#             */
/*   Updated: 2019/07/30 22:01:19 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nb_neg(char *str, long long n)
{
	size_t	counter;
	size_t	end;
	int		min;

	counter = 0;
	min = 0;
	str[counter] = '-';
	end = ft_nb_len_base(n, 10);
	if (n < -9223372036854775807 && n++)
		min = 1;
	n = -n;
	str[end] = '\0';
	counter = ft_nb_len_base(n, 10);
	while (n != 0)
	{
		str[counter] = (n % 10) + 48;
		n = n / 10;
		counter--;
	}
	if (min == 1)
		str[19] = '8';
	return (str);
}

char			*ft_itoa(long long n)
{
	char	*str;
	size_t	counter;

	counter = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * ft_nb_len_base(n, 10) + 1)))
		return (NULL);
	if (n == 0 || n == -0)
		str[0] = '0';
	if (n > 0)
		counter = ft_nb_len_base(n, 10) - 1;
	if (n < 0)
		return (ft_nb_neg(str, n));
	str[counter + 1] = '\0';
	while (n != 0)
	{
		str[counter] = (n % 10) + 48;
		n = n / 10;
		counter--;
	}
	return (str);
}
