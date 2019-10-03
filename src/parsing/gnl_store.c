/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:12:16 by amamy             #+#    #+#             */
/*   Updated: 2019/10/03 03:38:59 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem-in.h"

int gnl_store(int fd, char **line, t_farm *f)
{
    int     ret;
    t_input *new;
    t_input *tmp;
    // ft_putstr("teube\n");
    ret = get_next_line(fd, line);
    // ft_putstr("teube1\n");
    // ft_printf("line : |%s|\n", line[0]);
    // ft_putstr("teube1.5\n");
    tmp = f->input;
    if (ret > 0)
    {
        f->input->line = ft_strdup(*line);
        // ft_putstr(f->input->line);
		// ft_putstr("\n");
        if (!(new = ft_memalloc(sizeof(t_input))))
            return (-1);
        f->input->next = new;
        f->input = new;
        f->input->prev = tmp;
    }
    // ft_putstr("teube2\n");
    return (ret);
}