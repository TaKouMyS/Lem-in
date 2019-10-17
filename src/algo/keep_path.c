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
#include "libft.h"
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
    while (((int *)path->content)[i] != end)
    {
   //     ft_printf("from %d to %d = %d\n", ((int *)path->content)[i], ((int *)path->content)[i + 1], flow[((int *)path->content)[i]][((int *)path->content)[i + 1]]);
        if (flow[((int *)path->content)[i]][((int *)path->content)[i + 1]] == 0)
                return (0);
        ++i;
    }
 //   printf("HEREEEE\n?");
    return (1);
}

int duplicate_path(t_list *path, t_list *path_list, int end)
{
    t_list *tracker;
    int count;
    int i;

    count = 0;
    i = 0;
    tracker = path_list;
  //  ft_printf("HERE");
    while (tracker != NULL && tracker->content != NULL)
    {
   //    printf("HERE");
        i = 0;
        while(((int *)tracker->content)[i] == ((int *)path->content)[i])
         {
             if (((int *)tracker->content)[i] == end && ((int *)path->content)[i] == end)
                ++count;
            if (count > 1)
                return (1);
             if (((int *)tracker->content)[i] == end || ((int *)path->content)[i] == end)
                break;
            ++i;
         }
        tracker = tracker->next;
    }
    return (0);
}

t_list *clean_path(t_list *path_list, int max)
{
    if (max != 0)
    {
       while (path_list->content == NULL && path_list->next->content != NULL)
			path_list = path_list->next;
    }
	return (path_list);
}

t_list *verify_paths(t_farm *f, t_queue *q, t_list *path_list)
{
   	t_list *path;
    t_list *prev;
	int i;
	size_t j;

	i = 0;
    prev->content = NULL;
    clear_queue(q);
    path_list = clean_path(path_list, f->max_paths);
	path = path_list;
    while (path != NULL && path->content != NULL)
	{
      if (check_flow(path, q->flow, f->end->id) == 0 || duplicate_path(path, path_list, f->end->id) == 1)
        {
            if (prev->content != NULL)
            {
              prev->next = path->next;
               free(path->content);
                free(path);
                path = prev;
            }
            else
            {
                path_list = path->next;
                free(path->content);
                free(path);
                path = path_list;
                --f->max_paths;
                continue;
            }
            --f->max_paths;
        }    
		++i;
        prev = path;
        path = path->next;
        
	}
    return (path_list);
}