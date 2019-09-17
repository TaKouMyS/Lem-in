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
		//printf("link %d to %d = %d\n", node, j, map[node][j]);
        if (map[node][j] == 1 && q->visited[j] == 0 && q->flow[node][j] < 1) //if there is a link and we have not visited the link
        {
		//	printf("link %d to %d\n", node, j);
     //   if (node == 5 && j == 4)
    //    {
    ///        printf("here53!\n\n");
   //     }
			q->queue[q->position] = j; // add to end of queue
            q->prev[j] = node; //note from which node we linked this node
			q->visited[j] = 1; //mark it as visited
            if (q->flow[node][j] == -1)
            {
			    q->flow[node][j] = 0;
			    q->flow[j][node] = 0;
            }
            ++q->position; //move up the end of queue marker
        }
        ++j; 
    }
    return (0);
}

void save_flow(t_queue *q, t_farm *f)
{
	int position; 

	position = f->end->id;
	while (position != f->start->id)
	{
		q->flow[position][q->prev[position]] = -1;
		q->flow[q->prev[position]][position] = 1;
		position = q->prev[position];
	}
}

int optimise_flow(t_farm *f, t_queue *q)
{
    int i;
    int node;

    i = -1;
    
    q->position = 1;
	i = 0;
	while (i < q->length)
	{
		q->visited[i] = 0;
		q->queue[i] = 0;
		++i;
	}
	i = -1;
	q->visited[f->start->id] = 1;
	q->queue[0] = f->start->id;
    while (++i < q->length && q->visited[f->end->id] != 1 && q->queue[i] >= 0)
    {
        node = q->queue[i]; //sets node to the next node in the queue
	//	printf("node = %d\n", node);
		find_neighbours(q, f->links, node);
    }
	//finding the same path twice, WHY????
    if (q->visited[f->end->id] != 1) //if while path finding we did not reach the end, we failed
		    return (-1);
	save_flow(q, f);
    return (0);
}