/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:38 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/10 17:31:39 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

int check_flow(t_list *path, int **flow, int end)
{
    int i; 

    i = 0;
    printf("am I here?");
    printf("%d\n\n", ((int *)path->content)[i]);
    while (((int *)path->content)[i] != end)
    {
        ft_printf("from %d to %d = %d", ((int *)path->content)[i], ((int *)path->content)[i + 1], flow[((int *)path->content)[i]][((int *)path->content)[i + 1]]);
        if (flow[((int *)path->content)[i]][((int *)path->content)[i + 1]] == 0)
            return (0);
        ++i;
    }
    putchar('\n');
    printf("HEREEEE\n?");
    return (1);
}

int duplicate_path(t_list *path, t_list *path_list)
{
    t_list *tracker;
    int count;

    count = 0;
    tracker = path_list;
    while (tracker != NULL)
    {
        if (ft_memcmp(tracker->content, path->content, tracker->content_size) == 0)
            ++count;
        if (count > 1)
            return (0);
        tracker = tracker->next;
    }
    return (1);
}

int verify_paths(t_farm *f, t_queue *q, t_list *path_list)
{
   	t_list *path;
    t_list *prev;
	int i;
	size_t j;

	i = 0;
	path = path_list;
    prev->content = NULL;
    clear_queue(q);
	while (path->content != NULL)
	{
      while (check_flow(path, q->flow, f->end->id)) //|| duplicate_path(path, path_list) == 1)
        {
            if (prev->content != NULL)
            {
                prev->next = path->next;
             //   free(path->content);
               // free(path);
                path = prev;
            }
            else
            {
                printf("HERE");
                path_list = &path->next;
              //creating a malloc se
               // free(path->content);
               // free(path);
                path = path_list;
                continue;
            }
        }
      
		++i;
        prev = path;
        path = path->next;
        
	}
    return (0);
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
