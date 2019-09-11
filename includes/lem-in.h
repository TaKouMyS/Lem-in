/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:35:25 by amamy             #+#    #+#             */
/*   Updated: 2019/09/09 23:50:32 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#define START 1
#define END 2

typedef struct			s_queue
{
	int					*queue;
	int					*visited;
	int					*prev;
	int					length;
	int					position;
}						t_queue;

typedef struct			s_room
{
	int					id;
	int					links_nb;
	struct s_room		*next;
	struct s_room		*prev;
	char				*name;
}						t_room;


typedef struct			s_farm
{
	int					ant_nb;
	int					flags;
	int					room_nb;
	int					**links;
	t_room				**id_table;
	t_room				*start;
	t_room				*end;
	char				*line;
}						t_farm;

int						get_input(t_farm *f, t_room *r);
int						get_room(t_room *r, t_farm *f);
t_room					*new_room(t_room *r);
char					*check_comment(char *line, char *next_line, t_farm *f);
char					*room_check_syntax(char *line, t_farm *f);
void					ft_free_lemin(t_farm *f, t_room *r);
int						free_links(char *line, char **rooms, int ret);
int						get_links(t_farm *f);
int     solve(int **map, int length, int start, int end);

#endif
