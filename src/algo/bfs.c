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

int bfs(t_farm *f, t_queue *q)
{
    int i;
    int node;

    i = -1;
    q->queue[0] = f->start->id;
    q->position = 1;
    while (++i < q->length && q->visited[f->end->id] != 1)
    {
        node = q->queue[i]; //sets node to the next node in the queue
        find_neighbours(q, f->links, node);
    }
    if (q->visited[f->end->id] != 1) //if while path finding we did not reach the end, we failed
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

int *rev_path(t_farm *f, t_queue *q)
{
    int *rev_path;
    int steps;
    int i;
    int end;

    end = f->end->id;
    steps = count_steps(q, f->start->id, end); //count how many moves we made
    i = 1;
    if (!(rev_path = malloc((sizeof(int)) * (steps + 1))))
        return (NULL);
    rev_path[steps] = end;
    while (i <= steps) //save the path reversed as it is currently stored from end to start
    {
        rev_path[steps - i] = q->prev[end];
        end = q->prev[end];
        ++i;
    }
    i = 0;
  //  print_path(f, rev_path, steps);
    return (rev_path);
}

int print_path(t_farm *f, int *path, int steps)
{
  int i; 
  int steps_taken;
  int moving;
  int finished;

  i = 1;
  finished = 0;
  steps_taken = 0;
  moving = 1;
  while (finished < f->ant_nb)
  {
    ++steps_taken;
    i = finished;
    while (i < moving)
    {
        printf("L%d-%s ", i + 1, f->id_table[path[steps_taken - i]]->name);
        if (path[steps_taken - i] == f->end->id)
            ++finished;
        //here some kind of thing like if there's another path -> Go there
        f->id_table[path[steps_taken -i]]->empty = 1;
        f->id_table[path[steps_taken - i - 1]]->empty = 0;
        ++i;
    }
    putchar('\n');
    if (moving < f->ant_nb)
        ++moving;
    i = finished;
  } 
  return (0);
}

int     solve(t_farm *f, int length, int start, int end)
{
    t_queue q;

  //  print_map(map, length);
    if ((initialise_queue(&q, length, start)) < 0)
        return (-1);
        edmondskarp(&q, f);
 //   printf("%d\n", max_flow(&q, f));
  /*  if ((bfs(f->links, &q, end)) < 0)
    {
        printf("Path not found\n");
            return (0);
    }
    if (!(rev_path(f, &q, start, end)))
        return (0);*/
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