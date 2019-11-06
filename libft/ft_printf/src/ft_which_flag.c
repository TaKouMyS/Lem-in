/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:23:12 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 15:41:03 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_sharp_precent: if flag SHARP or PERCENT + WIDTH or PRECIS.
** Call appropriates flag function depending of enabled flags.
** Will return the converted flag.
*/

static char		*ft_sharp_precent(char *flag, t_data *d)
{
	char	*final;

	if (d->f & F_W_P && !(d->f & F_PERCENT))
	{
		if (flag[ft_strlen(flag) - 1] == 'X')
			d->f |= F_BIG_X;
		if (!(final = ft_preci_width(flag, d)))
			return (NULL);
	}
	else if (d->f & F_WIDTH && !(d->f & F_MINUS))
		return (ft_width(flag, d));
	else if (d->f & F_WIDTH && d->f & F_MINUS)
		return (ft_width_minus(flag, d));
	else if (d->f & F_PRECIS && !(d->f & F_PERCENT))
	{
		if (!(final = ft_precision_d(flag, d)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strnew(0)))
			return (NULL);
	}
	return (final);
}

/*
** ft_which_flag3: Call appropriates flag function depending of enabled flags.
** Will return the converted flag.
*/

static char		*ft_which_flag3(char *flag, char cv, t_data *data)
{
	char	*final;

	(void)cv;
	if (data->f & F_SPACE)
	{
		if (!(final = ft_strnew(1)))
			return (NULL);
		else if (!(data->f & F_PERCENT))
			final[0] = ' ';
	}
	else if (data->f & F_MINUS && !(data->f & F_W_P))
	{
		if (!(final = ft_minus(flag, data)))
			return (NULL);
	}
	else if (data->f & F_H || data->f & F_HH || data->f & F_L || data->f & F_LL)
		return (ft_strdup(""));
	else if (cv == 'f')
	{
		if (!(final = ft_conv_f(data, flag)))
			return (NULL);
	}
	else
		final = NULL;
	return (final);
}

/*
** ft_which_flag2: Call appropriates flag function depending of enabled flags.
** Will return the converted flag.
*/

static char		*ft_which_flag2(char *flag, char cv, t_data *data)
{
	char	*final;

	if (data->f & F_W_P && cv != 'f')
	{
		if (cv == 's')
			data->f |= F_S;
		if (!(final = ft_preci_width(flag, data)))
			return (NULL);
	}
	else if (data->f & F_ZERO || (data->f & F_WIDTH && !(data->f & F_PRECIS) \
		&& !(data->f & F_W_P)))
	{
		if (!(final = ft_width(flag, data)))
			return (NULL);
	}
	else if (data->f & F_PLUS)
	{
		if (!(final = ft_plus(flag, data)))
			return (NULL);
	}
	else
		return (ft_which_flag3(flag, cv, data));
	return (final);
}

/*
** ft_which_flag: Call appropriates flag function depending of enabled flags.
** Will return the converted flag.
*/

char			*ft_which_flag(char *flag, char cv, t_data *d)
{
	char	*final;

	if (ft_strlen(flag) == 2 && d->f & F_PRECIS)
		return (ft_strdup(""));
	if (d->f & F_SHARP || ((d->f & F_PERCENT) && (d->f & F_WIDTH \
		|| d->f & F_PRECIS)))
	{
		if (!(final = ft_sharp_precent(flag, d)))
			return (NULL);
	}
	else if ((d->f & F_PRECIS || d->f & F_WIDTH) && cv == 's' \
		&& !(d->f & F_W_P))
	{
		if (!(final = ft_string(flag, d, 1)))
			return (NULL);
	}
	else if (d->f & F_PRECIS && cv != 'f')
	{
		if (!(final = ft_precision_d(flag, d)))
			return (NULL);
	}
	else
		final = ft_which_flag2(flag, cv, d);
	return (final);
}
