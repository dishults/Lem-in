/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:11:06 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:11:07 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ants_max(t_lem_in *t)
{
	int	ants_max;

	if (t->start_room_links_nb < t->end_room_links_nb)
	{
		if (t->paths_nb < t->start_room_links_nb)
			ants_max = t->paths_nb;
		else
			ants_max = t->start_room_links_nb;
	}
	else
	{
		if (t->paths_nb < t->end_room_links_nb)
			ants_max = t->paths_nb;
		else
			ants_max = t->end_room_links_nb;
	}
	return (ants_max);
}

static void	sort_first_path(t_lem_in *t, t_path *p, int *sorted)
{
	t_path	*tmp;
	t_path	*tmp1;

	if (p->next)
	{
		if (p->step[0] == p->next->step[0] &&
			p->steps_nb > p->next->steps_nb)
		{
			tmp = t->first_path;
			tmp1 = t->first_path->next->next;
			t->first_path = t->first_path->next;
			t->first_path->next = tmp;
			tmp->next = tmp1;
			*sorted = 1;
		}
	}
}

static void	sort_remaining_paths(t_lem_in *t, t_path *p, int *sorted)
{
	t_path	*tmp;
	t_path	*tmp1;

	while (p->next->next)
	{
		if (p->next->step[0] == p->next->next->step[0] &&
			p->next->steps_nb > p->next->next->steps_nb)
		{
			tmp = p->next;
			tmp1 = p->next->next->next;
			p->next = p->next->next;
			p->next->next = tmp;
			tmp->next = tmp1;
			p = t->first_path;
			*sorted = 1;
		}
		else
			p = p->next;
	}
}

static int	sort_by_steps_nb(t_lem_in *t)
{
	int		sorted;
	t_path	*p;

	sorted = 0;
	p = t->first_path;
	sort_first_path(t, p, &sorted);
	if (t->paths_nb > 1)
		sort_remaining_paths(t, p, &sorted);
	return (sorted);
}

/*
**	max_ants - how many ants I can send at each turn which is
**	 		the smallest from start(end)_room_links_nb or paths(combo)_nb
**
**	sort ALL PATHS by steps_nb (shortest to longest)
**		sort START ROOM LINKS by steps_nb of the paths they represent
**			find as many shortest PATHS THAT DON'T INTERSECT
**									(path_combos) as max_ants
*/

int			sort_paths(t_lem_in *t)
{
	int	sort;

	sort = 1;
	t->max_ants = ants_max(t);
	if (t->paths_nb > 1)
	{
		while (sort)
			sort = sort_by_steps_nb(t);
		if (t->start_room_links_nb > 1)
		{
			sort = 1;
			while (sort)
				sort = sort_start_room_links(t, t->first_path, t->first_path);
		}
	}
	get_best_paths_combo(t, t->first_start_r_l, t->first_path);
	if (t->max_ants > t->paths_combo)
		t->max_ants = t->paths_combo;
	return (1);
}
