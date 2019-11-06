/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:24:50 by amamy             #+#    #+#             */
/*   Updated: 2018/11/16 13:35:31 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	counter;

	counter = 0;
	while (s1[counter] == s2[counter] && s1[counter] != '\0')
		counter++;
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}
