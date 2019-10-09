#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

//count steps on saved path
static int		count_path(int end, int *path)
{
	int i;

	i = 0;
	while (path[i] != end)
		++i;
	return (i);
}

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
static int *check_total_ants(int *ant_division, t_farm *f)
{
    int i;
    int total;

    i = 0;
    total = 0;
	while (i < f->max_paths)
	{
		total = total + ant_division[i];
		++i;
		
	}
	if (total < f->ant_nb)
		ant_division[0] = ant_division[0] + (f->ant_nb - total);
    return (ant_division);
}

//Save the length of each path, and the total length of all paths.
int     *get_path_lengths(t_farm *f, int **paths, int *total)
{
    int i;
    int *steps;

    i = 0;
    if (!(steps = (int *)malloc(sizeof(int) * f->max_paths)))
        return (NULL);
    while (i < f->max_paths)
	{
		steps[i] = count_path(f->end->id, paths[i]);
		total[0] = total[0] + steps[i];
		++i;
	}
    return (steps);
}

int		*divide_ants(t_farm *f, int **paths)
{
	int *ant_division;
	int i;
	int *steps;
	int total;

	i = 0;
	total = 0;
	//printf("%lu\n max = %d", sizeof(int) * f->max_paths, f->max_paths);
	if (!(ant_division = (int *)malloc(sizeof(int) * f->max_paths)))
		return (NULL);
    if ((steps = get_path_lengths(f, paths, &total)) == NULL)
        return (NULL);
	ant_division = calculate_divide(ant_division, f, total, steps);
    ant_division = check_total_ants(ant_division, f);
	return (ant_division);
}