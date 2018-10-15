/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_start_end_room_links.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:09:06 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:09:09 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_to_srl_list_end(t_lem_in *t, t_srl *srl)
{
	if (!t->first_start_r_l)
	{
		t->first_start_r_l = srl;
		t->last_start_r_l = t->first_start_r_l;
	}
	else
	{
		t->last_start_r_l->next = srl;
		t->last_start_r_l = t->last_start_r_l->next;
	}
}

static t_srl	*make_start_room_link(char *link)
{
	t_srl	*srl;

	srl = ft_memalloc(sizeof(t_srl));
	srl->name = link;
	srl->next = NULL;
	return (srl);
}

void			start_end_room_links(t_lem_in *t)
{
	t_link	*l;
	t_srl	*srl;

	l = t->first_link;
	while (l)
	{
		if (!ft_strcmp(l->link_a, t->start_room_name))
		{
			srl = make_start_room_link(l->link_b);
			add_to_srl_list_end(t, srl);
			t->start_room_links_nb++;
		}
		else if (!ft_strcmp(l->link_b, t->start_room_name))
		{
			srl = make_start_room_link(l->link_a);
			add_to_srl_list_end(t, srl);
			t->start_room_links_nb++;
		}
		if (!ft_strcmp(l->link_a, t->end_room_name) ||
			!ft_strcmp(l->link_b, t->end_room_name))
			t->end_room_links_nb++;
		l = l->next;
	}
}
