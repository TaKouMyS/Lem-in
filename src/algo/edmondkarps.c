
#include <stdlib.h>
#include <stdio.h>
#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"

int find_neg_flow(t_queue *q, int **map, int node)
{
	int j; 

	j = 0;
	while (j < q->length)
    {
        if (map[node][j] == 1 && q->visited[j] == 0 && q->flow[node][j] == -1) //if there is a link and we have not visited the link
        {
			q->queue[q->position] = j; // add to end of queue
            q->prev[j] = node; //note from which node we linked this node
			q->visited[j] = 1; //mark it as visited
            ++q->position; //move up the end of queue marker
			return (1);
        }
        ++j; 
    }
	return (0);
}

int find_flow(t_queue *q, int **map, int node, int prev_flow)
{
    int j;

    j = 0;
//	if (prev_flow == 0)
	//	if (find_neg_flow(q, map, node) == 1)
	//		return (0);
    while (j < q->length)
    {
        if (map[node][j] == 1 && q->visited[j] == 0 && q->flow[node][j] != 1) //if there is a link and we have not visited the link
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

void save_flow(t_queue *q, t_farm *f)
{
	int p;
	int s;
	p = f->end->id;
	while (p != f->start->id)
	{
		s = q->prev[p];
        if (q->flow[p][s] == 0) //if there's no flow mark forward/reverse flow as 1/-1
        { 
			q->flow[p][s] = -1;
			q->flow[s][p] = 1;
		}                              	
        else if (q->flow[p][s] == -1 || q->flow[p][s] == 1) //if there is flow, neutralise to zero
        { 
			q->flow[p][s] = 0;
			q->flow[s][p] = 0;
		}
		p = s; //check next node
	}
}

int optimise_flow(t_farm *f, t_queue *q)
{
    int i;
    int node;
	int prev_flow;

    i = -1;
	clear_queue(q);
	reset_queue(q, f->start->id, f->end->id);
	prev_flow = 0;
    while (++i < q->length && q->visited[f->end->id] != 1 && q->queue[i] >= 0)
    {

        node = q->queue[i]; //sets node to the next node in the queue
	//	ft_printf("end = %d node = %d\n", f->end->id, node);
		if (i != 0)
			prev_flow = q->flow[q->prev[node]][node];
	//	printf("flow from %d to %d = %d\n", q->prev[node], node, prev_flow);
		find_flow(q, f->links, node, prev_flow);
    }
    if (q->visited[f->end->id] == 0) //if while path finding we did not reach the end, we failed
	    return(-1);
    return (0);
}

int edmondskarp(t_queue *q, t_farm *f, int ***paths)
{
	int max;
	int i;

	i = 0;
//	printf(" I AM HEREEEEE\n\n");
	while (optimise_flow(f, q) == 0)
		save_flow(q, f);
	reset_queue(q, f->start->id, f->end->id);
	if ((max = count_paths(q, f)) <= 0)
		return (-1);
	clear_queue(q);
	*paths = save_paths(q, f, max);
	return (max);
}