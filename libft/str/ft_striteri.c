/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:42:26 by amamy             #+#    #+#             */
/*   Updated: 2018/11/19 16:53:20 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t counter;

	counter = 0;
	if (s == NULL)
		return ;
	if (f == NULL)
		return ;
	while (s[counter] != '\0')
	{
		f(counter, &s[counter]);
		counter++;
	}
}
