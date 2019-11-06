/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:40:16 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 11:15:44 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		*ft_array_increase_size(t_data *data)
{
	int i;
	int	*tmp;

	i = 0;
	if (!(tmp = ft_memalloc(sizeof(int) * (data->index_0[0] + 1))))
		return (0);
	while (i <= data->index_0[0])
	{
		tmp[i] = data->index_0[i];
		i++;
	}
	free(data->index_0);
	if (!(data->index_0 = ft_memalloc(sizeof(int) * (tmp[0] + 2))))
		return (0);
	i = 0;
	while (i <= tmp[0])
	{
		data->index_0[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (data->index_0);
}

/*
** ft_char_0:
** Enables needed flag when ap == 0 and save the index of the character.
*/

static void		ft_char_0(t_data *data)
{
	int nb_0;

	nb_0 = 0;
	if (data->f & F_C_02)
	{
		if (!(data->index_0 = ft_array_increase_size(data)))
			return ;
		nb_0 = (data->index_0[0] + 1);
	}
	else
	{
		if (!(data->index_0 = ft_memalloc(sizeof(int) * 2)))
			return ;
		nb_0 = 1;
	}
	data->index_0[0] = nb_0;
	data->index_0[nb_0] = ft_strlen(data->buf);
	data->f |= F_C_02;
}

/*
** ft_char: Deals with %c conversion, enable needed flag when ap == 0.
*/

char			*ft_char(t_data *data)
{
	char	ap;
	char	*final;

	if (!(final = ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	ap = (va_arg(data->ap, int));
	data->ap_sz = 1;
	if (ap == 0)
	{
		data->f |= F_AP_0;
		final[0] = 0;
		final[1] = '\0';
		ft_char_0(data);
	}
	else
	{
		final[0] = ap;
		final[1] = '\0';
	}
	data->conv_sz = 1;
	return (final);
}
