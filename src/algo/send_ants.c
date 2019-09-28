#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

void move_current_ants(int moving_ants, t_farm *f, int **paths, int *finished_ants)
{
	int i; 
	int j;
	int current_ant;

	current_ant = finished_ants[0];
	printf("here\n");
	while (current_ant != moving_ants)
	{
		i = 0;
		while (i < f->max_paths && current_ant != moving_ants)
		{
			j = 0;
			while (f->id_table[paths[i][j]]->empty == 1 && paths[i][j] != f->end->id)
				++j;
			if (paths[i][j] == f->end->id) //if we're end of path
			{
				++finished_ants[0];
				if (j > 1)
					f->id_table[paths[i][j - 1]]->empty = 0;
				ft_printf("L%d-%d", current_ant, paths[i][j]);
			}
			else
			{
				if (j > 1)
					f->id_table[paths[i][j - 1]]->empty = 0;
				f->id_table[paths[i][j]]->empty = 1;
				ft_printf("L%d-%d", current_ant, paths[i][j]);
			}
			++i;
			++current_ant;
		}
	}
}

int    send_new_ants(t_farm *f, int **paths, int *moving_ants)
{
    int i;
    
    i = 0;
	printf("moving_ants = %d\n", moving_ants[0]);
    while (i < f->max_paths && moving_ants[0] <= f->ant_nb)
    {
	//	printf("here?");
        if (f->id_table[paths[i][1]]->empty == 0)
			++moving_ants[0];
        f->id_table[paths[i][1]]->empty = 1;
        ++i;
    }
    return (moving_ants[0]);
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
    while (finished_ants < f->ant_nb)
    {
        current_ant = 0 + finished_ants;
		move_current_ants(moving_ants, f, paths, &finished_ants);
		send_new_ants(f, paths, &moving_ants);
	
		putchar('\n');
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
