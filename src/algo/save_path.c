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

void mark_path(t_farm *f, t_queue *q, int i)
{
    int path;
    int j;

    j = 0; 
    path = q->prev[f->end->id];
    while (path != f->start->id) 
    {
        q->visited[path] = i;
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
        mark_path(f, q, i);
		++i;
    }
    return (i - 2);
}

t_list *save_paths(t_queue *q, t_farm *f)
{
	int *path;
    t_list *new;

 //   new->content = NULL;
   // new->content_size = 0;
	if (bfs(f, q) == -1)
		return (new);
	if (!(path = rev_path(f, q)))
			return (new);
    new->content = path;
    printf("end= %d\n", f->end->id);
 //   printf("entry here HERE?\n");
   // printf("STEPS %zu\n", count_steps(q, f->start->id, f->end->id));
    count_steps(q, f->start->id, f->end->id);
	return (new);
}

size_t count_steps(t_queue *q, int start, int end)
{
    int steps;

    steps = 0;
    printf("doI get hereeee? end =%d start =%d\n\n", end, start);
    while (end != start)
    {
        ft_printf("end = %d next = %d step = %zu\n", end, q->prev[end], steps);
        end = q->prev[end];
		++steps;
    }
  //  printf("steps = %zu", steps);
    return (steps);
}

int *rev_path(t_farm *f, t_queue *q)
{
    int *rev_path;
    int steps;
    int i;
    int pos;

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


  
