/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort_startroom_links.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:11:15 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:11:17 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	sort_first_sr_link(t_lem_in *t, t_path *p1, t_path *p2, int *s)
{
	t_srl	*tmp;
	t_srl	*tmp1;

	if (p1->steps_nb > p2->steps_nb)
	{
		tmp = t->first_start_r_l;
		tmp1 = t->first_start_r_l->next->next;
		t->first_start_r_l = t->first_start_r_l->next;
		t->first_start_r_l->next = tmp;
		tmp->next = tmp1;
		*s = 1;
	}
}

static void	sort_remaining_sr_links(t_lem_in *t, t_path *p1, t_path *p2, int *s)
{
	t_srl	*srl;
	t_srl	*tmp;
	t_srl	*tmp1;

	srl = t->first_start_r_l;
	while (srl->next->next)
	{
		p1 = t->first_path;
		p2 = t->first_path;
		while (p1->step[0] != srl->next->name)
			p1 = p1->next;
		while (p2->step[0] != srl->next->next->name)
			p2 = p2->next;
		if (p1->steps_nb > p2->steps_nb)
		{
			tmp = srl->next;
			tmp1 = srl->next->next->next;
			srl->next = srl->next->next;
			srl->next->next = tmp;
			tmp->next = tmp1;
			*s = 1;
		}
		else
			srl = srl->next;
	}
}

int			sort_start_room_links(t_lem_in *t, t_path *p1, t_path *p2)
{
	t_srl	*srl;
	int		sorted;

	sorted = 0;
	srl = t->first_start_r_l;
	p1 = t->first_path;
	p2 = t->first_path;
	while (p1->step[0] != srl->name)
		p1 = p1->next;
	while (p2->step[0] != srl->next->name)
		p2 = p2->next;
	sort_first_sr_link(t, p1, p2, &sorted);
	if (t->start_room_links_nb > 1)
		sort_remaining_sr_links(t, p1, p2, &sorted);
	return (sorted);
}
