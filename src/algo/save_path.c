/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:32:10 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/10 17:32:11 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem-in.h"
#include "libft.h"
#include <stdio.h>



void mark_path(t_farm *f, t_queue *q)
{
    int path;
    int j;

    j = 0; 
    path = q->prev[f->end->id];
    while (path != f->start->id) 
    {
        q->visited[path] = 2;
        path = q->prev[path];

    }
    while (j < q->length)
    {
        q->prev[j] = -1;
		q->queue[j] = -1;
        if (q->visited[j] == 1)
            q->visited[j] = 0;
        ++j;
    }
}

int count_paths(t_queue *q, t_farm *f)
{
    int i;
    int longest_path;

    i = 2;
    int j = 0;
    longest_path = 0;
	while (bfs(f, q) == 0)
    {
        if ((keep_path(q, f, &longest_path, i - 2)) == 0)
            break;
        mark_path(f, q);
		++i;
    }
    return (i - 2);
}

t_path **save_paths(t_queue *q, t_farm *f, t_path **path_list, int *longest)
{
	int *path;
    size_t steps;
    t_path *new;
    int i;

    i = 0;
    set_to_n(&q->visited, q->length, 0);
    reset_queue(q, f->start->id, f->end->id);
    while (bfs(f, q) == 0)
	{
   //   printf("bfs");
   //i = 0;
 //  if (keep_path(q, f, longest, f->max_paths + 1) == 1)
//{
        if (!(path = rev_path(f, q)))
		    return (path_list);
        steps = count_steps(q, f->start->id, f->end->id);
        mark_path(f, q);
        new = ft_new_path(path, steps);
      //  if ((*path_list)->content == NULL)
        //    ft_lstadd(path_list, new);
       // else
        ft_add_path(*path_list, new);
        ++f->max_paths;
//}
    //    printf("max = %d\n", f->max_paths);
    }
 //  putchar('\n');
    clear_queue(q);
	return (path_list);
}

size_t count_steps(t_queue *q, int start, int end)
{
    int steps;

    steps = 0;
    while (end != start)
    {
     //   printf("end = %d next = %d step = %zu\n", end, q->prev[end], steps);
        end = q->prev[end];
		++steps;
    }
    return (steps);
}

int *rev_path(t_farm *f, t_queue *q)
{
    int *rev_path;
    int steps;
    int i;
    int pos;

;
    pos = f->end->id;
   // printf("entry?");
    steps = count_steps(q, f->start->id, f->end->id); //count how many moves we made
    i = 0;
    if (!(rev_path = malloc((sizeof(int)) * (steps + 1))))
        return (NULL);
    rev_path[steps] = pos;
    while (i <= steps) //save the path reversed as it is currently stored from end to start
    {
        rev_path[steps - i] = pos;
        pos = q->prev[pos];
        ++i;
    }
    return (rev_path);
}