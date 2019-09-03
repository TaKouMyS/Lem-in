/* Dijkstra's Algorithm in C */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

static int *fill_dist(int *dist, int length)
{
    int i;

    i = 0;
    if (!(dist = malloc((sizeof(int)) * length)))
        return (NULL);
    while (++i < length)
        dist[i] = 1000;
    dist[0] = 0;
    return (dist);
}

static int node_is_linked(int i)
{
    return (i);
}

static void check_minimum_distance(int current, int saved, int *dist, int *path)
{
    if (dist[current] + 1 < dist[saved]) //checking if this distance from source of the linking node + an additional link is smaller than saved distance, as we're looking for the minimum path
    {
        
        dist[saved] = dist[current] + 1;
        path[saved] = current;
    }
}

static void print_reversed_path(int *path, int length)
{
    while (length != 0)
    {
        printf("%d to %d\n", length, path[length]);
        length = path[length];
    }
}
   
static int dijsktra(int map[][7], int length)
{
    int *distance;
    int *path;
    int i = -1;
    int j;

    if (!(path = malloc(sizeof(int) * length)))
        return (-1);
    if ((distance = fill_dist(distance, length)) == NULL) //filling distance with arbitary large numbers (1000 in this case), apart from the first element
        return (-1);
    while (++i < length)
    {
        j = -1;
        while(++j < length)
        {
            if (node_is_linked(map[i][j])) //this will be a 1 if theres a link or 0 if there's no link
                check_minimum_distance(i, j, distance, path);
        }
    }
    print_reversed_path(path, length - 1); //printing from the end backwards, because it's easier, but easy to fix if need be. 
    return (0);
}

int main()
{
    /*current way of dealing with links. taking a look at map[0] - the 1 at map[0][1] indicates there is a link between map[0] and map[1], the 0 at map[0][3] indicates no link between map[0] and map[3]
    This map translates to: 
      
         1   ----------3
      | \    \          \ 
      |  \    \          \
      |   \    \         6
      |    \    \        /
      |     \    \      / 
      |      \    \    /
      |       \    \  /
      0--------2-4--5/

      We're also working under the presumption that 0 is always start and that the last element of the map is always end.*/
    int map[7][7] = 
    {
        {0, 1, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 0, 1, 0},
        {1, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 6}
    };
    dijsktra(map, 7);
    return (0);
}


   
