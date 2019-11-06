/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:47:45 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/23 21:10:50 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_conv_u: Deals with %u conversion. ft_conv_hhhlll_u does the good cast
** depending on previous flags. Also deals with < 0 numbers by
** returning an empty string.
*/

char	*ft_conv_u(t_data *data)
{
	unsigned long long	ap;
	char				*final;

	ap = 0;
	if (!(final = ft_conv_hhhlll_u(data, 10, 1)))
		return (NULL);
	data->ap_sz = ft_intlen(ap);
	data->conv_sz = ft_strlen(final);
	if (data->f & F_C_0)
		data->f &= ~F_C_0;
	if (data->f & F_AP_0 && (data->f & F_PRECIS || data->f & F_W_P))
	{
		free(final);
		if (!(final = ft_strdup("")))
			return (NULL);
	}
	return (final);
}
