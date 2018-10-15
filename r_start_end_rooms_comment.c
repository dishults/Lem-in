/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_start_end_rooms_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:10:34 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:10:36 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	char	**check_start_room(t_lem_in *t, char **strings)
{
	if (t->start_room_name)
		error_free_exit(t);
	get_next_line(0, &t->line);
	ft_printf("%s\n", t->line);
	strings = ft_strsplit(t->line, ' ');
	if (!strings || !strings[0] || !strings[1] || !strings[2] ||
		strings[0][0] == 'L' ||
		!ft_isnumber(strings[1]) || !ft_isnumber(strings[2]))
	{
		free_strsplit(strings, 0);
		free(t->line);
		error_free_exit(t);
	}
	return (strings);
}

int				start_room(t_lem_in *t, char **strings)
{
	if (!ft_strcmp(t->line, "##start"))
	{
		ft_printf("%s\n", t->line);
		free(t->line);
		strings = check_start_room(t, strings);
		t->start_room_name = strings[0];
		t->start_x = ft_atoi(strings[1]);
		t->start_y = ft_atoi(strings[2]);
		if (ft_strchr_no_zero(t->start_room_name, '-') ||
			ft_count_char(t->line, ' ') > 2 ||
			t->start_x < 0 || t->start_y < 0)
		{
			free_strsplit(strings, 1);
			free(t->line);
			error_free_exit(t);
		}
		free_strsplit(strings, 1);
		t->room_nb++;
		free(t->line);
		return (1);
	}
	return (0);
}

static	char	**check_end_room(t_lem_in *t, char **strings)
{
	if (t->end_room_name)
		error_free_exit(t);
	get_next_line(0, &t->line);
	ft_printf("%s\n", t->line);
	strings = ft_strsplit(t->line, ' ');
	if (!strings || !strings[0] || !strings[1] || !strings[2] ||
		strings[0][0] == 'L' ||
		!ft_isnumber(strings[1]) || !ft_isnumber(strings[2]))
	{
		free_strsplit(strings, 0);
		free(t->line);
		error_free_exit(t);
	}
	return (strings);
}

int				end_room(t_lem_in *t, char **strings)
{
	if (!ft_strcmp(t->line, "##end"))
	{
		ft_printf("%s\n", t->line);
		free(t->line);
		strings = check_end_room(t, strings);
		t->end_room_name = strings[0];
		t->end_x = ft_atoi(strings[1]);
		t->end_y = ft_atoi(strings[2]);
		if (ft_strchr_no_zero(t->end_room_name, '-') ||
			ft_count_char(t->line, ' ') > 2 ||
			t->end_x < 0 || t->end_x < 0)
		{
			free_strsplit(strings, 1);
			free(t->line);
			error_free_exit(t);
		}
		free_strsplit(strings, 1);
		t->room_nb++;
		free(t->line);
		return (1);
	}
	return (0);
}

int				comment(t_lem_in *t)
{
	if (t->line[0] == '#')
	{
		ft_printf("%s\n", t->line);
		free(t->line);
		return (1);
	}
	return (0);
}
