/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_links.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:08:54 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:08:56 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_to_link_list_end(t_lem_in *t, t_link *link)
{
	if (!t->first_link)
	{
		t->first_link = link;
		t->last_link = t->first_link;
	}
	else
	{
		t->last_link->next = link;
		t->last_link = t->last_link->next;
	}
}

static t_link	*make_link(char **input)
{
	t_link	*link;

	link = ft_memalloc(sizeof(t_link));
	link->link_a = input[0];
	link->link_b = input[1];
	free_strsplit(input, 2);
	return (link);
}

static int		line_is_link(t_lem_in *t)
{
	t_link	*link;
	char	**strings;

	strings = ft_strsplit(t->line, '-');
	if (check_link(t, strings))
	{
		link = make_link(strings);
		add_to_link_list_end(t, link);
		t->links_nb++;
		return (1);
	}
	return (0);
}

/*
**	CHECK IF
**
**	line is a comment
**			-> show the comment
**
**	line
**		- is empty
**		- has less than 2 links
**		- has more than 1 '-' char (more than 2 links)
**		- doesn't match room names
**
**			-> show error and exit
*/

void			get_links(t_lem_in *t)
{
	while (1)
	{
		if (line_is_link(t) || t->line[0] == '#')
		{
			ft_printf("%s\n", t->line);
			free(t->line);
		}
		else
		{
			free(t->line);
			break ;
		}
		if (get_next_line(0, &t->line) > 0)
			continue;
		else
		{
			free(t->line);
			break ;
		}
	}
	if (!t->links_nb || t->links_nb < 1)
		error_free_exit(t);
	start_end_room_links(t);
}
