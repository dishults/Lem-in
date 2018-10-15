/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_check_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:08:38 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:08:40 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	check if link is direct from start to end
*/

static int	only_two_rooms(t_lem_in *t, char **link)
{
	if (t->room_nb == 2)
		if (!ft_strcmp(t->start_room_name, link[0]) ||
			!ft_strcmp(t->end_room_name, link[0]))
			if (!ft_strcmp(t->start_room_name, link[1]) ||
				!ft_strcmp(t->end_room_name, link[1]))
				return (1);
	return (0);
}

static int	check(t_lem_in *t, t_room *r, char *link)
{
	if (!ft_strcmp(r->name, link) ||
		!ft_strcmp(t->start_room_name, link) ||
		!ft_strcmp(t->end_room_name, link))
		return (1);
	return (0);
}

/*
**	check if both ends of the link match room names
*/

static int	check_link_with_rooms(t_lem_in *t, char **link)
{
	t_room *r;

	r = t->first_room;
	if (only_two_rooms(t, link))
		return (1);
	while (r)
	{
		if (check(t, r, link[0]))
			while (r)
			{
				if (check(t, r, link[1]))
					return (1);
				r = r->next;
			}
		else if (check(t, r, link[1]))
			while (r)
			{
				if (check(t, r, link[0]))
					return (1);
				r = r->next;
			}
		else
			r = r->next;
	}
	return (0);
}

int			check_link(t_lem_in *t, char **input)
{
	if (t->line[0] == '#')
	{
		free_strsplit(input, 0);
		return (0);
	}
	else if ((!input || !input[0] || !input[1]) ||
			ft_count_char(t->line, '-') > 1)
	{
		ft_printf("%s\n", t->line);
		free(t->line);
		free_strsplit(input, 0);
		error_free_exit(t);
	}
	else if (!check_link_with_rooms(t, input))
	{
		ft_printf("%s\n", t->line);
		free(t->line);
		free_strsplit(input, 0);
		error_free_exit(t);
	}
	return (1);
}
