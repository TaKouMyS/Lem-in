/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:28:17 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 13:37:06 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_next_p100_i: Gives the index of the next char '%'
*/

static int	ft_next_p100_i(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '%')
		i++;
	return (i);
}

/*
** ft_next_p100
** Return a string copied from the begining of str and finishing by the char
** preceeding its first '%' or by '\0' if no '%' found.
*/

char		*ft_next_p100(char *str, t_data *data)
{
	int		i;
	int		n_p100;
	char	*ret;

	i = 0;
	n_p100 = ft_next_p100_i(str);
	if (!(ret = ft_memalloc(sizeof(char) * (n_p100 + 1))))
		return (NULL);
	while (str[i] != '\0' && str[i] != '%')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		data->f |= B_DONE;
	return (ret);
}

/*
** ft_cat_conv: join previous format with new converted sentence
*/

static void	ft_cat_conv(t_data *data, char *str, int i)
{
	char	*tmp;
	char	*tmp2;

	if (!(tmp = ft_strdup(data->buf)))
		return ;
	if (!(tmp2 = ft_got_flag(&str[i], data)))
	{
		free(tmp);
		return ;
	}
	free(data->buf);
	if (!(data->buf = ft_strjoin(tmp, tmp2)))
	{
		free(tmp);
		free(tmp2);
		return ;
	}
	free(tmp);
	free(tmp2);
}

/*
** ft_cat_txt: join previous converted sentence with the rest of format
*/

static void	ft_cat_txt(t_data *data, char *str, int i)
{
	char	*tmp;
	char	*tmp2;

	if (!(tmp = ft_strdup(data->buf)))
		return ;
	free(data->buf);
	tmp2 = ft_next_p100(&str[i], data);
	if (!(data->buf = ft_strjoin(tmp, tmp2)))
		return ;
	free(tmp);
	free(tmp2);
}

/*
** ft_analyse : create the final sentence to be printed by joining different
** parts, all returned by multiples conversions (case where ft_analyse finds
** a %), or not (format).
*/

char		*ft_analyse(char *str, t_data *data)
{
	int		i;

	i = 0;
	data->conv_t_sz = 0;
	while (!(data->f & B_DONE))
	{
		if (str[i] == '%')
		{
			ft_cat_conv(data, &str[1], i);
			if (data->f & B_DONE)
				return (ft_free_then_return(data->buf));
			ft_disable_flag(data);
			if ((str[i] == '%') && (str[i + 1] == '%'))
				i += 2;
			else
				i += data->flag_sz + 1;
		}
		else if (str[i] != '%')
		{
			ft_cat_txt(data, str, i);
			i += ft_next_p100_i(&str[i]);
		}
	}
	return (data->buf);
}
