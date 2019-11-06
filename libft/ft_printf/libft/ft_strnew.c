/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:31:04 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:20:40 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
