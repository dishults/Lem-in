/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_r_l_srl_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:08:20 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:08:28 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_r(t_lem_in *t)
{
	t_room *room;

	while (t->first_room)
	{
		room = t->first_room;
		t->first_room = t->first_room->next;
		free(room->name);
		free(room);
	}
}

void	free_l(t_lem_in *t)
{
	t_link *link;

	while (t->first_link)
	{
		link = t->first_link;
		t->first_link = t->first_link->next;
		free(link->link_a);
		free(link->link_b);
		free(link);
	}
}

void	free_srl(t_lem_in *t)
{
	t_srl *srl;

	while (t->first_start_r_l)
	{
		srl = t->first_start_r_l;
		t->first_start_r_l = t->first_start_r_l->next;
		free(srl);
	}
}

void	free_p(t_lem_in *t)
{
	t_path	*path;

	while (t->first_path)
	{
		path = t->first_path;
		t->first_path = t->first_path->next;
		if (path->step)
			free(path->step);
		free(path);
	}
}
