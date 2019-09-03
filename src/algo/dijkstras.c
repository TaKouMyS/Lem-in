/* Dijkstra's Algorithm in C */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int *fill_dist(int *dist, int length)
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

int node_is_linked(int i)
{
    return (i);
}

void check_minimum_distance(int current, int saved, int *dist, int *path)
{
    if (dist[current] + 1 < dist[saved])
    {
        
        dist[saved] = dist[current] + 1;
        path[saved] = current;
    }
}

void print_reversed_path(int *path, int length)
{
    while (length != 0)
    {
        printf("%d to %d\n", length, path[length]);
        length = path[length];
    }
}
   
int dijsktra(int map[][7], int length)
{
    int *distance;
    int *path;
    int i = -1;
    int j;

    if (!(path = malloc(sizeof(int) * length)))
        return (-1);
    if ((distance = fill_dist(distance, length)) == NULL)
        return (-1);
    while (++i < length)
    {
        j = -1;
        while(++j < length)
        {
            if (node_is_linked(map[i][j]))
                check_minimum_distance(i, j, distance, path);
        }
    }
    print_reversed_path(path, length - 1);
    return (0);
}

int main()
{
    int map[7][7] = 
    {
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0},
        {1, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 6}
    };
    int *path;


    /*
    int cost[N][N],i,j,w,ch,co;
    int source, target,x,y;
    printf("\t The Shortest Path Algorithm ( DIJKSTRA'S ALGORITHM in C \n\n");
    for(i=1;i< N;i++)
    for(j=1;j< N;j++)
    cost[i][j] = IN;
    for(x=1;x< N;x++)
    {
        for(y=x+1;y< N;y++)
        {
            printf("Enter the weight of the path between nodes %d and %d: ",x,y);
            scanf("%d",&w);
            cost [x][y] = cost[y][x] = w;
        }
        printf("\n");
    }
    printf("\nEnter the source:");
    scanf("%d", &source);
    printf("\nEnter the target");
    scanf("%d", &target); */
    dijsktra(map, 7);
    // printf("\nThe Shortest Path: %d",path);
}


    
    /*
    for(i=1;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    printf("%s", path);
    return dist[target];
    */
