#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

void mark_path(t_farm *f, t_queue *q, int i)
{
    int path;
    int j;

    j = 0; 
    path = q->prev[f->end->id];
    while (path != f->start->id)
    {
        q->visited[path] = i; //mark path using int
        path = q->prev[path];
        
    }
//		printf("///////////");
    while (j < q->length)
    {
        if (q->visited[j] != i)
            q->visited[j] = 0;  //any nodes we have not used in the path but have visited we remark as unvisited/can be used for next path
        q->prev[j] = -1;
		q->queue[j] = -1;
	
	//	printf("%d ", q->visited[j]);
        ++j;
    }
	putchar('\n');
}

int max_flow(t_queue *q, t_farm *f)
{
    int i;

    i = 2;
    int j = 0;
	while (j < q->length)
	{
		q->visited[j] = 0;
		++j;
	}
    while ((bfs(f, q)) >= 0)
    {
        mark_path(f, q, i);
        ++i;
    }
	while (j < q->length)
	{
		q->visited[j] = 0;
		++j;
	}
    printf("max flow = %d\n", i - 2);
    return (i - 2);
}

int **save_paths(t_queue *q, t_farm *f, int flow)
{
	int **paths;
	int i;
	int j;

	i = 0;
	if (!(paths = ft_memalloc(sizeof(int *) * flow)))
		return (NULL);
	while (i < flow)
	{
		j = 0;
		if (bfs(f, q) == -1)
			return (0);
		if (!(paths[i] = rev_path(f, q)))
			return (NULL);
		mark_path(f, q, i + 2);
		while (paths[i][j] != f->end->id)
		{
			printf("%d ", paths[i][j]);
			++j;
		}
		printf("%d\n", paths[i][j]);
		++i;
	}
	return (paths);
}
void print_map(int **map, int length)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			printf("%d ", map[i][j]);
			++j;
		}
		putchar('\n');
		++i;
	}

}
int edmondskarp(t_queue *q, t_farm *f)
{
	int flow;
	int j = 0;
	int **paths;

	while ((optimise_flow(f, q)) >= 0)
	{
	//	print_map(q->flow, q->length);
		printf("\n\n");
	}
//	print_map(q->flow, q->length);
	  while (j < q->length)
    {
        q->visited[j] = 0;  //any nodes we have not used in the path but have visited we remark as unvisited/can be used for next path
        q->prev[j] = -1;
		q->queue[j] = -1;	
        ++j;
    }
	flow = max_flow(q, f);
//	paths = save_paths(q, f, flow);
	
//	send_ants(f, paths, flow, 0);
	return (0);
}
  