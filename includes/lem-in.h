/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:35:25 by amamy             #+#    #+#             */
/*   Updated: 2019/09/02 21:56:34 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#define START 1
#define END 2

typedef struct			s_room
{
	char				*name;
	int					id;
	int					links_nb;
	int					*links;
	struct s_room		*next;
	struct s_room		*prev;
}						t_room;

typedef struct			s_farm
{
	int					ant_nb;
	int					flags;
	t_room				*start;
	t_room				*end;
}						t_farm;

int						get_input(t_farm *f, t_room *r);
int						get_room(t_room *r, t_farm *f);
t_room					*new_room(t_room *r, t_farm *f);
char					*check_comment(char *line, char *next_line, t_farm *f);
char					*room_check_syntax(char *line, t_farm *f);
void					ft_free_lemin(t_farm *f, t_room *r);

#endif
