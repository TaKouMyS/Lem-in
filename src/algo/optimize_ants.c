/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:47 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/26 13:39:16 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

// UNUSED? TO BE REMOVE
// //count steps on saved path
// static int		count_path(int end, int *path)
// {
// 	int i;

// 	i = 0;
// 	while (path[i] != end)
// 		++i;
// 	return (i);
// }

//calculate ants to send on each path
static int *calculate_divide(int *ant_division, t_farm *f, int total, int *steps)
{
    int i;

    i = 0;
    total = (total + f->ant_nb) / f->max_paths;
	while (i < f->max_paths)
	{
		ant_division[i] = total - steps[i];
		++i;
	}
    return (ant_division);
}

//check that we have allocated all the ants, if there are leftovers add them to shorest
//path
int	*split_remainder(int *ant_division, int remainder, t_path **paths)
{
	int i;
	int full;
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

static int *check_total_ants(int *ant_division, t_farm *f, t_path **paths)
{
    int i;
    int total;

    i = 0;
    total = 0;
	while (i < (*paths)->max)
	{
	//	printf("i = %d divde = %d\n", i, ant_division[i]);
		total = total + ant_division[i];
		++i;
		
	}
	if (total < f->ant_nb)
		ant_division = split_remainder(ant_division, f->ant_nb - total, paths);
    return (ant_division);
}

//Save the length of each path, and the total length of all paths.
int     *get_path_lengths(t_farm *f, t_path *paths, int *total)
{
    int i;
    int *steps;
	t_path *path;

    i = 0;
	path = paths;
    if (!(steps = (int *)ft_memalloc(sizeof(int) * f->max_paths)))
        return (NULL);
    while (i < f->max_paths)
	{
		steps[i] = path->len;
		total[0] = total[0] + steps[i];
		++i;
		path = path->next;
	}
    return (steps);
}

int		get_longest(int *ant_division, int *steps, int max)
{
	int i;
	int longest;

	i = -1;
	longest = 0;
	while (++i < max)
		if (longest < steps[i] + ant_division[i] + 1)
			longest = steps[i] + ant_division[i] + 1;
	return (longest);

}
int		*divide_ants(t_farm *f, t_path *paths)
{
	int *ant_division;
	int i;
	int *steps;
	int total;

	i = 0;
	total = 0;
	//printf("%lu\n max = %d", sizeof(int) * f->max_paths, f->max_paths);
	if (!(ant_division = (int *)ft_memalloc(sizeof(int) * paths->max)))
		return (NULL);
	f->max_paths = paths->max;
    if ((steps = get_path_lengths(f, paths, &total)) == NULL)
        return (NULL);
	ant_division = calculate_divide(ant_division, f, total, steps);
    ant_division = check_total_ants(ant_division, f, &paths);
	paths->longest = get_longest(ant_division, steps, paths->max);
	ft_memdel((void*)&steps);
	return (ant_division);
}
