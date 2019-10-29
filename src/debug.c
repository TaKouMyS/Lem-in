#include "lem-in.h"
#include "libft.h"


/*
** ==================== debug_print_room_links ====================
** to be put at the end of get_input
*/
void	debug_print_room_links(t_farm *f)
{
		ft_printf("links :\n");
		int j = 0;
		int i = 0;
		int id = 0;
		ft_printf("-------------\nroom nb = %d\n\n", f->room_nb);
		while (i < f->room_nb)
		{
			ft_printf("room %s (id : %d) has %d links : ", f->id_table[i]->name, i, f->id_table[i]->links_nb);
			j = 0;
			while (j < f->id_table[i]->links_nb)
			{
				id = f->id_table[i]->links[j];
				ft_printf("%s (id:%d) | ", f->id_table[id]->name, id);
				++j;
			}
			ft_putchar('\n');
			++i;
		}
}


/*
** ==================== which_links_save ====================
** to be put in save_links() (in get_links.c)
** 
*/
void	which_links_save(t_room **ids)
{
	ft_printf("links saved : |%s - %s|\n", ids[0]->name, ids[1]->name);
	ft_printf("links saved id : |%d - %d|\n----------\n", ids[0]->id, ids[1]->id);
}

/*
** ==================== ft_print_list_debug ====================
** to be put before return in get_links()
*/
void	ft_print_list_debug(t_farm *f)
{
	ft_printf("links :\n");
		int j = 0;
		int i = 0;
		ft_printf("room nb = %d\n", f->room_nb);
		while (i < f->room_nb)
		{
			ft_printf("%d ", i);
			++i;
		}
		ft_printf("\n................\n");
		i = 0;
		while (i < f->room_nb)
		{
			j = 0;
			while (j < f->room_nb)
			{
				ft_printf("%d ", f->links[i][j]);
				++j;
			}
			ft_putchar('\n');
			++i;
		}
}

//we won't need this later I think, it's just for debugging.

void	print_map(int **map, int length)
{
	int i;
	int j;

	i = 0;
	ft_printf("\n...........................\n");
	while (i < length)
	{
		j = 0;
		ft_printf("%d  |", i);
		while (j < length)
		{
			ft_printf("%d ", map[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
	ft_printf("...........................\n");
}

//same for debugging

void	print_paths(t_path *paths, t_farm *f)
{
	t_path	*tracker;
	int		i;
	size_t	j;

	i = 0;
	tracker = paths;
	ft_printf("max = %d\n", paths->max);
	while (i < paths->max)
	{
		j = 0;
		ft_printf("ant = %d len = %d. ", paths->division[i], tracker->len);
		//	ft_printf("i = %d, division = %d\n", i, paths->division[i]);
		if (tracker->path != NULL)
		{
			while (tracker->path[j] != f->end->id)
			{
				ft_printf("%s ", f->id_table[tracker->path[j]]->name);
				++j;
			}
			ft_printf("%s\n", f->id_table[tracker->path[j]]->name);
		}
		tracker = tracker->next;
		++i;
	}
}