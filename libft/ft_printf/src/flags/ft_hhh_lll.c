/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhh_lll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:21:56 by amamy             #+#    #+#             */
/*   Updated: 2019/04/24 15:51:20 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_initialize: initializes data->ap_size, and enable flag when ap = 0.
** data->ap_sz is useful in precision and others flags.
*/

static void		ft_initialize(unsigned long long ap, t_data *data)
{
	data->ap_sz = ft_intlen(ap);
	if (ap == 0)
		data->f |= F_AP_0;
}

/*
** ft_conv_hhhlll_u: does the good cast depending on previous flags (ex: %hhu),
** also deals with < 0 numbers. Enable needed flags.
*/

char			*ft_conv_hhhlll_u(t_data *data, int base, int mode)
{
	unsigned long long	ap;
	char				*final;

	if (data->f & F_H)
		ap = (unsigned short)(va_arg(data->ap, int));
	else if (data->f & F_HH)
		ap = (unsigned char)(va_arg(data->ap, int));
	else if (data->f & F_L)
		ap = (unsigned long)(va_arg(data->ap, long));
	else if (data->f & F_LL)
		ap = (unsigned long long)(va_arg(data->ap, long long));
	else
	{
		ap = (va_arg(data->ap, int));
		data->ap_sz = ft_intlen(ap);
		if (ap == 0)
			data->f |= F_AP_0;
		if (!(final = itoa_base_m((int)ap, base, mode, data)))
			return (NULL);
		return (final);
	}
	ft_initialize(ap, data);
	if (!(final = ibmul(ap, base, mode, data)))
		return (NULL);
	return (final);
}

/*
** ft_conv_hhhlll: does the good cast depending on previous flags (ex: %hhd),
** also deals with < 0 numbers. Enable needed flags.
*/

char			*ft_conv_hhhlll(t_data *data)
{
	long long			ap;

	if (data->f & F_H)
		ap = (short)(va_arg(data->ap, int));
	else if (data->f & F_HH)
		ap = (char)(va_arg(data->ap, int));
	else if (data->f & F_L)
		ap = (long)(va_arg(data->ap, long));
	else if (data->f & F_LL)
		ap = (long long)(va_arg(data->ap, long long));
	else
		ap = (va_arg(data->ap, int));
	data->ap_sz = ft_intlen(ap);
	if (ap < 0 && !(data->f & ONLY_CONV) && (data->f & F_PRECIS \
		|| data->f & F_WIDTH))
	{
		data->f |= AP_NEG;
		ap = -ap;
	}
	if (ap < 0)
		data->f |= AP_NEG;
	if (ap == 0)
		data->f |= F_AP_0;
	return (ft_itoa(ap));
}
