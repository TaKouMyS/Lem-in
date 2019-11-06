/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:17:02 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/23 22:27:00 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_no_flag_zero: deals with cases not dealing with flag zero.
*/

static char		*ft_no_flag_zero(char *ret, int width, int i, t_data *data)
{
	int		surplus;

	surplus = (data->f & F_PLUS && !(data->f & F_PERCENT)) ? 1 : 0;
	if (data->f & AP_NEG && !(data->f & F_UNSIGNED))
	{
		while (i < width - data->conv_sz - 1)
			ret[i++] = ' ';
		ret[i++] = '-';
	}
	else
	{
		while (i < width - data->conv_sz - surplus)
			ret[i++] = ' ';
		if (data->f & F_PLUS && !(data->f & F_PERCENT))
			ret[i++] = '+';
	}
	return (ret);
}

/*
** ft_small_width: when width is smaller than data->conv_sz which is the size
** of ap.
*/

static char		*ft_small_width(t_data *data)
{
	if (data->f & AP_NEG && !(data->f & F_UNSIGNED))
		return (ft_strdup("-"));
	else if (data->f & F_PLUS && !(data->f & F_PERCENT))
		return (ft_strdup("+"));
	return (ft_strdup(""));
}

/*
** ft_width2: apply the conversion and return converted flag. Called by
** ft_width in ft_width.c.
*/

char			*ft_width2(int width, t_data *d)
{
	int		i;
	int		o;
	char	*ret;

	i = 0;
	if (width > d->conv_sz)
	{
		o = (d->f & AP_NEG || d->f & F_PLUS) ? 1 : 0;
		if (!(ret = ft_memalloc(sizeof(char) * ((width - d->conv_sz) + 1 + o))))
			return (NULL);
		if (d->f & F_ZERO)
		{
			if (d->f & AP_NEG && !(d->f & F_UNSIGNED))
				ret[i++] = '-';
			else if (d->f & F_PLUS && !(d->f & F_PERCENT))
				ret[i++] = '+';
			while (i < width - d->conv_sz)
				ret[i++] = '0';
		}
		if (!(d->f & F_ZERO))
			ret = ft_no_flag_zero(ret, width, i, d);
	}
	if (width <= d->conv_sz)
		return (ft_small_width(d));
	return (ret);
}

static void		ft_c_null(char *f, int i, t_data *data)
{
	if (f[ft_strlen(f) - 1] == 'c' && data->f & F_AP_0)
		data->index_0[data->index_0[0]] += i - 1;
	else
		data->index_0[data->index_0[0]] += 0;
}

/*
** ft_width: analyse the flag to convert it into a int which will be width.
** Sends this int to ft_width2 which will apply the conversion.
*/

char			*ft_width(char *f, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (data->f & F_WIDTH && (i = data->tmp))
		data->f &= ~F_WIDTH;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	while (f[i] != '\0')
	{
		if (f[i] == '#' || f[i] == '+')
			i++;
		if ((f[i] >= '0' && f[i] <= '9') || f[i] == '-' || f[i] == '+')
			conv[j] = f[i];
		i++;
		j++;
	}
	i = ft_atoi(conv);
	free(conv);
	if (data->f & F_C_02)
		ft_c_null(f, i, data);
	i = (i < 0) ? -i : i;
	return (ft_width2(i, data));
}
