/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:50:10 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:19:25 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t counter;

	if (s == NULL)
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		ft_putchar_fd(s[counter], fd);
		counter++;
	}
	ft_putchar_fd('\n', fd);
}
