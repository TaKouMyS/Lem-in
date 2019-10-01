#include "../../includes/lem-in.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

static int find_last_ant(t_farm *f, int *path)
{
	int j;

	j = 0;
	//move to end of path
	while (path[j] != f->end->id)
		++j;
	//find last full room i.e. last ant on path
	while (f->id_table[path[j]]->empty == -1)
		--j;
	return (j + 1);
}

static int reach_finish(int *path, t_farm *f, int j)
{
	//If we've reached end of path return 1, else return 0. 
	if (path[j] == f->end->id)
	{
		ft_printf("L%d-%s ", f->id_table[path[j - 1]]->empty, f->id_table[path[j]]->name);
		if (j >= 1)
			f->id_table[path[j - 1]]->empty = -1;
		return (1);
	}
	return (0);
}

static void move_the_ant(int *path, t_farm *f, int j)
{
	//if the current space is empty and the prior place is not empty, MOVe
	if (f->id_table[path[j]]->empty == -1 && j > 1 && f->id_table[path[j - 1]]->empty != -1 )
	{
		f->id_table[path[j]]->empty = f->id_table[path[j - 1]]->empty;
		f->id_table[path[j - 1]]->empty = -1;
		ft_printf("L%d-%s ", f->id_table[path[j]]->empty, f->id_table[path[j]]->name);
	}
}

int    send_new_ant(t_farm *f, int *path, int moving_ants, int *finished_ants)
{
    int i;
    
    i = 0;
	// If first space on path (path[0] is start) is empty, send new ant
    if (moving_ants <= f->ant_nb && f->id_table[path[1]]->empty == -1)
	{	
		++moving_ants; //we're adding a new ant into the mix
        f->id_table[path[1]]->empty = moving_ants;
		if (path[1] == f->end->id)
			++finished_ants[0];
		ft_printf("L%d-%s ", moving_ants, f->id_table[path[1]]->name);
        	++i;
    }
    return (moving_ants);
}

void move_ants_on_path(int moving_ants, t_farm *f, int *path, int *finished_ants)
{
	int i; 
	int j;

	j = find_last_ant(f, path);
	//we find the last ant on the path, move forward one space, check if he has finished the path, 
	//then check the ant behind him, and behind him, until we reach beginning of path. 
	while (j != 0)
	{
		if ((reach_finish(path, f, j)) == 1)
			++finished_ants[0];
		else if (finished_ants[0] < f->ant_nb)
			move_the_ant(path, f, j);
		--j;
	}
}

int     send_ants(t_farm *f, int **paths, int max_paths, int moving_ants)
{
    int finished_ants;
    int i;

    moving_ants = 0;
    finished_ants = 0;
    i = 0;
	f->id_table[paths[0][0]]->empty = 0;
	printf("total ant s= %d\n", f->ant_nb); //to be deleted, for debugging
    while (finished_ants < f->ant_nb)
    {
		i = 0;
		//we cycle through our paths until all ants have finished paths
		while (i < f->max_paths)
		{
			move_ants_on_path(moving_ants, f, paths[i], &finished_ants);
			if (moving_ants < f->ant_nb) //if we have not yet sent all our ants
				moving_ants = send_new_ant(f, paths[i], moving_ants, &finished_ants);
			++i;
		}
		ft_putchar('\n');
	}
    return (0);

}