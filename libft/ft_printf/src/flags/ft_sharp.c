/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:26:20 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/23 21:52:56 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_ret_flag_sharp: Deals with special cases such as the flag SHARP + ZERO
** adding only 0 instead of 0x.
*/

char		*ft_ret_flag_sharp(char *ret_flag, char *f, int i)
{
	if (ft_strlen(ret_flag) < 2)
		return (ret_flag);
	ret_flag[0] = '0';
	ret_flag[1] = f[i];
	return (ret_flag);
}

/*
** ft_sharp: Deals with special cases such as the flag SHARP on x or X,
** adding 0x or 0X.
*/

char		*ft_sharp(int i, char *f, char *ret_flag, t_data *data)
{
	char	*tmp;

	tmp = ret_flag;
	if (f[i] == 'X' && !(data->f & F_X_0))
		if (!(ret_flag = ft_strjoin("0X", tmp)))
			return (NULL);
	if (f[i] == 'x' && !(data->f & F_X_0))
		if (!(ret_flag = ft_strjoin("0x", tmp)))
			return (NULL);
	if (data->f & F_X_0)
		return (ret_flag);
	free(tmp);
	return (ret_flag);
}
