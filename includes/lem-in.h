/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:35:25 by amamy             #+#    #+#             */
/*   Updated: 2019/10/05 04:39:42 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#define START 1
#define END 2

#define GET_ANTS_LINKS 1
#define GET_ROOMS 2

typedef struct			s_queue
{
	int					*queue;
	int					*visited;
	int					*prev;
	int					length;
	int					position;
	int					**flow;
}						t_queue;

typedef struct			s_room
{
	int					id;
	int					links_nb;
	struct s_room		*next;
	struct s_room		*prev;
	char				*name;
	int					empty;
}						t_room;

typedef struct 			s_input
{
	char				*line;
	struct s_input		*next;
}						t_input;


typedef struct			s_farm
{
	int					ant_nb;
	int					flags;
	int					room_nb;
	int					**links;
	int					max_paths;
	t_room				**id_table;
	t_room				*start;
	t_room				*end;
	t_input				*input;
	t_input				*input_start;
	char				*line;
}						t_farm;

int						get_input(t_farm *f, t_room *r);
int						get_room(t_room *r, t_farm *f);
t_room					*new_room(t_room *r);
char					*check_comment(char *line, char *next_line, t_farm *f);
char					*is_comment(t_farm *f, int ret, char *line);
void					ft_free_lemin(t_farm *f, t_room *r);
int						free_links(char *line, char **rooms, int ret);
int						error_free_line(char *line);
int						get_links(t_farm *f);
int 					gnl_store(int fd, char **line, t_farm *f, int origin);
int     				solve(t_farm *f, int length, int start, int end);
int 					bfs(t_farm *f, t_queue *q);
int 					max_flow(t_queue *q, t_farm *f);
int 					count_steps(t_queue *q, int start, int end);
int 					*rev_path(t_farm *f, t_queue *q);
int 					edmondskarp(t_queue *q, t_farm *f, int ***paths);
int						send_ants(t_farm *f, int **paths, int moving_ants);
int 					optimise_flow(t_farm *f, t_queue *q);
void 					save_flow(t_queue *q, t_farm *f);
void 					clear_queue(t_queue *q);
int 					**save_paths(t_queue *q, t_farm *f, int max);
int 					count_paths(t_queue *q, t_farm *f);
int 					initialise_queue(t_queue *q, int length, int start);
void 					print_map(int **map, int length);
void 					reset_queue(t_queue *q, int start, int end);
int 					set_to_n(int **set, int length, int n);
int 					keep_path(t_queue *q, t_farm *f, int *longest_path, int paths);
int						*divide_ants(t_farm *f, int **paths);
#endif
