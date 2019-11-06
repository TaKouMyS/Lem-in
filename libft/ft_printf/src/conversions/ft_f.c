/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 12:14:55 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_conv_f2_1 :
** Mode 1 : concat the digits of decimal part in s_deci_p.
** Mode 2 : Assigns the accuracy if needed (used in ft_ffinal)
*/

char			*ft_conv_f2_2(t_float *ft, t_data *d, char *flag, int mode)
{
	char *tmp;

	if (mode == 1)
	{
		tmp = ft->s_deci_p;
		if (!(ft->s_deci_p = ft_strjoin(tmp, ft->str_deci_ar_cp)))
		{
			ft_free(ft, 0, 2);
			return (NULL);
		}
		free(tmp);
		return (ft->s_deci_p);
	}
	if (mode == 2)
	{
		tmp = ft->s_deci_p;
		if (!(ft->s_deci_p = ft_float_accuracy(d, flag, ft)))
			return (NULL);
		free(tmp);
		return (NULL);
	}
	return (NULL);
}

/*
** ft_conv_f2_1 :
** used to convert and store char by char the decimal digit passed by
** ft_conv_f2.
*/

static char		*ft_conv_f2_1(t_float *ft, int mode)
{
	if (mode == 1)
	{
		if (!(ft->s_deci_p = ft_itoa(ft->deci_p)))
		{
			free(ft->int_p);
			return (NULL);
		}
		ft->deci_p = 0;
		return (ft->s_deci_p);
	}
	if (mode == 2)
	{
		if (!(ft->str_deci_ar_cp = ft_itoa(ft->deci_p)))
		{
			ft_free(ft, 0, 1);
			return (NULL);
		}
		ft->deci_p = 0;
		return (ft->str_deci_ar_cp);
	}
	return (NULL);
}

/*
** ft_conv_f2 :
** Gets the decimal part of the number.
*/

static char		*ft_conv_f2(t_float *ft, t_data *d, char *flag, int j)
{
	long double		ret;
	int				max;

	ret = ft->ap - (long long)ft->ap;
	max = ft_float_width(d, ft, flag, ret);
	while (((ft->ap - (long long)ft->ap) > 0.0 && j < max) || d->f & F_AP_0)
	{
		ret = ret * 10;
		ft->deci_p = ret;
		if (j == 0)
			ft->s_deci_p = ft_conv_f2_1(ft, 1);
		else
		{
			if (j > 1)
				free(ft->str_deci_ar_cp);
			ft->str_deci_ar_cp = ft_conv_f2_1(ft, 2);
		}
		ret = (ret - (long long)ret);
		if (j++ != 0)
			ft->s_deci_p = ft_conv_f2_2(ft, d, flag, 1);
		ft->ap = ret;
		d->f &= ~F_AP_0;
	}
	return (ft_ffinal(ft, d, flag, j));
}

static void		ft_cases(t_data *d, t_float *ft)
{
	if (d->f & F_BIG_L)
		ft->ap = (va_arg(d->ap, long double));
	else
		ft->ap = (va_arg(d->ap, double));
	if (ft->ap == 0)
		d->f |= F_AP_0;
}

/*
** ft_conv_f :
** Root function for floats. Get the ap, set the size of it in data(d) and
** return the result.
** in case of conversions with accuracy, return "", conversion happens later.
*/

char			*ft_conv_f(t_data *d, char *flag)
{
	t_float	*ft;
	int		j;
	char	*final;

	j = 0;
	if (((d->f & F_PRECIS || d->f & F_W_P) && (ft_strlen(flag) == 1)))
		return (ft_strdup(""));
	if (((d->f & F_BIG_L && !(d->f & F_PRECIS)) && (ft_strlen(flag) != 1)))
		return (ft_strdup(""));
	if (!(ft = ft_memalloc(sizeof(t_float))))
		return (NULL);
	ft_cases(d, ft);
	d->ap_sz = ft_intlen((int)ft->ap) + 7;
	if (!(ft->int_p = ft_itoa(ft->ap)))
		return (NULL);
	final = ft->int_p;
	if (!(ft->int_p = ft_strjoin(final, ".")))
		return (NULL);
	free(final);
	if (ft->ap < 0)
		ft->ap = -ft->ap;
	if (!(final = ft_conv_f2(ft, d, flag, j)))
		return (NULL);
	return (final);
}
