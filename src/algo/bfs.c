#include <stdlib.h>
#include <stdio.h>

typedef struct			s_queue
{
	int	    			*queue;
	int					*prev;
	int         		*visited;
    int                 length;
    int                 position;
}						t_queue;

int     initialise_set_to_n(int **set, int length, int n)
{
    int i;

    i = -1;
    if (!(*set = malloc(sizeof(int) * length)))
        return (-1);
    while (++i < length)
         *set[0] = n;
    return (0);
}
 
 int initialise_queue(t_queue *q, int length, int start)
 {
    q->length = length;
    if ((initialise_set_to_n(&q->queue, length, -1)) < 0)
        return (-1);
    if ((initialise_set_to_n(&q->prev, length, -1)) < 0)
        return (-1);
    if ((initialise_set_to_n(&q->visited, length, 0)) < 0)
        return (-1);
    q->queue[0] = start;
    q->visited[start] = 1;
    q->position = 1;
    return (0);
 }

int find_neighbours(t_queue *q, int **map, int node)
{
    int j;

    j = 0;
    while (j < q->length)
    {
       
        if (map[node][j] == 1 && q->visited[j] == 0)
         {   
             q->queue[q->position] = j;
             q->prev[j] = node;
             q->visited[j] = 1;
             ++q->position;
         }
         ++j; 
    }
    return (0);
}

int fill_path(int **map, t_queue *q, int start, int end)
{
    int i;
    int node;

    i = -1;
    while (++i < q->length && q->visited[end] != 1)
    {
        node = q->queue[i];
        find_neighbours(q, map, node);
    }
    if (q->visited[end] != 1)
        return (-1);
    return (0);
}
int count_steps(t_queue *q, int start, int end)
{
      int steps;

    steps = 0;
    while (end != start)
    {
        end = q->prev[end];
        ++steps;
    }
    return (steps);
}

int print_path(t_queue *q, int start, int end)
{
    int *rev_path;
    int steps;
    int i;

    steps = count_steps(q, start, end);
    i = 1;
    if (!(rev_path = malloc(sizeof(int) * steps)))
        return (-1);
    rev_path[steps] = end;
    while (i < steps)
    {
        rev_path[steps - i] = q->prev[end];
        end = q->prev[end];
        ++i;
    }
    i = 0;
    while (i < steps)
    {
        printf("%d to %d\n", rev_path[i], rev_path[i + 1]);
        ++i;
    }
    return (0);
  
}

int     solve(int **map, int length, int start, int end)
{
    t_queue q;

    if ((initialise_queue(&q, length, start)) < 0)
        return (-1);
    if ((fill_path(map, &q, start, end)) < 0)
    {
        printf("Path not found\n");
            return (0);
    }
    if (!(print_path(&q, start, end)))
        return (0);
    return (0);
}

int **create_matrix(int **map)
{
    int i;
    int j;
    int *cpy;
    int matrice[7][7] =
    {
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0},
        {1, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 1, 0}
    };

    i = 0;
    if (!(*map = malloc(sizeof(int*) * 7)))
        return (0);
    while (i < 7)
    {
        j = 0;
        if (!(map[i] = malloc(sizeof(int) * 7)))
            return (0);
        while (j < 7)
        {   
            map[i][j] = matrice[i][j];
            ++j;
        }
        ++i;
    }
    return (map);
}

int main()
{
    int **map;
    map = create_matrix(map); //this is just so the rest of the functions work well with dynamically allocated matrices

    solve(map, 7, 0, 6);
    return (0);
}
