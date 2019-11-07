/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:35:25 by amamy             #+#    #+#             */
/*   Updated: 2019/11/07 16:39:56 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define START 1
# define END 2

# define GET_ANTS_LINKS 1
# define GET_ROOMS 2

typedef	struct		s_path
{
	int				*path;
	int				len;
	int				max;
	int				*division;
	int				longest;
	struct s_path	*next;
}					t_path;

typedef struct		s_queue
{
	int				*queue;
	int				*visited;
	int				*prev;
	int				length;
	int				position;
	int				**flow;
}					t_queue;

typedef struct		s_room
{
	int				id;
	int				links_nb;
	int				*links;
	struct s_room	*next;
	struct s_room	*prev;
	char			*name;
	int				empty;
	int				weight;
}					t_room;

typedef struct		s_input
{
	char			*line;
	struct s_input	*next;
}					t_input;

typedef struct		s_farm
{
	int				ant_nb;
	int				flags;
	int				room_nb;
	int				**links;
	int				max_paths;
	t_room			**id_table;
	t_room			*start;
	t_room			*end;
	t_room			*first_room;
	t_input			*input;
	t_input			*input_start;
	char			*line;
}					t_farm;

/*
** Parsing :
*/
int					get_input(t_farm *f, t_room *r);
int					get_room(t_room *r, t_farm *f);
t_room				*new_room(t_farm *f, t_room *r, char *line, long id);
int					get_links(t_farm *f);
int					gnl_store(int fd, char **line, t_farm *f, int origin);

/*
** Algo :
*/
int					error_free_line(char *line);
int					solve(t_farm *f);
int					bfs(t_farm *f, t_queue *q);
int					edmondskarp(t_queue *q, t_farm *f, t_path **p, int t);
int					send_ants(t_farm *f, t_path *paths, int moving_ants, int x);
void				clear_queue(t_queue *q);
int					initialise_queue(t_queue *q, t_farm *f);
void				reset_queue(t_queue *q, int start, int end);
int					set_to_n(int **set, int length, int n);
int					*divide_ants(t_farm *f, t_path *paths);
t_path				**save_paths(t_queue *q, t_farm *f, t_path **path_list);
t_path				*ft_new_path(int *path, int len);
void				ft_add_path(t_path *paths, t_path *new);
t_path				**set_path(t_path **path_list, int i, t_farm *f);
int					send_new_ant(t_farm *f, int *p, int mov, int *fin);
int					*get_path_lengths(t_farm *f, t_path *paths, int *total);
void				set_weights(t_farm *f);
int					check_weights(t_room *n, t_room *c, t_queue *q, t_farm *f);
int					check_print_space(int x);

/*
** Free :
*/
void				free_queue(t_queue *q);
void				free_path(t_path *path_list);
int					ft_delete_line(char *line);
int					ft_free_lemin(t_farm *f, t_room *r);
int					free_links(char *line, char **rooms, int ret);

#endif
