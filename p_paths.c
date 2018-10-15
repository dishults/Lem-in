/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_paths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:10:04 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:10:05 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	not_step(char *link, t_path *p, char *start_room_name)
{
	int	i;

	i = 0;
	if (!ft_strcmp(link, start_room_name))
		return (0);
	while (i < p->steps_nb)
	{
		if (!ft_strcmp(link, p->step[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	found_the_end_a(t_lem_in *t, t_path *path, char **next, t_link **l)
{
	if (not_step(l[0]->link_b, path, t->start_room_name))
	{
		if (l[0]->next)
			get_paths(t, path, *next, l[0]->next);
		*next = l[0]->link_b;
		path->step[path->steps_nb] = *next;
		path->steps_nb++;
		if (!ft_strcmp(*next, t->end_room_name))
		{
			path->steps_nb--;
			add_to_path_list_end(t, path);
			t->paths_nb++;
			return (1);
		}
		*l = t->first_link;
	}
	else
		*l = l[0]->next;
	return (0);
}

static int	found_the_end_b(t_lem_in *t, t_path *path, char **next, t_link **l)
{
	if (not_step(l[0]->link_a, path, t->start_room_name))
	{
		if (l[0]->next)
			get_paths(t, path, *next, l[0]->next);
		*next = l[0]->link_a;
		path->step[path->steps_nb] = *next;
		path->steps_nb++;
		if (!ft_strcmp(*next, t->end_room_name))
		{
			path->steps_nb--;
			add_to_path_list_end(t, path);
			t->paths_nb++;
			return (1);
		}
		*l = t->first_link;
	}
	else
		*l = l[0]->next;
	return (0);
}

/*
**	NEXT is start_room
**
**	find NEXT in LINK_A(B)
**		if LINK_B(A) is not a step that path already has
**			if there are more links to check
**				duplicate the path
**				copy all the steps except the last one
**				try to find NEXT in another LINK_A(B)
**			change NEXT to LINK_B(A)
**				if NEXT is the end_room
**					add path to the list of paths
**				else
**					save NEXT as a step
**					continue search
**
**	if NEXT is not the end_room and there are no more links to check
**		free(path)
*/

int			get_paths(t_lem_in *t, t_path *path, char *next, t_link *l)
{
	path = make_path(path, t->links_nb);
	while (l)
	{
		if (!ft_strcmp(l->link_a, next))
		{
			if (found_the_end_a(t, path, &next, &l))
				return (1);
		}
		else if (!ft_strcmp(l->link_b, next))
		{
			if (found_the_end_b(t, path, &next, &l))
				return (1);
		}
		else
			l = l->next;
	}
	free(path->step);
	free(path);
	return (0);
}
