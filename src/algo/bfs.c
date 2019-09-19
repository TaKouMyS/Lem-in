#include <stdlib.h>
#include <stdio.h>
#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"

int find_neighbours(t_queue *q, int **map, int node)
{
    int j;

    j = 0;                                                                                                                                                    
    while (j < q->length)
    {
        if (map[node][j] == 1 && q->visited[j] == 0 && q->flow[node][j] == 1) //if there is a link and we have not visited the link
        {
			q->queue[q->position] = j; // add to end of queue
            q->prev[j] = node; //note from which node we linked this node
			q->visited[j] = 1; //mark it as visited
            ++q->position; //move up the end of queue marker
        }
        ++j; 
    }
    return (0);
}

int bfs(t_farm *f, t_queue *q)
{
    int i;
    int node;

    i = -1;  
	set_to_n(&q->queue, q->length, 0); //empty the queue
	reset_queue(q, f->start->id, f->end->id);
    while (++i < q->length && q->visited[f->end->id] != 1 && q->queue[i] >= 0)
    {
        node = q->queue[i]; //sets node to the next node in the queue
		find_neighbours(q, f->links, node);
    }
    if (q->visited[f->end->id] != 1) //if while path finding we did not reach the end, we failed
		    return (-1);
    return (0);
}
