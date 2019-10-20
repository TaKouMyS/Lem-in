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
		ft_memcpy(new_element->path, path, (len * sizeof(int)));
		new_element->len = len;
	}
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	ft_add_path(t_path *paths, t_path *new)
{
    t_path *tracker;
    tracker = paths;
	if ((!paths) || (!new))
		return ;
	while (tracker->next != NULL)
		tracker = tracker->next;
	tracker->next = new;
	new->prev = tracker;
}