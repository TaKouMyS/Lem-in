/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:24:02 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:20:47 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *str, int len)
{
	char	*newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + len + 1))))
		return (NULL);
	ft_bzero(newstr, ft_strlen(str) + len + 1);
	ft_strcpy(newstr, str);
	return (newstr);
}
