/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:43:21 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 13:43:23 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flags 							# 0 - + space
** width and precision				0123456789
** length 							hh h l ll j z
** char conversion specifiers 		c C s S
** num conversion specifiers 		d D i o O u U x X
** extra conversion specifiers 		p %%
**
** bonus 	* asterisk for width or precision
*/

void	ft_conversion_specifier(const char *s, int *i, t_size *t, va_list ap)
{
	if (!t->convsp && ft_isprintt(s[*i]))
		t->convsp = s[*i];
	if (t->len == 'l' && t->convsp == 'c')
		t->convsp = 'C';
	else if (t->len == 'l' && t->convsp == 's')
		t->convsp = 'S';
	if (ft_strchr_no_zeroo("sScC", t->convsp))
		ft_convsp_char(t, ap);
	else if (t->convsp)
	{
		if (!t->len && ft_strchr_no_zeroo("doiuxX", t->convsp))
			t->num = va_arg(ap, int);
		else
		{
			if (ft_strchr_no_zeroo("DOU", t->convsp))
				t->num = va_arg(ap, long);
			ft_length(i, t, ap);
		}
		if (t->num < 0 && ft_strchr_no_zeroo("dDi", t->convsp))
		{
			t->ps = '-';
			t->num *= -1;
		}
		ft_convsp_num(t, ap);
	}
}

int		ft_process(const char *s, int i, va_list ap)
{
	t_size	*t;
	int		print;

	t = ft_memallocc(sizeof(t_size));
	if (!t)
		return (0);
	t->start = i;
	t->tmp = 0;
	ft_get_flags(s, &i, t, ap);
	i = t->start;
	ft_get_width(s, &i, t, ap);
	ft_precision(s, &i, t, ap);
	if (!t->width || !t->precision)
		i = t->start;
	t->tmp = i;
	i = t->start;
	ft_get_length(s, &i, t);
	while (ft_strchr_no_zeroo(NOT_CONVERSION_SPECIFIER, s[i]))
		i++;
	ft_conversion_specifier(s, &i, t, ap);
	print = t->prnt;
	free(t);
	return (print);
}

void	ft_continue(int *i, const char *s, int *printed, va_list ap)
{
	*i += 1;
	if (!(s[*i] == '\0' || !ft_strchr_no_zeroo(VALID_CHARS, s[*i])))
	{
		*printed += ft_process(s, *i, ap);
		while (ft_strchr_no_zeroo(" #0-+.hljz123456789*", s[*i]))
			*i += 1;
		if (ft_isprintt(s[*i]))
			*i += 1;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(ap, format);
	while (format[i] && ft_isasciii(format[i]))
	{
		if (format[i] == '%')
			ft_continue(&i, format, &printed, ap);
		else
		{
			ft_putcharr(format[i]);
			i++;
			printed++;
		}
	}
	va_end(ap);
	return (printed);
}
