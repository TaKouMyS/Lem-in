/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwp_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:15:32 by amamy             #+#    #+#             */
/*   Updated: 2019/04/24 17:29:57 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_case3: Deals with cases where before > after and after >= data->conv_sz.
*/

char		*ft_case3(char *final, int before, int after, t_data *data)
{
	int		surplus;
	int		i;

	i = 0;
	surplus = 0;
	if (data->f & F_S)
		return (ft_s(final, before, after, data));
	if (!(data->f & AP_NEG))
	{
		if (!(final = ft_not_ap_neg(before, after, final, data)))
			return (NULL);
	}
	else if (data->f & AP_NEG)
	{
		while (before-- > after + 1)
			final[i++] = ' ';
		final[i++] = '-';
		while (after-- > data->conv_sz)
			final[i++] = '0';
	}
	return (final);
}

static char	*ft_case2_no_neg(char *final, int i, int after, t_data *data)
{
	if (data->f & F_AP_0 && after == 0)
	{
		data->f |= F0;
		final[i++] = ' ';
	}
	if (data->f & F_AP_0 && data->f & F_SHARP && data->f & F_O)
		final[i - 1] = '0';
	return (final);
}

/*
** ft_case2: Deals with cases where before > after and after < data->conv_sz.
*/

char		*ft_case2(char *final, int before, int after, t_data *data)
{
	int		i;

	i = 0;
	if (data->f & F_S)
		return (ft_s(final, before, after, data));
	if (data->f & AP_NEG)
	{
		while (i < before - data->conv_sz - 1)
			final[i++] = ' ';
		final[i++] = '-';
	}
	if (!(data->f & AP_NEG))
	{
		if (data->f & F_PLUS)
			final[i++] = '+';
		while (i < before - data->conv_sz)
			final[i++] = ' ';
		final = ft_case2_no_neg(final, i, after, data);
	}
	return (final);
}

/*
** ft_case1: Deals with cases where before == or < after.
*/

char		*ft_case1(char *final, int i, int after, t_data *data)
{
	if (data->f & AP_NEG)
	{
		final[i++] = '-';
		while (i < after - data->conv_sz + 1)
			final[i++] = '0';
	}
	else if (data->f & F_PLUS)
	{
		final[i++] = '+';
		while (i < after - data->conv_sz + 1)
			final[i++] = '0';
	}
	else
	{
		while (i < after - data->conv_sz)
			final[i++] = '0';
	}
	return (final);
}
