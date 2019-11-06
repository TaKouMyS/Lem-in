/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:04:12 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 16:38:19 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_for_c_0: for %o conversions.
** when ap is 0, we have to return an empty string, or only a
** space or 0 depending on the flags.
*/

static char		*ft_for_c_o(char *final, t_data *d)
{
	if (((d->f & F_SHARP) && ((d->f & F_PRECIS) || d->f & F_WIDTH)) \
		|| (d->f & F_SHARP && !(d->f & F_PRECIS) && !(d->f & F_WIDTH)))
	{
		free(final);
		if (!(final = (ft_strdup("0"))))
			return (NULL);
	}
	else if ((d->f & F_SHARP || d->f & F_PRECIS) && !(d->f & F_WIDTH))
	{
		free(final);
		if (!(final = (ft_strdup(""))))
			return (NULL);
	}
	else if (d->f & F_SHARP)
	{
		free(final);
		if (!(final = (ft_strdup(" "))))
			return (NULL);
	}
	d->f &= ~F_C_0;
	return (final);
}

/*
** ft_octal: deals with %o cases.
*/

char			*ft_octal(t_data *d)
{
	char	*final;
	char	*tmp;

	d->f |= F_UNSIGNED;
	d->f |= F_O;
	if (!(tmp = ft_conv_hhhlll_u(d, 8, 1)))
		return (NULL);
	if ((d->f & F_SHARP) && !(d->f & F_C_0))
	{
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strdup(tmp)))
			return (NULL);
	}
	if (d->f & F_C_0)
	{
		if (!(final = ft_for_c_o(final, d)))
			return (NULL);
	}
	d->conv_sz = ft_strlen(final);
	free(tmp);
	return (final);
}
