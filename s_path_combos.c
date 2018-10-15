/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_path_combos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:10:51 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:10:54 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_p_combo	*make_path_combo(t_path *p)
{
	t_p_combo		*p_combo;

	p_combo = ft_memalloc(sizeof(t_p_combo));
	if (p)
	{
		p_combo->step = p->step;
		p_combo->steps_nb = p->steps_nb;
	}
	else
	{
		p_combo->step = NULL;
		p_combo->steps_nb = 0;
	}
	p_combo->next = NULL;
	return (p_combo);
}

static void			add_to_path_combo_list_end(t_lem_in *t, t_p_combo *pc)
{
	if (!t->first_pc)
	{
		t->first_pc = pc;
		t->last_pc = t->first_pc;
	}
	else
	{
		t->last_pc->next = pc;
		t->last_pc = t->last_pc->next;
	}
}

static int			paths_intersect(t_lem_in *t, t_path *p)
{
	t_p_combo	*pc;
	int			s1;
	int			s2;

	pc = t->first_pc;
	while (pc)
	{
		s1 = 0;
		while (s1 < pc->steps_nb)
		{
			s2 = 0;
			while (s2 < p->steps_nb)
			{
				if (!ft_strcmp(pc->step[s1], p->step[s2]))
					return (1);
				else
					s2++;
			}
			s1++;
		}
		pc = pc->next;
	}
	return (0);
}

/*
**	check if I take 1st shortest path
**		* will there be a 2nd_path without intersections ?
**		* if not - 1st_shortest_path++. What about now ? if yes :
**			* 3rd_path ? or up to [max_ants]_paths
*/

int					get_best_paths_combo(t_lem_in *t, t_srl *s, t_path *p)
{
	if (t->paths_combo == t->max_ants)
		return (1);
	while (s && p)
	{
		while (s->next && ft_strcmp(s->name, p->step[0]))
		{
			if (p->next)
				p = p->next;
			else
				s = s->next;
		}
		while (p && !ft_strcmp(s->name, p->step[0]))
		{
			if (!paths_intersect(t, p))
			{
				add_to_path_combo_list_end(t, make_path_combo(p));
				t->paths_combo++;
				if (get_best_paths_combo(t, s->next, t->first_path))
					return (1);
			}
			p = p->next;
		}
		s = s->next;
	}
	return (0);
}
