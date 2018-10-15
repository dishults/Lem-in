/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:09:35 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:09:37 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	not enough data to proceed or
**	line is non-compliant or empty
*/

void			error_free_exit(t_lem_in *t)
{
	ft_putstr("ERROR\n");
	free_all(t);
	exit(0);
}

/*
**	while line is a comment(#)
**		print as long as it's a comment
**	if
**	 - line is empty
**	 - WHOLE LINE is not a number
**	 - number is less then 1
**		show error and exit
*/

static void		get_ants(t_lem_in *t)
{
	ft_printf("%s\n", t->line);
	while (t->line[0] == '#')
	{
		free(t->line);
		get_next_line(0, &t->line);
		ft_printf("%s\n", t->line);
	}
	if (!ft_isnumber(t->line))
	{
		free(t->line);
		error_free_exit(t);
	}
	t->ants_nb = ft_atoi_intmax(t->line);
	free(t->line);
	if (!t->ants_nb || t->ants_nb < 1)
		error_free_exit(t);
}

static void		check_if_rooms_are_there(t_lem_in *t)
{
	if (!t->room_nb || t->room_nb < 1 ||
		!t->start_room_name || !t->end_room_name)
		error_free_exit(t);
	else if (t->start_room_name && t->end_room_name)
	{
		if (!ft_strcmp(t->start_room_name, t->end_room_name))
		{
			ft_putstr("Already at the end\n");
			free(t->line);
			free_all(t);
			exit(0);
		}
	}
}

/*
** 	find each possible path
** 		- count steps for it
**	find [how many ants] I can send at each turn
**	find [as many] best shortest paths (that don't intersect)
*/

int				main(void)
{
	t_lem_in	*t;

	t = ft_memalloc(sizeof(t_lem_in));
	if (get_next_line(0, &t->line) < 1)
	{
		ft_putstr("ERROR\n");
		if (t->line)
			free(t->line);
		free(t);
		return (0);
	}
	get_ants(t);
	get_rooms(t);
	check_if_rooms_are_there(t);
	get_links(t);
	get_paths(t, NULL, t->start_room_name, t->first_link);
	if (t->first_path)
		sort_paths(t);
	else
		error_free_exit(t);
	move_ants(t);
	free_all(t);
	return (0);
}
