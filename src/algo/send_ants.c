#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

int    send_new_ants(t_farm *f, int **paths, int max_paths, int *moving_ants)
{
    int i;
    
    i = 0;

    while (i < max_paths && moving_ants[0] <= f->ant_nb)
    {
        if (f->id_table[paths[i][1]]->empty == 0)
			++moving_ants[0];
        f->id_table[paths[i][1]]->empty = 1;
        ++i;
    }
    return (moving_ants[0]);
}

int     send_ants(t_farm *f, int **paths, int max_paths, int ants)
{
    int finished_ants;
    int i;
    int current_ant;
    int step;

    ants = 0;
    finished_ants = 0;
    i = 0;
    while (finished_ants < f->ant_nb)
    {
        current_ant = 0;
        while (current_ant <= ants - finished_ants)
        {
            i = 0;
            while (i < max_paths && current_ant <= ants - finished_ants && i < 4)
            {
                step = 1;
				//get to last ant in current path
				while (f->id_table[paths[i][step]]->empty != 0)
					++step;
				//check if next space is available
                if (f->id_table[paths[i][step + 1]]->empty == 0)
				{
					//mark next space as full and current as empty
                	f->id_table[paths[i][step + 1]]->empty = 1;
                	f->id_table[paths[i][step]]->empty = 0;
                	printf("L%d-%s ", current_ant + 1 + i + finished_ants, f->id_table[paths[i][step + 1]]->name);
                	if (paths[i][step + 1] == f->end->id)
               		{
						//if it's the end, mark end as empty ant as finished
                    	f->id_table[paths[i][step + 1]]->empty = 0;
                    	++finished_ants;
               		}
				}
				//next ant, next path
                ++current_ant;
                ++i;
            }
			//checked ends of each path, moved all the ants
		//	putchar('\n');
		//send new ants and start from the beginning
    	i = 0;
    	while (i < max_paths && ants <= f->ant_nb)
   		{
        	if (f->id_table[paths[i][1]]->empty == 0)
				++ants;
			printf("L%d-%s ", ants, f->id_table[paths[i][1]]->name);
        	f->id_table[paths[i][1]]->empty = 1;
        	++i;
    	}
		putchar('\n');
	}
    }
    return (0);
}