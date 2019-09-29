#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

static int find_last_ant(t_farm *f, int *path)
{
	int j;

	j = 0;
	while (f->id_table[path[j]]->empty != -1 && path[j] != f->end->id)
		++j;
	return (j);
}

static int reach_finish(int *path, t_farm *f, int j, int current_ant)
{
	if (path[j] == f->end->id)
	{
		ft_printf("L%d-%s ", f->id_table[path[j - 1]]->empty, f->id_table[path[j]]->name);
		if (j > 1)
			f->id_table[path[j - 1]]->empty = -1;
		return (1);
	}
	return (0);
}

static void move_the_ant(int *path, t_farm *f, int j, int current_ant)
{
	if (f->id_table[path[j]]->empty == -1 && j > 1)
	{
		f->id_table[path[j]]->empty = f->id_table[path[j - 1]]->empty;
		f->id_table[path[j - 1]]->empty = 0;
		ft_printf("L%d-%s ", f->id_table[path[j]]->empty, f->id_table[path[j]]->name);
	}
}

int    send_new_ants(t_farm *f, int *path, int moving_ants)
{
    int i;
    
    i = 0;
	printf("hello");
    if (moving_ants <= f->ant_nb && f->id_table[path[1]]->empty == -1)
	{	
		++moving_ants;
        f->id_table[path[1]]->empty = moving_ants;
		ft_printf("three L%d-%s ", moving_ants, f->id_table[path[1]]->name);
        	++i;
    }
    return (moving_ants);
}

void move_current_ants(int moving_ants, t_farm *f, int **paths, int *finished_ants)
{
	int i; 
	int j;
	int current_ant;

	current_ant = 0;
	while (current_ant <= moving_ants)
	{
		i = 0;
		while (i < f->max_paths && current_ant <= moving_ants)
		{
			j = find_last_ant(f, paths[i]);
		//	printf("j= %d\n", j);
			while (j != 1)
			{
				if ((reach_finish(paths[i], f, j, current_ant)) == 1)
					++finished_ants[0];
				else if (finished_ants[0] < f->ant_nb)
					move_the_ant(paths[i], f, j, current_ant);
				--j;	
			}
			if (j == 1)
				moving_ants = send_new_ants(f, paths[i], moving_ants);
			++i;
			++current_ant;
		}
	}
}




int     send_ants(t_farm *f, int **paths, int max_paths, int moving_ants)
{
    int finished_ants;
    int i;
    int current_ant;
    int position;

    moving_ants = 0;
    finished_ants = 0;
    i = 0;
	f->id_table[paths[0][0]]->empty = 1;
	printf("total ant s= %d\n", f->ant_nb);
//	moving_ants = send_new_ants(f, paths, moving_ants);
    while (finished_ants < f->ant_nb)
    {
		move_current_ants(moving_ants, f, paths, &finished_ants);

	}
    return (0);

}

/*

int send_ants(t_farm *f, int **paths, int max, int ants)
{
	
	int finished_ants;
	int moving_ants;


	return (0);ßßßß

			//checked ends of each path, moved all the ants
		//	putchar('\n');
		//send new ants and start from the beginning
    	i = 0;
    	while (i < max_paths && ants <= f->ant_nb)
   		{
        	if (f->id_table[paths[i][1]]->empty == 0)
			{	++ants;
				printf("L%d-%s ", ants, f->id_table[paths[i][1]]->name);
        		f->id_table[paths[i][1]]->empty = 1;
        		++i;
			}
    	}
}*/
