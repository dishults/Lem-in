/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:08:05 by dshults           #+#    #+#             */
/*   Updated: 2018/10/01 13:08:09 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	free strings made by ft_strsplit starting from string[i]
*/

void		free_strsplit(char **str, int i)
{
	while (str[i])
		free(str[i++]);
	free(str);
}

static void	free_p_combo(t_lem_in *t)
{
	t_p_combo	*pc;

	while (t->first_pc)
	{
		pc = t->first_pc;
		t->first_pc = t->first_pc->next;
		free(pc);
	}
}

static void	free_a(t_lem_in *t)
{
	t_ant	*ant;

	while (t->first_ant)
	{
		ant = t->first_ant;
		t->first_ant = t->first_ant->next;
		free(ant);
	}
}

static void	free_firsts(t_lem_in *t)
{
	free(t->first_room);
	free(t->first_link);
	free(t->first_start_r_l);
	free(t->first_path);
	free(t->first_pc);
	free(t->first_ant);
}

void		free_all(t_lem_in *t)
{
	free_r(t);
	free_l(t);
	free_srl(t);
	free_p(t);
	free_p_combo(t);
	free_a(t);
	free_firsts(t);
	free(t->start_room_name);
	free(t->end_room_name);
	free(t);
}
