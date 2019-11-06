/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:19:57 by amamy             #+#    #+#             */
/*   Updated: 2019/04/23 22:33:11 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_accuracy_size :
** Gets the number given for accuracy in the format.
*/

int		ft_accuracy_size(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
		return (-1);
	while ((flags[i] < '0' || flags[i] > '9') && flags[i] != '\0')
		i++;
	while ((flags[i] >= '0' && flags[i] <= '9') && flags[i] != '\0')
	{
		while ((flags[i] == '.' || flags[i] == '*') && flags[i] != '\0')
			i++;
		while (flags[i] >= '0' && flags[i] <= '9' && flags[i] != '\0')
			conv[j++] = flags[i++];
	}
	if (conv[0] == '\0')
		i = 0;
	else
		i = ft_atoi(conv);
	free(conv);
	return (i);
}

/*
** ft_float_accuracy :
** Free different variables depend on conversion.
*/

char	*ft_float_accuracy(t_data *d, char *flag, t_float *ft)
{
	char	*final;
	char	*tmp;
	int		diff;
	int		i;
	int		len;

	len = ft_strlen(ft->s_deci_p);
	i = ft_accuracy_size(flag, d);
	if (i > len)
		diff = i - len;
	else
		diff = len - i;
	i = 0;
	if (!(final = ft_memalloc(sizeof(char) * (diff + 1))))
		return (NULL);
	while (diff-- > 0)
		final[i++] = '0';
	tmp = final;
	if (!(final = ft_strjoin(ft->s_deci_p, tmp)))
		return (NULL);
	free(tmp);
	return (final);
}

/*
** ft_free :
** Free different variables depend on conversion.
*/

void	ft_free(t_float *ft, int j, int m)
{
	if (m == 1)
	{
		free(ft->s_deci_p);
		free(ft->int_p);
	}
	if (m == 2)
	{
		free(ft->int_p);
		free(ft->s_deci_p);
		free(ft->str_deci_ar_cp);
	}
	free(ft->int_p);
	if (j > 0)
		free(ft->s_deci_p);
	if (j > 1)
		free(ft->str_deci_ar_cp);
	free(ft);
}

/*
** ft_missing_zeros :
** Ad missing 0 if necessary.
*/

char	*ft_missing_zeros(int len, t_float *ft)
{
	char	*final;
	char	*tmp;
	int		diff;
	int		i;

	diff = 6 - len;
	i = 0;
	if (!(final = ft_memalloc(sizeof(char) * (diff + 1))))
		return (NULL);
	while (diff-- > 0)
		final[i++] = '0';
	tmp = final;
	if (!(final = ft_strjoin(ft->s_deci_p, tmp)))
		return (NULL);
	free(tmp);
	return (final);
}

/*
** ft_ffinal :
** Concat decimal part, Adjust final return.
*/

char	*ft_ffinal(t_float *ft, t_data *data, char *flag, int j)
{
	char	*final;
	char	*tmp;
	int		len;

	if (data->f & F_PRECIS)
		ft_conv_f2_2(ft, data, flag, 2);
	len = (ft->s_deci_p) ? ft_strlen(ft->s_deci_p) : 0;
	if (len < 6 && !(data->f & F_PRECIS) && !(data->f & F_W_P))
	{
		tmp = ft->s_deci_p;
		if (!(ft->s_deci_p = ft_missing_zeros(len, ft)))
			return (NULL);
		free(tmp);
	}
	if (!(final = ft_strjoin(ft->int_p, ft->s_deci_p)))
	{
		ft_free(ft, 0, 2);
		return (NULL);
	}
	if (data->f & F_W_P)
		if (!(final = ft_float_w_a_width(final, ft, data)))
			return (NULL);
	ft_free(ft, j, 0);
	data->conv_sz = (final) ? ft_strlen(final) : 0;
	return (final);
}
