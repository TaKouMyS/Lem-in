#include "lem-in.h"

t_path *ft_new_path(int *path, int len)
{
	t_path *new_element;

	if (!(new_element = (t_path *)malloc(sizeof(t_path) + (sizeof(int) * (len + 1)))))
		return (NULL);
	if (path == NULL)
	{
		new_element->path = NULL;
		new_element->len = 0;
	}
	else
	{
		if (!(new_element->path = malloc(sizeof(int) * (len + 1))))
			return (NULL);
		ft_memcpy(new_element->path, path, ((len + 1) * sizeof(int)));
		new_element->len = len;
	}
	new_element->next = NULL;
	new_element->division = NULL;
	return (new_element);
}
 
 //add new path to path solution
void	ft_add_path(t_path *paths, t_path *new)
{
    t_path *tracker;
    tracker = paths;
	if ((!paths) || (!new))
		return ;
	while (tracker->next != NULL)
		tracker = tracker->next;
	tracker->next = new;
}

//move path from iniial Null starting space.
t_path *clean_path(t_path *path_list)
{
   if (path_list->path == NULL && path_list->next->path != NULL)
		{
            path_list->next->max = path_list->max;
            path_list->next->division = path_list->division;
            path_list->next->longest = path_list->longest;
            path_list = path_list->next;
        }
    
	return (path_list);
}

//fill in the missing boxes
t_path **set_path(t_path **path_list, int i, t_farm *f)
{
	*path_list = clean_path(*path_list);
    (*path_list)->max = i;
    if (!((*path_list)->division = divide_ants(f, *path_list)))
			(*path_list)->len = -1;
	return (path_list);
}

void free_path(t_path *path_list)
{
	t_path *tracker;

	tracker = path_list;
	while(tracker != NULL)
	{
		path_list = path_list->next;
		if (tracker->division != NULL)
			free(tracker->division);
		free(tracker->path);
		free(tracker);
		tracker = path_list;
	}
}