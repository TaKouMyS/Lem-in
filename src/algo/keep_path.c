#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

int keep_path(t_queue *q, t_farm *f, int *longest_path, int paths)
{
    int steps;
    int new_steps;
    int ants;
    int new_path = count_steps(q, f->start->id, f->end->id);

    if (longest_path[0] == 0)
    {
        longest_path[0] = new_path;
        return (1);
    }
    else
    {
        ants = f->ant_nb / paths;
        if (f->ant_nb <= 1)
            return (0);
        else
        {
            steps = longest_path[0] + ants - 1;
            new_steps = (f->ant_nb /(paths + 1)) + new_path - 1;
			if (new_steps < steps)
            {
                longest_path[0] = new_path;
				return (1);
            }
		}
		return (0);
	}   
}

/*
int keep_path(t_queue *q, t_farm *f, int *longest_path, int **paths)
{
  //  int steps;
   // int new_steps;
   // int ants;
   // int new_path = count_steps(q, f->start->id, f->end->id);
   int new_longest;
   int compare;
   int *divide;
   int i; 

   i = 0;
   new_longest = 0;
   divide = divide_ants(f, paths);
    if (longest_path[0] == 0)
        {
			longest_path[0] = count_steps(q, f->start->id, f->end->id) + divide[f->max_paths - 1];
			return (1);
		}
	else
	{
		while (i < f->max_paths)
		{
			if (new_longest < count_steps(q, f->start->id, f->end->id) + divide[i])
				new_longest = count_steps(q, f->start->id, f->end->id) + divide[i];
			++i;
		}
	}
	if (longest_path[0] < new_longest)
	{
		--f->max_paths;
		return (0);
	}
	longest_path[0] = new_longest;
	free(divide);
	return (1);
}
 
 /*   if (longest_path[0] == 0)
    {
        longest_path[0] = new_path;
        return (1);
    }
    else
    {
        ants = f->ant_nb / paths;
        if (f->ant_nb <= 1)
            return (0);
        else
        {
            steps = longest_path[0] + ants - 1;
            new_steps = (f->ant_nb /(paths + 1)) + new_path - 1;
			if (new_steps < steps)
            {
                longest_path[0] = new_path;
				return (1);
            }
		}
		return (0);
	}  */