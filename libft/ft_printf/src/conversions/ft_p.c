/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:57:13 by amamy             #+#    #+#             */
/*   Updated: 2019/10/16 16:34:26 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_initialize: data->conv_sz is needed in files dealing with flags.
*/

static int		ft_initialize(t_data *d)
{
	d->conv_sz = 14;
	d->conv_t_sz += d->conv_sz;
	d->ap_sz = 15;
	return (0);
}

/*
** ft_freetmpitoa: free and return.
*/

static char		*ft_freetmpitoa(char *tmp, char *ret_itoa, int mode)
{
	free(tmp);
	if (mode == 1)
		free(ret_itoa);
	return (NULL);
}

/*
** ft_conv_p: deals with %p cases.
*/

char			*ft_conv_p(t_data *data)
{
	unsigned long	ad;
	char			*final;
	char			*tmp;
	int				i;
	char			*ret_itoa;

	i = ft_initialize(data);
	if (!(ad = (va_arg(data->ap, unsigned long))))
	{
		data->conv_sz = 3;
		return (ft_strdup("0x0"));
	}
	if (!(tmp = ft_strdup("0x")))
		return (NULL);
	if (!(ret_itoa = ft_itoa_base_p(ad, 16)))
		return (ft_freetmpitoa(tmp, ret_itoa, 0));
	if (!(final = ft_strjoin(tmp, ret_itoa)))
		return (ft_freetmpitoa(tmp, ret_itoa, 1));
	while (final[i++] != '\0')
		final[i] = ft_tolower(final[i]);
	ft_freetmpitoa(tmp, ret_itoa, 1);
	data->conv_sz = ft_strlen(final);
	return (final);
}
