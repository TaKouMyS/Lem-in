/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:47:30 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 15:52:47 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_special_cases: Returns the converted flag. Deals with special cases such
** as the flag SHARP on x or X, adding 0x or 0X.
*/

char			*ft_special_cases(int i, char *f, t_data *d)
{
	char	*ret_flag;

	if (!(ret_flag = ft_which_flag(f, f[i], d)))
		return (NULL);
	if (d->f & F_SHARP && d->f & F_ZERO && !(d->f & F_PRECIS) \
		&& !(d->f & F_W_P) && (f[i] == 'x' || f[i] == 'X'))
		ret_flag = ft_ret_flag_sharp(ret_flag, f, i);
	else if (d->f & F_SHARP && d->f & F_ZERO && d->f & F_PRECIS \
		&& !(d->f & F_W_P) && (f[i] == 'x' || f[i] == 'X'))
		ret_flag = ft_sharp(i, f, ret_flag, d);
	else if (d->f & F_SHARP && d->f & F_PRECIS \
		&& !(d->f & F_W_P) && (f[i] == 'x' || f[i] == 'X'))
		ret_flag = ft_sharp(i, f, ret_flag, d);
	return (ret_flag);
}

/*
** ft_fwp_minus: in %-4.3s cases. WIDTH + PRECIS with MINUS. We have to return
** ret_conv + ret_flag.
*/

char			*ft_fwp_minus(char *final, t_data *data)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_memalloc(sizeof(char) * (data->width_precis_minus + 1))))
		return (NULL);
	while (i < data->width_precis_minus)
		ret[i++] = ' ';
	tmp = final;
	if (!(final = ft_strjoin(tmp, ret)))
		return (NULL);
	free(ret);
	free(tmp);
	return (final);
}

/*
** ft_free_return: free before return.
*/

static char		*ft_free_return(char *ret_c, char *ret_f, char *final, int m)
{
	if (m == 1 || m == 0)
	{
		if (m == 0)
			free(final);
		free(ret_f);
		return (NULL);
	}
	if (m == 2)
	{
		free(ret_c);
		free(ret_f);
	}
	return (final);
}

/*
** ft_for_minus: In cases of flag MINUS or flag SPACE + AP_NEG are activated.
** We have to return only the returned conversion. Deals with +- cases.
*/

char			*ft_for_minus(char *ret_conv, char *f, int i, t_data *d)
{
	char	*ret_flag2;
	char	*final;
	int		plus;

	plus = 0;
	if (d->f & AP_NEG && !(d->f & F_UNSIGNED) && (f[i] != 's' || f[i] != 'c'))
	{
		final = ret_conv;
		if (!(ret_conv = ft_strjoin("-", final)))
			return (NULL);
		free(final);
		plus = 1;
	}
	if (!(ret_flag2 = ft_width_minus(f, d)))
		return (NULL);
	if (d->f & F_PLUS && d->f & F_PLUS && plus != 1)
	{
		final = ret_conv;
		if (!(ret_conv = ft_strjoin("+", final)))
			return (ft_free_return(ret_conv, ret_flag2, final, 0));
		free(final);
	}
	if (!(final = ft_strjoin(ret_conv, ret_flag2)))
		return (ft_free_return(ret_conv, ret_flag2, final, 1));
	return (ft_free_return(ret_conv, ret_flag2, final, 2));
}
