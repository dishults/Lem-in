/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_check_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:10:14 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:10:15 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	compliance_check(t_lem_in *t, t_room *room)
{
	if (ft_strchr_no_zero(room->name, '-') || ft_count_char(t->line, ' ') > 2 ||
		room->room_x < 0 || room->room_y < 0)
	{
		free(t->line);
		free(room->name);
		free(room);
		error_free_exit(t);
	}
}

static void	same_as_startroom(t_lem_in *t, t_room *room)
{
	if (t->start_room_name &&
		(!ft_strcmp(t->start_room_name, room->name) ||
		(t->start_x == room->room_x && t->start_y == room->room_y)))
	{
		free(t->line);
		free(room->name);
		free(room);
		error_free_exit(t);
	}
}

static void	same_as_endroom(t_lem_in *t, t_room *room)
{
	if (t->end_room_name &&
			(!ft_strcmp(t->end_room_name, room->name) ||
			(t->end_x == room->room_x && t->end_y == room->room_y)))
	{
		free(t->line);
		free(room->name);
		free(room);
		error_free_exit(t);
	}
}

/*
**	checks room for compliance and duplicates
*/

void		check_room(t_lem_in *t, t_room *room)
{
	t_room	*r;

	compliance_check(t, room);
	same_as_startroom(t, room);
	same_as_endroom(t, room);
	r = t->first_room;
	while (r)
	{
		if (!ft_strcmp(r->name, room->name) ||
			(r->room_x == room->room_x && r->room_y == room->room_y))
		{
			free(t->line);
			free(room->name);
			free(room);
			error_free_exit(t);
		}
		else
			r = r->next;
	}
	free(t->line);
}
