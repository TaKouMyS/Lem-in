
typedef struct			s_queue
{
	int	    			*queue;
	int					*prev;
	int         		*visited;
    int                 length;
    int                 position;
}						t_queue;

int     initialise_set_to_n(int *set, int length, int n)
{
    int i;

    i = -1;
    if (!(set = malloc(sizeof(int) * length)))
        return (-1);
    while (++i < length)
        set[i] = n;
    return (0);
}
 
 int intialise_queue(t_queue *q, int length, int start)
 {
    q->length = length;
    if ((initialise_set_to_n(q->queue, length, -1)) < 0)
        return (-1);
    if ((initialise_set_to_n(q->prev, length, -1)) < 0)
        return (-1);
    if ((initialise_set_to_n(q->visited, length, 0)) < 0)
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
    while (map[node][j] < q->length)
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
    while (++i <= q->length && q->visited[end] != 1)
    {
        node = q->queue[i];
        find_neighbours(q, node, map);
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
    i = 0;
    if (!(rev_path = malloc(sizeof(int) * steps)))
        return (-1);
    while (i <= steps)
    {
        rev_path[steps - i] = q->prev[end];
        end = q->prev[end];
        ++i;
    }
    i = 0;
    while (i <= steps)
    {
        printf("")
    }
  
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
    reverse_path(&q, start, end);






    

}