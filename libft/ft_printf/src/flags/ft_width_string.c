/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:13:17 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 11:13:19 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_width_s : Deals with width in a %s case. Returns converted flag.
*/

static char		*ft_width_s2(int width, t_data *data)
{
	char	*ret;
	int		i;

	i = 0;
	if (width < data->ap_sz)
		return (ft_strdup(""));
	else
	{
		if (!(ret = ft_memalloc(sizeof(char) * (width - data->ap_sz + 1))))
			return (NULL);
		while (i < width - data->ap_sz)
		{
			ret[i] = ' ';
			i++;
		}
	}
	return (ret);
}

/*
** ft_width_s : Deals with width in a %s case. Analyse the flag to convert it
** into a int which will be width. Sends it to ft_width_s2.
*/

char			*ft_width_s(char *f, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	while (f[i] != '\0')
	{
		if (f[i] == '#')
			i++;
		if ((f[i] >= '0' && f[i] <= '9') || f[i] == '+' || f[i] == '-')
			conv[j] = f[i];
		i++;
		j++;
	}
	i = ft_atoi(conv);
	free(conv);
	data->f &= ~F_WIDTH;
	return (ft_width_s2(i, data));
}

/*
** ft_s_width: deals with cases such as %5s --> width only.
*/

char			*ft_s_width(char *flag, char *ap, t_data *data)
{
	char	*final;
	char	*ret_width;

	data->ap_sz = ft_strlen(ap);
	if (!(ret_width = ft_width_s(flag, data)))
		return (NULL);
	if (!(final = ft_strjoin(ret_width, ap)))
		return (NULL);
	free(ret_width);
	return (final);
}
