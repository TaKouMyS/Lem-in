/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:24:50 by amamy             #+#    #+#             */
/*   Updated: 2019/04/24 15:56:26 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	counter;

	counter = 0;
	while (s1[counter] != '\0' && s2[counter] != '\0' \
	&& s1[counter] == s2[counter])
		counter++;
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}
