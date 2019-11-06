/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_len_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:38:37 by amamy             #+#    #+#             */
/*   Updated: 2019/03/14 22:32:10 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes an int and tells you how much space it would take if the number
** were in base X;
*/

int	ft_nb_len_base(long value, int base)
{
	int	size;

	size = 0;
	if (value == 0 || value == -0)
		size = 1;
	if (value < 0)
		size++;
	while (value != 0)
	{
		value = value / (long)base;
		size++;
	}
	return (size);
}
