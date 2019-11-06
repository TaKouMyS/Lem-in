/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:03:39 by amamy             #+#    #+#             */
/*   Updated: 2019/07/30 22:02:12 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nb_neg(char *str, int n)
{
	size_t counter;
	size_t end;

	counter = 0;
	str[counter] = '-';
	end = ft_nb_len_base(n, 10);
	if (n == -2147483648)
	{
		counter = ft_nb_len_base(n, 10) - 1;
		str[counter] = (n % 10) * -1 + 48;
		n = n / 10;
		counter--;
	}
	n = -n;
	str[end] = '\0';
	if (n != -2147483648)
		counter = ft_nb_len_base(n, 10);
	while (n != 0)
	{
		str[counter] = (n % 10) + 48;
		n = n / 10;
		counter--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	counter;

	counter = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_nb_len_base(n, 10) + 1)))
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
