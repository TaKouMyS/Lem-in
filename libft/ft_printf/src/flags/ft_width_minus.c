/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:12:44 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 15:25:21 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*ft_width_sup_convsz(int width, int i, int surplus, t_data *d)
{
	char	*ret;

	if (!(ret = ft_memalloc(sizeof(char) * ((width - d->conv_sz) + 1))))
		return (NULL);
	if (d->f & F_ZERO)
		while (i < width - d->conv_sz)
			ret[i++] = '0';
	if (!(d->f & F_ZERO))
		while (i < width - d->conv_sz - surplus)
			ret[i++] = ' ';
	return (ret);
}

/*
** ft_width_minus2 : Case of width + flag minus. Returns the converted flag.
*/

static char		*ft_width_minus2(int width, t_data *d)
{
	int		i;
	char	*ret;
	int		surplus;

	i = 0;
	if (d->f & TMP_S_M)
		free(d->tmp_s);
	surplus = (d->f & AP_NEG || (d->f & F_MINUS && d->f & F_PLUS)) ? 1 : 0;
	if (d->f & F_MINUS && d->f & F_ZERO)
		return (ft_strdup(""));
	if (width > d->conv_sz)
	{
		if (!(ret = ft_width_sup_convsz(width, i, surplus, d)))
			return (NULL);
	}
	else
		return (ft_strdup(""));
	if (d->f & F_PLUS && !(d->f & F_MINUS))
		ret[i++] = '+';
	return (ret);
}

/*
** ft_width_minus : Case of width + flag minus. Analyse the flag to convert it
** into a int which will be width. Sends it to ft_width_minus2.
*/

char			*ft_width_minus(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
		return (NULL);
	while (flags[i] == '+' || flags[i] < '0' || flags[i] > '9' \
		|| flags[i] == '-')
		i++;
	while (flags[i] >= '0' && flags[i] <= '9')
		conv[j++] = flags[i++];
	i = ft_atoi(conv);
	free(conv);
	return (ft_width_minus2(i, data));
}
