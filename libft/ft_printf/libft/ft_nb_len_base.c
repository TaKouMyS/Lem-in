/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_len_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:18:33 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/20 16:18:57 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_len_base(long long value, int base)
{
	int	size;

	size = 0;
	if (value == 0 || value == -0)
		size = 1;
	if (value < 0)
		size++;
	while (value != 0)
	{
		value = value / (long long)base;
		size++;
	}
	return (size);
}
