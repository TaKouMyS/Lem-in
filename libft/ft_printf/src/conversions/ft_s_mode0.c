/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_mode0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:14:00 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 12:32:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_string_mode0_2: In cases of flag MINUS is activated.
*/

static void		ft_stringmode0_2(char *ap, char *tmp, t_data *d, int mode)
{
	if (mode == 1)
	{
		if (tmp[0] == '\0')
			d->f |= F_S_0;
		d->conv_sz = ft_strlen(ap);
		d->ap_sz = ft_strlen(ap);
	}
	if (mode == 2)
	{
		if ((d->f & F_PRECIS || d->f & F_WIDTH) && (!(d->f & F_MINUS)))
		{
			d->f |= TMP_S_M;
			if (!(d->tmp_s = ft_strdup(ap)))
				return ;
		}
		else if (d->f & F_MINUS)
		{
			d->f |= TMP_S_M;
			if (!(d->tmp_s = ft_strdup(ap)))
				return ;
		}
	}
}

/*
** ft_string_mode0: mode 0 is called when there are no flags to deal with.
*/

static char		*ft_string_mode0(t_data *d)
{
	char	*ap;
	char	*tmp;

	tmp = va_arg(d->ap, char*);
	if (tmp != NULL)
	{
		if (!(ap = ft_strdup(tmp)))
			return (NULL);
	}
	else
	{
		d->ap_sz = 6;
		d->conv_sz = 6;
		return (ft_strdup("(null)"));
	}
	if (((d->f & F_PRECIS || d->f & F_WIDTH) && (!(d->f & F_MINUS))) \
		|| (d->f & F_MINUS))
		ft_stringmode0_2(ap, tmp, d, 2);
	ft_stringmode0_2(ap, tmp, d, 1);
	if ((d->f & F_PRECIS || d->f & F_WIDTH) && (!(d->f & F_MINUS)))
		free(ap);
	if ((d->f & F_PRECIS || d->f & F_WIDTH) && (!(d->f & F_MINUS)))
		if (!(ap = ft_strdup("")))
			return (NULL);
	return (ap);
}

/*
** ft_string: mode 0 is called when there is only a conversion to do, without
** flags. Mode 1 is called with flags such as precision or width.
*/

char			*ft_string(char *flag, t_data *data, int mode)
{
	char	*final;

	if (mode == 0)
		if (!(final = ft_string_mode0(data)))
			return (NULL);
	if (mode == 1)
		if (!(final = ft_string_mode1(flag, data)))
			return (NULL);
	return (final);
}
