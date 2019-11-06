/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:27:48 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 15:55:08 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_active_cast: active needed format flags for h, hh, l, ll.
*/

static void		ft_active_cast(char *flag, t_data *data, int i)
{
	int	len;

	len = ft_strlen(&flag[i]);
	if (flag[i] == 'h' && flag[i + 1] == 'h' && len == 3 \
		&& (!(data->f & F_H)))
		data->f |= F_HH;
	else if (flag[i] == 'h' && len == 2 && (!(data->f & F_HH)))
		data->f |= F_H;
	else if (flag[i] == 'l' && len == 2 && (!(data->f & F_LL)))
		data->f |= F_L;
	else if (flag[i] == 'l' && flag[i + 1] == 'l' && len == 3 \
		&& (!(data->f & F_L)))
		data->f |= F_LL;
}

/*
** ft_active_flag2: Enable needed flags.
** F_PERCENT --> for ft_printf("%323%"); cases.
*/

static void		ft_active_flag2(char *flag, t_data *data, int i)
{
	if (flag[i] == ' ')
		data->f |= F_SPACE;
	else if (flag[i] == '#')
		data->f |= F_SHARP;
	else if (flag[i] == '+')
		data->f |= F_PLUS;
	else if (flag[i] == '-')
		data->f |= F_MINUS;
	else if (flag[i] == '%')
		data->f |= F_PERCENT;
	else if (flag[i] == 'h' || flag[i] == 'l')
		ft_active_cast(flag, data, i);
	else if (flag[i] == 'L')
		data->f |= F_BIG_L;
}

/*
** ft_not_going_together: some flags don't work together, so some are disabled
** here in such cases.
*/

static void		ft_not_going_together(char f, t_data *data)
{
	if (data->f & F_ZERO && data->f & F_MINUS)
		data->f &= ~F_ZERO;
	if ((f == 'c' || f == 'u') && data->f & F_SPACE)
		data->f &= ~F_SPACE;
	if ((f == 'u') && data->f & F_PLUS)
		data->f &= ~F_PLUS;
	if ((f == 'c') && data->f & F_PRECIS)
		data->f &= ~F_PRECIS;
}

/*
** ft_active_flag: Analyses between % and the conversion, enable needed flags.
** F_W_P: active flag width + accuracy (ex: %5.2d)
*/

int				ft_active_flag(int i, char *f, t_data *data)
{
	while (f[i] != 'd' && f[i] != 'c' && f[i] != 's' && f[i] != 'p' \
		&& f[i] != 'x' && f[i] != 'o' && f[i] != 'x' && f[i] != 'X' \
		&& f[i] != 'i' && f[i] != 'f' && f[i] != 'u' && f[i] != 'C' \
		&& f[i] != '\0')
	{
		if ((f[i] == '0' && i == 0) || (f[i] == '0' && (f[i - 1] < '0' \
			|| f[i - 1] > '9')))
			data->f |= F_ZERO;
		if (f[i] == '.' && (data->f & F_WIDTH))
			data->f |= F_W_P;
		else if (((f[i] >= '0' && f[i] <= '9') || f[i] == '*')
			&& !(data->f & F_PRECIS))
			data->f |= F_WIDTH;
		else if (f[i] == '.')
			data->f |= F_PRECIS;
		else
			ft_active_flag2(f, data, i);
		i++;
	}
	ft_not_going_together(f[i], data);
	return (i);
}
