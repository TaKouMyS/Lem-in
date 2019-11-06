/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:51:24 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:31:34 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *map;
	t_list *origin;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	if (!(map = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	origin = map;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		map->next = ft_lstnew(tmp->content, tmp->content_size);
		lst = lst->next;
		map = map->next;
	}
	return (origin);
}
