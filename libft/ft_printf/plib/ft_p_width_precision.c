/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_width_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:42:29 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 15:42:30 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_width(const char *s, int *i, t_size *t, va_list ap)
{
	if (ft_isdigitt(s[*i]))
	{
		t->width = ft_atoii(&s[*i]);
		while (ft_isdigitt(s[*i]))
			*i += 1;
	}
	if (s[*i] == '*')
	{
		t->width = va_arg(ap, int);
		if (t->width < 0)
		{
			t->mz = '-';
			t->flags = '1';
			t->width *= -1;
		}
		*i += 1;
		if (ft_isdigitt(s[*i]))
		{
			t->width = ft_atoii(&s[*i]);
			while (ft_isdigitt(s[*i]))
				*i += 1;
		}
	}
}

void		ft_get_width(const char *s, int *i, t_size *t, va_list ap)
{
	while ((!ft_strchr_no_zeroo("cCdDiuUoOxXsSp%.", s[*i]) || (s[*i] == '.' &&
		!ft_strchr_no_zeroo(VALID_CHARS, s[*i + 1]))) && !t->width)
	{
		if (ft_isdigitt(s[*i]) || s[*i] == '*')
			ft_width(s, i, t, ap);
		else
			*i += 1;
	}
	if (t->width && s[*i] == '\0')
		t->width = 0;
}

void		ft_precision(const char *s, int *i, t_size *t, va_list ap)
{
	if (s[*i] == '.')
	{
		t->pr = 1;
		*i += 1;
		if (ft_isdigitt(s[*i]))
		{
			t->precision = ft_atoii(&s[*i]);
			while (ft_isdigitt(s[*i]))
				*i += 1;
			if (s[*i] == '*')
				t->width = va_arg(ap, int);
		}
		else if (s[*i] == '*')
		{
			t->precision = va_arg(ap, int);
			if (t->precision < 0)
			{
				t->precision = 0;
				t->pr = 0;
			}
			*i += 1;
		}
	}
}
