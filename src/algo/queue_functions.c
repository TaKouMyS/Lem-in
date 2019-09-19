#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

int set_to_n(int **set, int length, int n)
{
    int i;

    i = -1;
    if (!(set[0] = malloc(sizeof(int) * length)))
        return (-1);
    while (++i < length)
         set[0][i] = n;
    return (0);
}

int initialise_queue(t_queue *q, int length, int start)
 {
    int i;

    i = 0;
    q->length = length;
    if (!(q->queue = ft_memalloc(sizeof(int) * length)))
        return (-1);
    if (!(q->prev = ft_memalloc(sizeof(int) * length)))
        return (-1);
    if (!(q->visited = ft_memalloc(sizeof(int) * length)))
        return (-1);
    set_to_n(&q->queue, length, -1);
    set_to_n(&q->prev, length, -1);
    if (!(q->flow = ft_memalloc(sizeof(int *) * q->length)))
        return (-1);
    while (i < q->length)
    {
        if (!(q->flow[i] = ft_memalloc(sizeof(int) * q->length)))
            return (-1);
		++i;
    }
    reset_queue(q, start, -1);
    return (0);
 }

void reset_queue(t_queue *q, int start, int end)
{
    q->queue[0] = start; //first element in queue is the start of path
    q->visited[start] = 1; //mark start as visited
    q->position = 1; //we have one item in the queue
    if (end >= 0)      //if we don't need to restet end, we can give -1
        q->visited[end] = 0; 
}

 void clear_queue(t_queue *q)
{
	set_to_n(&q->visited, q->length, 0);
    set_to_n(&q->prev, q->length, -1);
    set_to_n(&q->queue, q->length, -1);
}