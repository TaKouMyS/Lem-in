#include <stdlib.h>
#include <stdio.h>
#include "../../includes/lem-in.h"


int initialise_set_to_n(int **set, int length, int n)
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
    q->length = length;
    if ((initialise_set_to_n(&q->queue, length, -1)) < 0) // initialise to minus one to avoid confusion with 0 position
        return (-1);
    if ((initialise_set_to_n(&q->prev, length, -1)) < 0) // snap
        return (-1);
    if ((initialise_set_to_n(&q->visited, length, 0)) < 0) // set to 0 to mark all as unvisited
        return (-1);
    q->queue[0] = start; //first element in queue is the start of path
    q->visited[start] = 1; //mark start as visited
    q->position = 1; //we have one item in the queue
    return (0);
 }

int find_neighbours(t_queue *q, int **map, int node)
{
    int j;

    j = 0;
    while (j < q->length)
    {
        if (map[node][j] == 1 && q->visited[j] == 0) //if there is a link and we have not visited the link
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

int fill_path(int **map, t_queue *q, int end)
{
    int i;
    int node;

    i = -1;
    while (++i < q->length && q->visited[end] != 1)
    {
        node = q->queue[i]; //sets node to the next node in the queue
        find_neighbours(q, map, node); 
    }
    if (q->visited[end] != 1) //if while path finding we did not reach the end, we failed
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

int print_path(t_farm *f, t_queue *q, int start, int end)
{
    int *rev_path;
    int steps;
    int i;

    steps = count_steps(q, start, end); //count how many moves we made
    i = 1;
    if (!(rev_path = malloc((sizeof(int)) * (steps + 1))))
        return (-1);
    rev_path[steps] = end;
    while (i <= steps) //save the path reversed as it is currently stored from end to start
    {
        rev_path[steps - i] = q->prev[end];
        end = q->prev[end];
        ++i;
    }
    i = 0;
    while (i < steps) //prints path -> this could all be divided into subfunctions to make it tidier
    {
        printf("L%s-L%s\n", f->id_table[rev_path[i]]->name, f->id_table[rev_path[i + 1]]->name);
        ++i;
    }
    return (0);
  
}
void    print_map(int **map, int length)
{
    int i;
    int j;

    i = 0;

    while (i < length)
    {
        j = 0;
        while (j < length)
        {
            printf("%d", map[i][j]);
            ++j;
        }
        putchar('\n');
        ++i;
    }
}
int     solve(t_farm *f, int length, int start, int end)
{
    t_queue q;

  //  print_map(map, length);
    if ((initialise_queue(&q, length, start)) < 0)
        return (-1);
    if ((fill_path(f->links, &q, end)) < 0)
    {
        printf("Path not found\n");
            return (0);
    }
    if (!(print_path(f, &q, start, end)))
        return (0);
    return (0);
}

//This is an unnecessary function in the long run, it's just to make the matrix dynamically allocated as the room links 
//will be dynamically allocated. 
/*int **create_matrix(int **map)
{
    int i;
    int j;
    int matrice[7][7] =
    {
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0}
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
    int **map = NULL;
    map = create_matrix(map); //this is just so the rest of the functions work well with dynamically allocated matrices

    solve(map, 7, 0, 6);
    return (0);
}
*/