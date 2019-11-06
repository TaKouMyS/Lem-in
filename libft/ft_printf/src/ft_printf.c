/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/24 16:05:29 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_analyse_flag: checks if we need to analyse flags or simply do a conversion
*/

static char		*ft_analyse_flags(char *flags, t_data *data)
{
	int		len;
	char	*final;
	char	*ret_conv;
	int		i;

	i = 0;
	ret_conv = NULL;
	len = data->flag_sz;
	if (len == 1)
	{
		data->f |= ONLY_CONV;
		if (!(final = ft_only_conv(flags, data)))
			return (NULL);
		data->f &= ~ONLY_CONV;
	}
	else
	{
		len = ft_active_flag(i, flags, data);
		if (!(final = ft_flag_conv(flags, ret_conv, len, data)))
			return (NULL);
	}
	return (final);
}

/*
** ft_got_flag: returns the new converted sentence by calling ft_analyse_flags,
** %flagconv will be replaced by this new sentence.
*/

char			*ft_got_flag(char *str, t_data *data)
{
	int		x;
	char	*flags;
	char	*ret;

	x = 0;
	while (str[x] != 'c' && str[x] != 's' && str[x] != 'p' && str[x] != 'd' \
		&& str[x] != 'i' && str[x] != 'o' && str[x] != 'u' && str[x] != '%' \
		&& str[x] != 'x' && str[x] != 'X' && str[x] != 'f' \
		&& str[x] != 0)
		x++;
	data->flag_sz = (str[x] == '%' && str[x - 1] == '%') ? 1 : x + 1;
	if (!(flags = ft_strndup(str, data->flag_sz)))
		return (NULL);
	if ((ret = ft_search_forbidden_conv(flags)) == NULL)
	{
		data->f |= B_DONE;
		return (NULL);
	}
	if (ft_strchr(flags, '*') || (ret = ft_analyse_flags(flags, data)) == NULL)
	{
		free(flags);
		return (NULL);
	}
	free(flags);
	return (ret);
}

/*
** ft_print_char_0 :
** In case %c with value 0, need to print 0(non-printale]).
*/

static void		ft_print_char_0(t_data *d)
{
	int to_print;

	to_print = 1;
	ft_putstrn(d->buf, (d->index_0[to_print] + d->tmp));
	ft_putchar(0);
	while (d->index_0[0] - to_print > 0)
	{
		if (to_print + d->index_0[0] == 2)
			ft_putstr(&d->buf[d->index_0[to_print]]);
		else
		{
			ft_putstrn(&d->buf[d->index_0[to_print]],
				(d->index_0[to_print + 1] - d->index_0[to_print]));
			ft_putchar(0);
		}
		to_print++;
	}
	ft_putstr(&d->buf[d->index_0[to_print]]);
}

/*
** ft_print_format : print final sentence returned by ft_analyse.
*/

static int		ft_print_format(char *format, t_data *data)
{
	int		len;

	if (!(data->buf = ft_strnew(0)))
		return (-1);
	if ((data->buf = ft_analyse(format, data)) == NULL)
	{
		free(data->index_0);
		return (-1);
	}
	len = ft_strlen(data->buf);
	if (data->f & F_C_02)
	{
		len++;
		ft_print_char_0(data);
	}
	else
		ft_putstr(data->buf);
	free(data->index_0);
	free(data->buf);
	return (len);
}

/*
** ft_printf : if error returns -1, else return nb of printed caracters
*/

int				ft_printf(const char *format, ...)
{
	int			len;
	t_data		*data;

	if (format == NULL)
		return (0);
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	if (data->f & TMP_S_M)
		free(data->tmp_s);
	free(data);
	return (len);
}
