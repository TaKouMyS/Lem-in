/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwp_not_ap_neg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:56:36 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 17:29:46 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_sharp_x(char *final, int i, t_data *data)
{
	final[i++] = '0';
	if (data->f & F_BIG_X)
		final[i++] = 'X';
	else
		final[i++] = 'x';
	return (final);
}

/*
** ft_case3: Deals with cases where before > after and after >= data->conv_sz.
** When ap is not negative.
*/

char		*ft_not_ap_neg(int before, int after, char *final, t_data *d)
{
	int		i;
	int		surplus;

	surplus = 0;
	i = 0;
	surplus = (d->f & F_SHARP && !(d->f & F_X_0) && d->f & F_X) ? 2 : 0;
	surplus += (surplus != 0 && after < 2) ? 2 : 0;
	if (after + surplus == 0)
		before = before - d->conv_sz;
	while (before-- > (after + surplus))
		final[i++] = ' ';
	if (d->f & F_PLUS)
		final[i - 1] = '+';
	if (d->f & F_SHARP && !(d->f & F_X_0) && d->f & F_X)
	{
		final = ft_sharp_x(final, i, d);
		i += 2;
	}
	if (d->f & F_S_0 || d->f & F_S)
		while (after-- > d->conv_sz)
			final[i++] = ' ';
	else
		while (after-- > d->conv_sz)
			final[i++] = '0';
	return (final);
}
