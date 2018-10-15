/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:27:15 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:27:16 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	To print wchar_t I convert it to UTF-8 and print it by bytes using char
**				*							_
**		bits being converted		bits being cut
**		and sent to print			and ignored
**
**				Mandatory bits to be added
**	1 byte		0xxxxxxx
**					no action								*
**
** 	2 bytes		110xxxxx 10xxxxxx // 192 128
**					(chr >> 6) + 11000000					*_
**					(chr & 111111) + 10000000				_*
**
** 	3 bytes		1110xxxx 10xxxxxx 10xxxxxx // 224 128 128
**					(chr >> 12) + 11100000					*__
**					((chr >> 6) & 111111) + 10000000		_*_
**					(chr & 111111) + 10000000				__*
**
** 	4 bytes		11110xxx 10xxxxxx 10xxxxxx 10xxxxxx // 240 128 128 128
**					(chr >> 18) + 11110000					*___
**					((chr >> 12) & 111111) + 10000000		_*__
**					((chr >> 6) & 111111) + 10000000		__*_
**					(chr & 111111) + 10000000				___*
*/

#include "../ft_printf.h"

void	ft_putcharr(char c)
{
	write(1, &c, 1);
}

/*
**	127 2047 65537 1114111
*/

void	ft_putcharr_w(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putcharr(chr);
	else if (chr <= 0x7FF)
	{
		ft_putcharr((chr >> 6) + 192);
		ft_putcharr((chr & 63) + 128);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putcharr((chr >> 12) + 224);
		ft_putcharr(((chr >> 6) & 63) + 128);
		ft_putcharr((chr & 63) + 128);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putcharr((chr >> 18) + 240);
		ft_putcharr(((chr >> 12) & 63) + 128);
		ft_putcharr(((chr >> 6) & 63) + 128);
		ft_putcharr((chr & 63) + 128);
	}
}

int		ft_putstrr(char const *s)
{
	int	ret;

	ret = 0;
	if (s == NULL || s[0] == '\0')
		return (0);
	else
	{
		while (*s)
		{
			ft_putcharr(*s++);
			ret++;
		}
		return (ret);
	}
}

int		ft_putstr_w(wchar_t *s)
{
	int	ret;

	ret = 0;
	if (s == NULL || s[0] == '\0')
		return (0);
	else
	{
		while (*s)
		{
			ft_putcharr_w(*s++);
			ret++;
		}
		return (ret);
	}
}

void	ft_error(t_size *t, va_list ap)
{
	if (t->error == 1)
	{
		if (t->pr && t->precision < t->var_size)
			t->prnt += ft_putstrr(ft_strndupp("(null)", t->precision));
		else
			t->prnt += ft_putstrr("(null)");
		(void)va_arg(ap, char *);
	}
	else
	{
		if (t->pr && t->precision < t->var_size)
			t->prnt += ft_putstr_w(ft_strndup_w(va_arg(ap, wchar_t *),
														t->precision));
		else
			t->prnt += ft_putstr_w(va_arg(ap, wchar_t *));
	}
}
