/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_mode1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:14:31 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 15:55:51 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_s_fwp: deals with cases such as %8.5s --> accuracy + width.
*/

static char		*ft_s_fwp(char *flag, char *ap, t_data *data)
{
	char	*final;
	char	*tmp;
	char	*ret_width;

	data->ap_sz = ft_precision_s(flag, data);
	if (!(final = ft_strsub(ap, 0, data->ap_sz)))
		return (NULL);
	if (!(ret_width = ft_width_s(flag, data)))
		return (NULL);
	tmp = final;
	if (!(final = ft_strjoin(ret_width, tmp)))
		return (NULL);
	free(tmp);
	free(ret_width);
	return (final);
}

static char		*ft_string_mode1_2(char *flag, char *ap, t_data *data)
{
	char	*final;

	if (data->f & F_PRECIS && !(data->f & F_W_P))
	{
		if (!(data->ap_sz = ft_precision_s(flag, data)))
			return (NULL);
		if (!(final = ft_strsub(ap, 0, data->ap_sz)))
			return (NULL);
	}
	if (data->f & F_WIDTH && !(data->f & F_W_P))
		if (!(final = ft_s_width(flag, ap, data)))
			return (NULL);
	if (data->f & F_W_P)
		if (!(final = ft_s_fwp(flag, ap, data)))
			return (NULL);
	free(ap);
	return (final);
}

char			*ft_free_then_return(char *ap)
{
	free(ap);
	return (NULL);
}

/*
** ft_string_mode 1: mode 1 is called with flags such as precision or width.
*/

char			*ft_string_mode1(char *flag, t_data *data)
{
	char	*ap;
	char	*final;

	if (data->tmp_s)
	{
		if (!(ap = ft_strdup(data->tmp_s)))
			return (NULL);
		free(data->tmp_s);
	}
	else
	{
		if ((data->f & F_WIDTH) && !(data->f & F_W_P))
			return (ft_width_s(flag, data));
		else if (data->f & F_PRECIS && (data->f & F_W_P))
			return (ft_strsub("(null)", 0, ft_precision_s(flag, data)));
		else
		{
			if (!(ap = ft_strdup("(null)")))
				return (NULL);
		}
	}
	if (!(final = ft_string_mode1_2(flag, ap, data)))
		return (ft_free_then_return(ap));
	data->f |= F_S;
	return (final);
}
