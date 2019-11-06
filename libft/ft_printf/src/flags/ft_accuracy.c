/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:51:16 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/23 22:29:27 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ft_accuracy_sup: write the good numbers of 0 in a string.
** Returns the converted flag.
*/

static char		*ft_accuracy_sup(int accuracy, char *ret, t_data *data)
{
	int		surplus;
	int		i;
	int		overage;

	i = 0;
	if (data->f & F_ZERO)
	{
		surplus = (data->f & AP_NEG && !(data->f & F_UNSIGNED)) ? 1 : 0;
		if (data->f & AP_NEG && !(data->f & F_UNSIGNED))
			ret[i++] = '-';
		while (i < accuracy - data->conv_sz - surplus)
			ret[i++] = '0';
	}
	if (!(data->f & F_ZERO))
	{
		if (data->f & AP_NEG && !(data->f & F_UNSIGNED))
			ret[i++] = '-';
		else if (data->f & F_PLUS)
			ret[i++] = '+';
		surplus = ((data->f & F_PLUS) && !(data->f & AP_NEG)) ? 1 : 0;
		overage = (data->f & AP_NEG && !(data->f & F_UNSIGNED)) ? 1 : 0;
		while (i < accuracy - data->conv_sz + surplus + overage)
			ret[i++] = '0';
	}
	return (ret);
}

/*
** ft_precision_d_else2: write the good numbers of 0 in a string and deals
** with +- cases. Returns the converted flag.
*/

static char		*ft_precision_d_else2(t_data *data, char *ret, int accuracy)
{
	if (!(ret = ft_memalloc(sizeof(char) * (accuracy + 1))))
		return (NULL);
	if (accuracy > data->conv_sz)
		ret = ft_accuracy_sup(accuracy, ret, data);
	if (accuracy <= data->conv_sz)
	{
		free(ret);
		if (data->f & AP_NEG && !(data->f & F_UNSIGNED))
			return (ft_strdup("-"));
		else if (data->f & F_PLUS && (data->f & AP_NEG))
			return (ft_strdup("-"));
		else if (data->f & F_PLUS && !(data->f & AP_NEG))
			return (ft_strdup("+"));
		return (ft_strdup(""));
	}
	return (ret);
}

/*
** ft_precision_d_else: convert .123 (precision numbers) in int.
*/

static int		ft_precision_d_else(char *flags, t_data *data)
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
		while (flags[i] == '.' || flags[i] == '*')
			i++;
		while (flags[i] >= '0' && flags[i] <= '9')
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
** ft_precision_d: convert .123 (precision numbers) in int by calling
** ft_precision_d_else, and then write the good numbers of 0 in a string
** with ft_precision_d_else2.
*/

char			*ft_precision_d(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	i = ft_precision_d_else(flags, data);
	conv = NULL;
	if (!i && data->f & F_AP_0 && data->f & F_X)
		data->f |= F_W_P_0;
	if (i < data->ap_sz)
	{
		if (data->f & AP_NEG)
			return (ft_strdup("-"));
		if (data->f & F_PLUS && !(data->f & AP_NEG))
			return (ft_strdup("+"));
		return (ft_strdup(""));
	}
	else
	{
		if (!(conv = ft_precision_d_else2(data, conv, i)))
			return (NULL);
	}
	return (conv);
}

/*
** ft_precision_s: returns a int which is the number of char to print.
*/

int				ft_precision_s(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	while ((flags[i] < '0' || flags[i] > '9') && flags[i] != '\0')
		i++;
	if (data->f & F_W_P)
	{
		while (flags[i] != '.')
			i++;
		i++;
	}
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
		return (0);
	while (flags[i] >= '0' && flags[i] <= '9' && flags[i] != '\0')
		conv[j++] = flags[i++];
	i = ft_atoi(conv);
	free(conv);
	if (i > data->ap_sz)
		return (data->ap_sz);
	else
		return (i);
}
