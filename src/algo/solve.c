#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

//we won't need this later I think, it's just for debugging. 
void print_map(int **map, int length)
{
	int i;
	int j;

	i = 0;
	printf("\n...........................\n");
	while (i < length)
	{
		j = 0;
		printf("%d  |", i);
		while (j < length)
		{
			printf("%d ", map[i][j]);
			++j;
		}
		putchar('\n');
		++i;
	}
	printf("...........................\n");
}


int     solve(t_farm *f, int length, int start, int end)
{
    t_queue q;
    int		**paths;
	int		i;
	int		j;

	i = 0;
	if (initialise_queue(&q, length, start) < 0)
        return (-1);
    edmondskarp(&q, f, paths);
    return (0);
}