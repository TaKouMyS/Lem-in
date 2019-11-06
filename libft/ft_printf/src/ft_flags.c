/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:22:30 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 15:55:24 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_end_percent: %% cases.
*/

static char	*ft_end_percent(char *ret_flag, t_data *data)
{
	char	*final;

	if (data->f & F_WIDTH && !(data->f & F_PRECIS))
	{
		ret_flag[ft_strlen(ret_flag) - 1] = '%';
		if (!(final = ft_strdup(ret_flag)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strdup("%")))
			return (NULL);
	}
	free(ret_flag);
	return (final);
}

/*
** ft_conv_percent: deals with %242% cases. We have to return ret_flag + % or
** % + ret_flag depending on wether the flag PERCENT is enabled or not.
*/

static char	*ft_conv_percent(int i, char *flag, t_data *data)
{
	char	*ret_flag;
	char	*final;

	if (!(data->f & F_MINUS))
	{
		data->conv_sz = 1;
		if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
			return (NULL);
		if (!(final = ft_strjoin(ret_flag, "%")))
			return (NULL);
	}
	if (data->f & F_MINUS)
	{
		data->conv_sz = 1;
		i--;
		if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
			return (NULL);
		if (data->f & F_WIDTH)
			if (!(final = ft_strjoin("%", ret_flag)))
				return (NULL);
	}
	free(ret_flag);
	return (final);
}

/*
** ft_final: free ret_conv or ret_flag and return final.
*/

static char	*ft_final(char *ret_conv, char *ret_flag, char *final, int mode)
{
	if (mode == 1)
	{
		free(ret_conv);
		return (ret_flag);
	}
	if (mode == 2)
	{
		free(ret_conv);
		free(ret_flag);
	}
	if (mode == 3 || mode == 4)
	{
		free(ret_conv);
		if (mode == 3)
			free(ret_flag);
		return (NULL);
	}
	return (final);
}

/*
** ft_s_fwp_minus: return the final string, join flag + conv in normal cases,
** and calls ft_fwp_minus when the flag minus is activated: we have to join
** conv + flag in such a case.
*/

static char	*ft_s_fwp_minus(char f, char *ret_conv, char *ret_flag, t_data *d)
{
	char *final;

	if (d->f & F_W_P_0)
	{
		if (!(final = ft_strdup("")))
			return (NULL);
	}
	else if ((f == 's' && (d->f & F_MINUS) && (d->f & F_W_P)) \
		|| (f == 'u' && (d->f & F_PRECIS) && (d->f & F_C_0)))
	{
		if (!(final = ft_strdup(ret_flag)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strjoin(ret_flag, ret_conv)))
			return (NULL);
	}
	if ((d->f & F_W_P) && d->f & F_MINUS)
	{
		if (!(final = ft_fwp_minus(final, d)))
			return (NULL);
	}
	return (final);
}

/*
** ft_flag_conv: join the converted conversion with converted flags.
*/

char		*ft_flag_conv(char *f, char *ret_conv, int i, t_data *d)
{
	char	*final;
	char	*ret_flag;

	if (f[i] != '%' && !(d->f & F_PERCENT))
	{
		if (!(ret_conv = ft_only_conv(&f[i], d)))
			return (NULL);
		if ((ret_conv[0] == '\0' && d->f & F_SHARP && !(d->f & F_WIDTH)) \
			|| (d->f & F_SPACE && d->f & AP_NEG))
			return (ret_conv);
	}
	if (!(d->f & F_PERCENT) && (d->f & F_MINUS) && (d->f & F_WIDTH) \
		&& !(d->f & F_PRECIS) && !(d->f & F_W_P))
		return (ft_for_minus(ret_conv, f, i, d));
	if (d->f & F_PERCENT)
		return (ft_conv_percent(i, f, d));
	if (!(ret_flag = ft_special_cases(i, f, d)))
		return (ft_final(ret_conv, ret_flag, ret_flag, 4));
	if ((d->f & F0) || ((d->f & F_PRECIS) && (f[i] == 's' || f[i] == 'c')))
		return (ft_final(ret_conv, ret_flag, ret_flag, 1));
	if (f[i] == '%')
		return (ft_end_percent(ret_flag, d));
	if (!(final = ft_s_fwp_minus(f[i], ret_conv, ret_flag, d)))
		return (ft_final(ret_conv, ret_flag, ret_flag, 3));
	return (ft_final(ret_conv, ret_flag, final, 2));
}
