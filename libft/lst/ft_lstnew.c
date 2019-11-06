/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:20:10 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:17:37 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_element;

	if (!(new_element = (t_list*)malloc(sizeof(t_list) + content_size)))
		return (NULL);
	if (content == NULL)
	{
		new_element->content = NULL;
		new_element->content_size = 0;
	}
	else
	{
		if (!(new_element->content = ft_strnew(content_size)))
			return (NULL);
		ft_memcpy(new_element->content, content, content_size);
		new_element->content_size = content_size;
	}
	new_element->next = NULL;
	return (new_element);
}
