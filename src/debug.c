#include "lem-in.h"
#include "libft.h"


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