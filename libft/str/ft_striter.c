/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:29:46 by amamy             #+#    #+#             */
/*   Updated: 2018/11/19 15:01:41 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t counter;

	counter = 0;
	if (s == NULL)
		return ;
	if (f == NULL)
		return ;
	while (s[counter] != '\0')
	{
		(*f)(&s[counter]);
		counter++;
	}
}
