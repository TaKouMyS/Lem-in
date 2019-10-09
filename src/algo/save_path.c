#include "lem-in.h"
#include "libft.h"
#include <stdio.h>

void mark_path(t_farm *f, t_queue *q, int i)
{
    int path;
    int j;

    j = 0; 
    path = q->prev[f->end->id];
    while (path != f->start->id) 
    {
        q->visited[path] = i;
    //    printf("%s ", f->id_table[path]->name);
        path = q->prev[path];

    }
    while (j < q->length)
    {
        q->prev[j] = -1;
		q->queue[j] = -1;
        if (q->visited[j] == 1)
            q->visited[j] = 0;
        ++j;
    }
 //   ft_putchar('\n');
}

int count_paths(t_queue *q, t_farm *f)
{
    int i;
    int longest_path;

    i = 2;
    int j = 0;
    longest_path = 0;
	while (bfs(f, q) == 0)
    {
      //  printf("Do we  get hhereee?");
        if (keep_path(q, f, &longest_path, i - 2) == 0)
            break;
        mark_path(f, q, i);
		++i;
    }
    return (i - 2);
}

int **save_paths(t_queue *q, t_farm *f, int max)
{
	int **paths;
	int i;
	int j;
    int longest_path;

	i = 0;
   // f->max_paths = 0;
    longest_path = 0;
	if (!(paths = ft_memalloc(sizeof(int *) * max)))
		return (NULL);
	while (i < max)
	{
		j = 0;
		if (bfs(f, q) == -1)
			return (0);
       // f->max_paths++;
		if (!(paths[i] = rev_path(f, q)))
			return (NULL);
      //  if (keep_path(q,f,&longest_path, paths) == 0)
      //      return (paths);
		mark_path(f, q, i + 2);
		++i;
	}
	return (paths);
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
    int pos;

    pos = f->end->id;
    steps = count_steps(q, f->start->id, f->end->id); //count how many moves we made
    i = 0;
    if (!(rev_path = malloc((sizeof(int)) * (steps + 1))))
        return (NULL);
    rev_path[steps] = pos;
    while (i <= steps) //save the path reversed as it is currently stored from end to start
    {
        rev_path[steps - i] = pos;
        pos = q->prev[pos];
        ++i;
    }
    return (rev_path);
}


  