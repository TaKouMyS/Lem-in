/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:04:20 by amamy             #+#    #+#             */
/*   Updated: 2019/03/14 22:51:48 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nb_neg(char *str, long n, int base)
{
	size_t	counter;
	size_t	end;
	int		q;

	counter = 0;
	str[counter] = '-';
	end = ft_nb_len_base(n, base);
	n = -n;
	str[end] = '\0';
	counter = ft_nb_len_base(n, base);
	while (n != 0)
	{
		q = n % base;
		if (q <= 9)
			str[counter] = (n % base) + 48;
		if (q > 9)
			str[counter] = (n % base) + 55;
		n = n / base;
		counter--;
	}
	return (str);
}

char			*ft_itoa_base(long n, int base)
{
	char	*str;
	long	counter;
	int		q;

	counter = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_nb_len_base(n, 10) + 1)))
		return (NULL);
	if (n == 0 || n == -0)
		return ("0");
	if (n > 0)
		counter = ft_nb_len_base(n, base) - 1;
	if (n < 0)
		return (ft_nb_neg(str, n, base));
	str[counter + 1] = '\0';
	while (n != 0)
	{
		q = n % base;
		if (q <= 9)
			str[counter] = (n % base) + 48;
		if (q > 9)
			str[counter] = (n % base) + 55;
		n = n / base;
		counter--;
	}
	return (str);
}
