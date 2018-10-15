/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:42:13 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 15:42:15 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**	length hh h l ll j z
*/

static void	ft_get_it(const char *s, int *i, t_size *t)
{
	while (ft_strchr_no_zeroo("hljz", s[*i]))
	{
		if (t->len && ft_strchr_no_zeroo("2jz", t->len))
			*i += 1;
		else if (s[*i] == 'h' && s[*i + 1] == 'h' && t->len != 'h')
		{
			t->len = 'c';
			*i += 2;
		}
		else if (s[*i] == 'l' && s[*i + 1] == 'l')
		{
			t->len = '2';
			*i += 2;
		}
		else
		{
			t->len = s[*i];
			*i += 1;
		}
	}
}

void		ft_get_length(const char *s, int *i, t_size *t)
{
	while (!ft_strchr_no_zeroo("cCdDiuUoOxXsSp%", s[*i]) && !t->len)
	{
		ft_get_it(s, i, t);
		if (!t->len)
			*i += 1;
	}
	if (!t->len)
		*i = t->start;
}

static void	ft_l(int *i, t_size *t, va_list ap)
{
	if (!t->num && ft_strchr_no_zeroo("doiuxX", t->convsp))
	{
		if (t->len == 'l')
		{
			if (t->convsp == 'd' || t->convsp == 'i')
				t->num = va_arg(ap, long);
			else
				t->num = va_arg(ap, unsigned long);
			*i += 1;
		}
		else
		{
			if (t->convsp == 'd' || t->convsp == 'i')
				t->num = va_arg(ap, long long);
			else
				t->num = va_arg(ap, unsigned long long);
			*i += 2;
		}
	}
}

static void	ft_h(int *i, t_size *t, va_list ap)
{
	if (!t->num && ft_strchr_no_zeroo("doiuxX", t->convsp))
	{
		if (t->len == 'h')
		{
			if (t->convsp == 'd' || t->convsp == 'i')
				t->num = (short)va_arg(ap, int);
			else
				t->num = (unsigned short)va_arg(ap, int);
		}
		else
		{
			*i += 1;
			if (t->convsp == 'd' || t->convsp == 'i')
				t->num = (char)va_arg(ap, int);
			else
				t->num = (unsigned char)va_arg(ap, int);
		}
	}
	*i += 1;
}

void		ft_length(int *i, t_size *t, va_list ap)
{
	if (t->len == 'l' || t->len == '2')
		ft_l(i, t, ap);
	else if (t->len == 'h' || t->len == 'c')
		ft_h(i, t, ap);
	else if (t->len == 'j')
	{
		if (!t->num && ft_strchr_no_zeroo("doiuxX", t->convsp))
		{
			if (t->convsp == 'd' || t->convsp == 'i')
				t->num = va_arg(ap, intmax_t);
			else
				t->num = va_arg(ap, uintmax_t);
		}
		*i += 1;
	}
	else if (t->len == 'z')
	{
		if (!t->num && ft_strchr_no_zeroo("doiuxX", t->convsp))
			t->num = va_arg(ap, size_t);
		*i += 1;
	}
}
