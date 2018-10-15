/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:09:22 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:09:24 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct			s_path
{
	char				**step;
	int					steps_nb;
	struct s_path		*next;
}						t_path;

typedef struct			s_p_combo
{
	char				**step;
	int					steps_nb;
	struct s_p_combo	*next;
}						t_p_combo;

typedef struct			s_ant
{
	int					ant_nb;
	int					step;
	t_p_combo			*p;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_link
{
	char				*link_a;
	char				*link_b;
	struct s_link		*next;
}						t_link;

typedef struct			s_room
{
	char				*name;
	int					room_x;
	int					room_y;
	struct s_room		*next;
}						t_room;

/*
**	start room links
*/

typedef struct			s_srl
{
	char				*name;
	struct s_srl		*next;
}						t_srl;

typedef struct			s_lem_in
{
	char				*line;
	intmax_t			ants_nb;
	t_room				*first_room;
	t_room				*last_room;
	int					room_nb;
	char				*start_room_name;
	int					start_x;
	int					start_y;
	int					start_room_links_nb;
	char				*end_room_name;
	int					end_x;
	int					end_y;
	int					end_room_links_nb;
	t_link				*first_link;
	t_link				*last_link;
	t_srl				*first_start_r_l;
	t_srl				*last_start_r_l;
	int					links_nb;
	t_path				*first_path;
	t_path				*last_path;
	t_p_combo			*first_pc;
	t_p_combo			*last_pc;
	t_ant				*first_ant;
	t_ant				*last_ant;
	int					paths_nb;
	int					max_ants;
	int					paths_combo;
}						t_lem_in;

/*
**	MAIN
*/

void					error_free_exit(t_lem_in *t);

/*
**	ROOMS
*/

void					get_rooms(t_lem_in *t);
void					check_room(t_lem_in *t, t_room *room);
int						start_room(t_lem_in *t, char **strings);
int						end_room(t_lem_in *t, char **strings);
int						comment(t_lem_in *t);

/*
**	LINKS
*/

void					get_links(t_lem_in *t);
int						check_link(t_lem_in *t, char **input);
void					start_end_room_links(t_lem_in *t);

/*
**	PATHS
*/

int						get_paths(
							t_lem_in *t, t_path *path, char *next, t_link *l);
t_path					*make_path(t_path *p, int links_nb);
void					add_to_path_list_end(t_lem_in *t, t_path *path);

/*
**	SORT
*/

int						sort_paths(t_lem_in *t);
int						sort_start_room_links(
							t_lem_in *t, t_path *p1, t_path *p2);
int						get_best_paths_combo(t_lem_in *t, t_srl *s, t_path *p);

/*
**	MOVE
*/

void					move_ants(t_lem_in *t);

/*
**	FREE
*/

void					free_all(t_lem_in *t);
void					free_strsplit(char **str, int i);
void					free_r(t_lem_in *t);
void					free_l(t_lem_in *t);
void					free_srl(t_lem_in *t);
void					free_p(t_lem_in *t);

#endif
