/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:47 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/29 01:58:37 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Here we calculate how many ants we will send per path using the formula
** (sum of steps of all paths + total number of paths) / number of paths
** - number of steps in current path. This is saved in the ant_div variable.
*/

static int	*calculate_divide(int *ant_div, t_farm *f, int total, int *steps)
{
	int		i;

	i = 0;
	total = (total + f->ant_nb) / f->max_paths;
	while (i < f->max_paths)
	{
		ant_div[i] = total - steps[i];
		++i;
	}
	return (ant_div);
}

/*
** This function divdes the remaining ants between the potential paths
** in a the least harmful way possible with regards to path length.
*/

static int	*split_remainder(int *ant_division, int remainder, t_path **paths)
{
	int		i;
	int		full;

	full = 0;
	while (remainder > 0)
	{
		i = 0;
		while (i < (*paths)->max)
		{
			if (ant_division[i] + 1 <= (*paths)->longest)
			{
				--remainder;
				++ant_division[i];
			}
			if (ant_division[i] >= (*paths)->longest)
				++full;
			if (full == (*paths)->max)
			{
				full = 0;
				++(*paths)->longest;
			}
			++i;
		}
	}
	return (ant_division);
}

/*
** The formula used to divide the ants can sometimes leave some stray
** ants left over. Here we get the sum of ants designated for all the
** paths, and compare it with the total ants we have. If there is a
** remainder we divide it out using the split remainder function.
*/

static int	*check_total_ants(int *ant_division, t_farm *f, t_path **paths)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < (*paths)->max)
	{
		total = total + ant_division[i];
		++i;
	}
	if (total < f->ant_nb)
		ant_division = split_remainder(ant_division, f->ant_nb - total, paths);
	return (ant_division);
}

/*
** Here we iterate through the steps variable, which contains the quantity
** of steps in each path, and add it to the quantity of ants designated
** for this path, and remove 1 for the first ant. This corresponds to the
** quantity of lines that will be printed by this path. We compare as
** we go along to find the longest path, and hence the length of our solution.
*/

static int	get_longest(int *ant_division, int *steps, int max)
{
	int		i;
	int		longest;

	i = -1;
	longest = 0;
	while (++i < max)
	{
		if (longest < steps[i] + ant_division[i] - 1)
			longest = steps[i] + ant_division[i] - 1;
	}
	return (longest);
}

/*
** Here our goal is to find the optimal quantity of ants to
** send down each path, in order to have the shortest possible
** solution.
*/

int			*divide_ants(t_farm *f, t_path *paths)
{
	int		*ant_division;
	int		*steps;
	int		total;

	total = 0;
	if (!(ant_division = (int *)ft_memalloc(sizeof(int) * paths->max)))
		return (NULL);
	f->max_paths = paths->max;
	if (paths->max == 1)
	{
		ant_division[0] = f->ant_nb;
		return (ant_division);
	}
	if ((steps = get_path_lengths(f, paths, &total)) == NULL)
		return (NULL);
	ant_division = calculate_divide(ant_division, f, total, steps);
	paths->longest = get_longest(ant_division, steps, paths->max);
	ant_division = check_total_ants(ant_division, f, &paths);
	paths->longest = get_longest(ant_division, steps, paths->max);
	ft_memdel((void*)&steps);
	return (ant_division);
}
