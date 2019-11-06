/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:03:08 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 15:54:32 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_join_sharp: when we have to return | 0x34234|, we have to join 0x
** on the conversion and not the flag.
*/

static char		*ft_join_sharp(char *tmp, int mode)
{
	char	*final;

	if (mode == 1)
		if (!(final = ft_strjoin("0x", tmp)))
			return (NULL);
	if (mode == 2)
		if (!(final = ft_strjoin("0X", tmp)))
			return (NULL);
	return (final);
}

/*
** ft_hexa_is_0: when ap is 0, we have to return an empty string, or only a
** space or 0 depending on the flags.
*/

static char		*ft_hexa_is_0(char *final, t_data *d)
{
	d->f |= F_X_0;
	if ((d->f & F_SHARP) && !(d->f & F_PRECIS) && !(d->f & F_W_P))
	{
		free(final);
		if (!(final = (ft_strdup("0"))))
			return (NULL);
	}
	else if (d->f & F_SHARP || d->f & F_PRECIS)
	{
		free(final);
		if (!(final = (ft_strdup(""))))
			return (NULL);
	}
	else if ((d->f & F_SHARP || d->f & F_W_P) && !(d->f & F_PRECIS) \
		&& !(d->f & F_AP_0))
	{
		free(final);
		if (!(final = ft_strdup(" ")))
			return (NULL);
	}
	d->f &= ~F_C_0;
	return (final);
}

/*
** ft_hexa :
** Called from ft_only_conv for conv x ans X, mode 1 is x, mode 2 is X
*/

char			*ft_hexa(t_data *d, int mode)
{
	char	*final;
	char	*tmp;

	d->f |= F_UNSIGNED;
	d->f |= F_X;
	if (!(tmp = ft_conv_hhhlll_u(d, 16, mode)))
		return (NULL);
	if (!(d->f & F_C_0) && (d->f & F_SHARP) && !(d->f & F_PRECIS) \
		&& !(d->f & F_W_P) && !(d->f & F_ZERO))
	{
		if (!(final = ft_join_sharp(tmp, mode)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strdup(tmp)))
			return (NULL);
	}
	if (d->f & F_C_0)
		if (!(final = ft_hexa_is_0(final, d)))
			return (NULL);
	free(tmp);
	d->conv_sz = ft_strlen(final);
	return (final);
}
