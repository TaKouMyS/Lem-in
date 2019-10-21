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


#include "lem-in.h"
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

int check_flow(t_path *path, t_queue *q, int end)
{
    int i; 

    i = 0;
    while (path->path[i] != end)
    {
        if (q->flow[path->path[i]][path->path[i + 1]] == 0)
                return (0);
        if (q->visited[path->path[i]] == 1 && i != 0)
        {
            while (--i >= 0)
                q->visited[path->path[i]] = 0;
            return (0);
        }
        ++i;
    }
    return (1);
}

int duplicate_path(t_path *path, t_path *path_list, int end)
{
    t_path *tracker;
    int count;
    int i;

    count = 0;
    i = 0;
    tracker = path_list;
    while (tracker != NULL && tracker->path != NULL)
    {
        i = 0;
        if (tracker->len == path->len)
        {
            while (tracker->path[i] == path->path[i])
            {
             if (tracker->path[i] == end && path->path[i] == end)
                ++count;
            if (count > 1)
                return (1);
             if (tracker->path[i] == end || path->path[i] == end)
                break;
            ++i;
            }
        }
        tracker = tracker->next;
    }
    return (0);
}

t_path *clean_path(t_path *path_list)
{
   if (path_list->path == NULL && path_list->next->path != NULL)
		{
            path_list->next->max = path_list->max;
            path_list->next->division = path_list->division;
            path_list->next->longest = path_list->longest;
            path_list = path_list->next;
            path_list->prev = NULL;
        }
    
	return (path_list);
}

t_path *verify_paths(t_farm *f, t_queue *q, t_path *path_list)
{
   	t_path *path;
    t_path *tmp;
	int i;
	size_t j;

	i = 0;
    clear_queue(q);
    set_to_n(&q->visited, q->length, 0);
//	path = path_list;
 /*   while (path != NULL && path->path != NULL)
	{
      if (check_flow(path, q, f->end->id) == 0 || duplicate_path(path, path_list, f->end->id) == 1)
        {
            if (path->prev != NULL)
            {
              path->prev->next = path->next;
              tmp = path->prev;
           //    free(path->path);
             //  free(path);
               path = tmp;
            }
            else
            {
                path_list = path->next;
                path_list->prev = NULL;
                free(path->path);
                free(path);
                path = path_list;
                --f->max_paths;
                continue;
            }
            --f->max_paths;
        }    
		++i;
        path = path->next;
        
	}*/
    return (path_list);
}