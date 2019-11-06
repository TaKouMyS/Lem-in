/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwp_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:20:28 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/23 21:53:00 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_minus_s2: Initialize data->width_precis_minus so we will know how much
** space or 0 is to be printed at the end of ret_conv in ft_flag_conv.
*/

static void		ft_minus_s2(int before, int after, t_data *data, int mode)
{
	if (mode == 1)
	{
		if (before > after && after >= data->conv_sz)
			data->width_precis_minus = before - data->conv_sz;
		else if (before > after && after < data->conv_sz)
			data->width_precis_minus = before - after;
		else if (after > before && after >= data->conv_sz)
			data->width_precis_minus = 0;
	}
	if (mode == 2)
	{
		if (after == before && after >= data->conv_sz)
			data->width_precis_minus = after - data->conv_sz;
		else if (after >= before && after < data->conv_sz)
			data->width_precis_minus = 0;
	}
}

/*
** ft_minus_s: deals with WIDTH + PRECIS + MINUS cases on strings.
** Initialize data->width_precis_minus so we will know how much space or 0
** is to be printed at the end of ret_conv in ft_flag_conv.
*/

static char		*ft_minus_s(int before, int after, char *final, t_data *data)
{
	char	*ap;

	if (data->f & TMP_S_M)
	{
		if (!(ap = ft_strdup(data->tmp_s)))
			return (NULL);
		free(data->tmp_s);
	}
	else
	{
		if (!(ap = ft_strdup("(null)")))
			return (NULL);
	}
	free(final);
	if (!(final = ft_strsub(ap, 0, after)))
		return (NULL);
	ft_minus_s2(before, after, data, 1);
	if (ap == '\0' && before > after && after >= data->conv_sz)
		data->width_precis_minus = before;
	else if (ap == '\0' && before <= after && after >= data->conv_sz)
		data->width_precis_minus = before;
	else
		ft_minus_s2(before, after, data, 2);
	free(ap);
	return (final);
}

/*
** ft_else: deals with ap is not negative. WIDTH + PRECIS + MINUS cases.
** Return the converted flag.
*/

static char		*ft_else(char *final, int before, int after, t_data *data)
{
	int		surplus;
	int		i;

	surplus = 0;
	i = 0;
	if (data->f & F_PLUS)
	{
		surplus = 1;
		final[i++] = '+';
	}
	while (i < after - data->conv_sz + surplus)
		final[i++] = '0';
	final[i] = '\0';
	if (before > after)
		data->width_precis_minus = before - i - data->conv_sz;
	return (final);
}

/*
** ft_flag_minus: WIDTH + PRECIS + MINUS cases. Return the converted flag.
** if it is %s, calls ft_minus_s dealing with string cases.
*/

char			*ft_flag_minus(int before, int after, char *final, t_data *data)
{
	int		i;

	i = 0;
	if (data->f & F_S)
	{
		if (!(final = ft_minus_s(before, after, final, data)))
			return (NULL);
	}
	else
	{
		if (data->f & AP_NEG && !(data->f & F_UNSIGNED))
		{
			final[i++] = '-';
			while (i < after - data->conv_sz + 1)
				final[i++] = '0';
			final[i] = '\0';
			if (after == 0)
				data->width_precis_minus = 0;
		}
		else
			ft_else(final, before, after, data);
	}
	return (final);
}
