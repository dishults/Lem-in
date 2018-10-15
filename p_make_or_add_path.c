/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_make_or_add_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:09:51 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:09:53 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	if it's an alternative path
**		- copy all previous steps except the last one
*/

t_path	*make_path(t_path *p, int links_nb)
{
	t_path	*path;
	int		i;

	i = 0;
	path = ft_memalloc(sizeof(t_path));
	path->step = (char **)malloc(links_nb * sizeof(char *));
	if (!path->step)
		return (0);
	if (p)
	{
		if (p->steps_nb > 0)
		{
			while (i < p->steps_nb)
			{
				path->step[i] = p->step[i];
				i++;
			}
		}
		path->steps_nb = p->steps_nb;
	}
	else
		path->steps_nb = 0;
	return (path);
}

void	add_to_path_list_end(t_lem_in *t, t_path *path)
{
	if (!t->first_path)
	{
		t->first_path = path;
		t->last_path = t->first_path;
	}
	else
	{
		t->last_path->next = path;
		t->last_path = t->last_path->next;
	}
}
