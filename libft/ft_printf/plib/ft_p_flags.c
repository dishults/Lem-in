/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:42:04 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 15:42:05 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** flags # 0 - + space
*/

static void	ft_get_it(const char *s, int i, t_size *t)
{
	if (s[i] == '#')
	{
		t->hash = '#';
		t->flags = '1';
	}
	else if (s[i] == '-')
	{
		t->mz = '-';
		t->flags = '1';
	}
	else if (s[i] == '0' && !ft_isdigitt(s[i - 1]) && t->mz != '-')
	{
		t->mz = '0';
		t->flags = '1';
	}
	else if (s[i] == '+')
	{
		t->ps = '+';
		t->flags = '1';
	}
	else if (s[i] == ' ' && t->ps != '+')
	{
		t->ps = ' ';
		t->flags = '1';
	}
}

static void	ft_flags(const char *s, int *i, t_size *t, va_list ap)
{
	va_list tmp;

	va_copy(tmp, ap);
	if (ft_strchr_no_zeroo("#0-+ ", s[*i]))
	{
		while (!ft_strchr_no_zeroo("cCdDiuUoOxXsSp%", s[*i]))
		{
			ft_get_it(s, *i, t);
			*i += 1;
		}
	}
	va_end(tmp);
}

void		ft_get_flags(const char *s, int *i, t_size *t, va_list ap)
{
	while ((!ft_strchr_no_zeroo("cCdDiuUoOxXsSp%.", s[*i]) || (s[*i] == '.' &&
		!ft_strchr_no_zeroo(VALID_CHARS, s[*i + 1]))) && !t->flags)
	{
		ft_flags(s, i, t, ap);
		if (!t->flags)
			*i += 1;
	}
	if (t->flags)
		t->tmp = *i;
}
