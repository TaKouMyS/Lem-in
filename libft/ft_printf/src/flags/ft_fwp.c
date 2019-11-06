/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:56:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 17:32:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_calculate_size: calculates the needed size for final's malloc.
*/

static int		ft_calculate_size(int before, int after, t_data *data)
{
	int		size;

	if (before > after)
		size = before;
	if (after >= before)
		size = after;
	if (size < data->ap_sz)
		size = data->ap_sz;
	if (data->f & AP_NEG || data->f & F_PLUS)
		size++;
	if (after == 0)
		size++;
	return (size);
}

/*
** ft_preci_width3: calls the appropriate function depending on which
** cases we are: when the flag minus is on, when width > accuracy, etc...
*/

static char		*ft_preci_width3(int b, int a, t_data *d)
{
	int		i;
	char	*final;
	int		size;

	i = 0;
	size = ft_calculate_size(b, a, d);
	if (!(final = ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	if (!a && !b && (d->f & F_O || (d->f & F_X \
		&& !(d->f & F_SHARP))) && d->f & F_AP_0)
		d->f |= F_W_P_0;
	if (d->f & F_MINUS)
		final = ft_flag_minus(b, a, final, d);
	else if ((b == a || b < a) && !(d->f & F_SHARP))
	{
		if (d->f & F_S)
			return (ft_s(final, b, a, d));
		final = ft_case1(final, i, a, d);
	}
	else if (a < d->conv_sz && b > a && !(d->f & F_SHARP && d->f & F_X))
		final = ft_case2(final, b, a, d);
	else if ((a >= d->ap_sz && b > a) \
		|| (a == d->conv_sz) || d->f & F_SHARP)
		final = ft_case3(final, b, a, d);
	return (final);
}

/*
** ft_preci_width2: analyse what is before the '.' and what is after. Converts
** them in 2 int to send to preci_width3 which will apply the flag effect.
*/

static char		*ft_preci_width2(char *flag, t_data *data, int i, int j)
{
	char	*final;
	char	*before;
	char	*after;

	if (!(before = ft_memalloc(sizeof(char) * data->flag_sz + 1)))
		return (NULL);
	if (!(after = ft_memalloc(sizeof(char) * data->flag_sz + 1)))
		return (NULL);
	while ((flag[i] < '0' || flag[i] > '9') && flag[i] != '\0')
		i++;
	while (flag[i] != '.' && flag[i] != '\0')
		before[j++] = flag[i++];
	j = 0;
	i++;
	while (flag[i + 1] != '\0')
		after[j++] = flag[i++];
	if (ft_strlen(flag) > 2 && j == 0)
		after[j++] = '0';
	i = ft_atoi(before);
	j = ft_atoi(after);
	free(before);
	free(after);
	if (!(final = ft_preci_width3(i, j, data)))
		return (NULL);
	return (final);
}

/*
** ft_preci_width: will return the converted flag.
*/

char			*ft_preci_width(char *flag, t_data *data)
{
	int		i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	if (!(final = ft_preci_width2(flag, data, i, j)))
		return (NULL);
	return (final);
}
