/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwp_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:59:22 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 11:53:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_free_all: free and return or free, join and return the converted flag.
*/

static char		*ft_free_all(char *final, char *ap, char *for_s, int mode)
{
	char	*tmp;

	if (mode == 1 || mode == 0)
	{
		free(ap);
		if (mode == 0)
			free(final);
		return (NULL);
	}
	if (mode == 2)
	{
		tmp = final;
		if (!(final = ft_strjoin(for_s, tmp)))
			return (NULL);
		free(tmp);
		free(for_s);
		free(ap);
	}
	return (final);
}

/*
** ft_init_for_s: returns the converted flag. PRECIS + WIDTH on strings cases.
*/

static char		*ft_init_for_s(char *for_s, int a, int b, t_data *d)
{
	int		i;
	int		surplus;

	i = 0;
	surplus = (d->f & F_S_0) ? 0 : 1;
	if ((b >= a && a >= d->conv_sz) || (b < a && a >= d->conv_sz))
	{
		while (i < b - d->conv_sz)
			for_s[i++] = ' ';
	}
	if ((b >= a && a < d->conv_sz) || (b < a && a < d->conv_sz))
	{
		while (i < b - a)
			for_s[i++] = ' ';
	}
	return (for_s);
}

/*
** ft_init_wpm: Initialize data->width_precis_minus so we will know how much
** space or 0 is to be printed at the end of ret_conv in ft_flag_conv.
*/

static void		ft_init_wpm(int a, int b, char *ap, t_data *d)
{
	if (b > a)
		d->width_precis_minus = b - a;
	if (a >= b)
		d->width_precis_minus = b - d->conv_sz + 1;
	if (ap[0] == '\0' && b > a)
		d->width_precis_minus = b;
	if (ap[0] == '\0' && b <= a)
		d->width_precis_minus = a;
}

/*
** ft_init_final: deals with PRECIS + WIDTH on strings. Returns the final
** conversion.
*/

static char		*ft_init_final(int a, int b, char *ap, t_data *d)
{
	char	*final;

	if ((b <= a) || (b > a && a > d->conv_sz && !(d->f & F_S_0)) \
		|| (b > a && a < d->conv_sz && !(d->f & F_S_0)))
	{
		if (!(final = ft_strsub(ap, 0, a)))
			return (NULL);
	}
	else if (b > a && (d->f & F_S_0))
	{
		if (!(final = ft_strsub(ap, 0, b)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strdup("(null)")))
			return (NULL);
	}
	return (final);
}

/*
** ft_s: deals with PRECIS + WIDTH on strings. Returns the final conversion.
*/

char			*ft_s(char *final, int b, int a, t_data *d)
{
	char	*ap;
	char	*for_s;
	int		size;

	if (d->tmp_s)
	{
		if (!(ap = ft_strdup(d->tmp_s)))
			return (NULL);
		free(d->tmp_s);
	}
	else
	{
		if (!(ap = ft_strdup("(null)")))
			return (NULL);
		d->f |= F0;
	}
	free(final);
	if (!(final = ft_init_final(a, b, ap, d)))
		return (ft_free_all(final, final, final, 1));
	ft_init_wpm(a, b, ap, d);
	size = (b <= a) ? a : b;
	if (!(for_s = ft_memalloc(sizeof(char) * size + 1)))
		return (ft_free_all(final, final, final, 0));
	for_s = ft_init_for_s(for_s, a, b, d);
	return (ft_free_all(final, ap, for_s, 2));
}
