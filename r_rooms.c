/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rooms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:10:24 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:10:27 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_to_room_list_end(t_lem_in *t, t_room *room)
{
	if (!t->first_room)
	{
		t->first_room = room;
		t->last_room = t->first_room;
	}
	else
	{
		t->last_room->next = room;
		t->last_room = t->last_room->next;
	}
}

static t_room	*make_room(char **input)
{
	t_room		*room;

	if (!input || !input[0] || !input[1] || !input[2] ||
		input[0][0] == 'L' || input[0][0] == '#' ||
		!ft_isnumber(input[1]) || !ft_isnumber(input[2]))
	{
		free_strsplit(input, 0);
		return (0);
	}
	room = ft_memalloc(sizeof(t_room));
	room->name = input[0];
	room->room_x = ft_atoi(input[1]);
	room->room_y = ft_atoi(input[2]);
	free_strsplit(input, 1);
	return (room);
}

static int		line_is_a_link(t_lem_in *t)
{
	if (!ft_strchr_no_zero(t->line, '-'))
	{
		ft_printf("%s\n", t->line);
		free(t->line);
		error_free_exit(t);
	}
	return (1);
}

/*
**	CHECK IF
**
**	 room name
**		- already exists
**	 	- starts with a char 'L'
**	 	- has a char '-'
**
**	 coordinates
**		- aren't integers
**	 	- are negative
**
**	 line has more then 2 spaces(more parameters than "name x y")
**
**			 -> show error and exit
*/

void			get_rooms(t_lem_in *t)
{
	t_room		*room;
	char		**strings;

	while (get_next_line(0, &t->line) > 0)
	{
		strings = ft_strsplit(t->line, ' ');
		room = make_room(strings);
		if (room)
		{
			ft_printf("%s\n", t->line);
			check_room(t, room);
			add_to_room_list_end(t, room);
			t->room_nb++;
		}
		else if (start_room(t, strings) ||
				end_room(t, strings) ||
				comment(t))
			continue;
		else if (line_is_a_link(t))
			break ;
	}
}
