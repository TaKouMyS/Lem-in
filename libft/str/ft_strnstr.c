/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:29:33 by amamy             #+#    #+#             */
/*   Updated: 2018/11/23 12:10:45 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	cnt;
	size_t	ndl_c;

	cnt = 0;
	ndl_c = 0;
	if (ndl[0] == '\0')
		return ((char*)hay);
	while (hay[cnt] && cnt < len)
	{
		ndl_c = 0;
		while (hay[cnt + ndl_c] == ndl[ndl_c] && (cnt + ndl_c) < len)
		{
			ndl_c++;
			if (ndl[ndl_c] == '\0')
				return (((char*)&hay[cnt]));
		}
		cnt++;
	}
	return (NULL);
}
