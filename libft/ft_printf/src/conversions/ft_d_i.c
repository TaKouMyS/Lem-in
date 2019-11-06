/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 12:32:38 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_conv_d_i: Deals with %d and %i conversion. ft_conv_hhhlll does the good
** cast depending on previous flags (ex: %hhd), also deals with < 0 numbers by
** returning an empty string.
*/

char	*ft_conv_di(t_data *data)
{
	char	*final;

	if (!(final = ft_conv_hhhlll(data)))
		return (NULL);
	if (((data->f & F_PLUS) || (data->f & F_MINUS)) && (data->f & AP_NEG) \
		&& data->f & F_PRECIS)
	{
		data->ap_sz--;
		data->f |= F_PLUS_MINUS;
	}
	data->conv_sz = ft_strlen(final);
	if (final[0] == '0' && final[1] == '\0' && ((data->f & F_SHARP) \
		|| data->f & F_PRECIS))
	{
		free(final);
		return (ft_strdup(""));
	}
	return (final);
}
