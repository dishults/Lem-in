/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:09:43 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:09:45 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ant	*make_ant(int ant_nb, t_p_combo *pc)
{
	t_ant		*ant;

	ant = ft_memalloc(sizeof(t_ant));
	ant->ant_nb = ant_nb;
	ant->p = pc;
	return (ant);
}

static void		add_to_ant_list_end(t_lem_in *t, t_ant *ant)
{
	if (!t->first_ant)
	{
		t->first_ant = ant;
		t->last_ant = t->first_ant;
	}
	else
	{
		t->last_ant->next = ant;
		t->last_ant = t->last_ant->next;
	}
}

static void		init_ants(t_lem_in *t)
{
	t_ant		*ant;
	t_p_combo	*path;
	int			ant_nb;

	ant = 0;
	ant_nb = 1;
	path = t->first_pc;
	if (t->paths_combo == 1)
		while (ant_nb <= t->ants_nb)
		{
			ant = make_ant(ant_nb, path);
			add_to_ant_list_end(t, ant);
			ant_nb++;
		}
	else
		while (ant_nb <= t->ants_nb)
		{
			ant = make_ant(ant_nb, path);
			add_to_ant_list_end(t, ant);
			if (path->next)
				path = path->next;
			else
				path = t->first_pc;
			ant_nb++;
		}
}

static void		move(t_lem_in *t, int n)
{
	t_ant		*ant;

	while (t->last_ant->step <= t->last_ant->p->steps_nb)
	{
		ant = t->first_ant;
		while (ant &&
			ant->ant_nb <= n * t->max_ants && ant->ant_nb <= t->ants_nb)
		{
			if (ant->step <= ant->p->steps_nb)
			{
				ft_printf("L%i-%s", ant->ant_nb, ant->p->step[ant->step]);
				ant->step++;
				if (ant->ant_nb < n * t->max_ants && ant->ant_nb < t->ants_nb)
					ft_putchar(' ');
			}
			ant = ant->next;
		}
		ft_putchar('\n');
		n++;
	}
}

/*
**	max_ants - how many ants I can send at each turn which is
**	 		the smallest from start(end)_room_links_nb or paths(combo)_nb
**
**	send 1st ant on path 1, 2nd on path 2, etc
**		for each ant remember its path and at what step it is
**
**	each step I can move [how many ants already sent] + max_ants
**		for as long as the [last ant] is not yet at its [last step]
*/

void			move_ants(t_lem_in *t)
{
	int	n;

	n = 0;
	if (t->paths_combo == 1 && t->first_pc->steps_nb == 0)
		while (n++ < t->ants_nb)
			ft_printf("L%i-%s\n", n, t->first_pc->step[0]);
	else
	{
		init_ants(t);
		move(t, n);
	}
}
