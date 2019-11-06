/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:58:13 by amamy             #+#    #+#             */
/*   Updated: 2018/11/20 15:29:09 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0' && i < (n - 1) && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
