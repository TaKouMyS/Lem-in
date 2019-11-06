/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bmul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:00:58 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 16:01:12 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ibmul(unsigned long long v, unsigned int b, int m, t_data *data)
{
	char				*str;
	char				*tab;
	unsigned long long	tmp;
	int					size;

	size = 0;
	if (m == 1)
		tab = "0123456789abcdef";
	else if (m == 2)
		tab = "0123456789ABCDEF";
	tmp = v;
	while (tmp /= b)
		size++;
	size = size + 1;
	m = size;
	if (!(str = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size > 0)
	{
		str[size-- - 1] = tab[v % b];
		v /= b;
	}
	if (m == 1 && str[0] == '0')
		data->f |= F_C_0;
	return (str);
}
