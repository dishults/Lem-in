/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convsp_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:41:27 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 15:41:29 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**	conversion specifiers c C s S
*/

static void	ft_get_print_w(t_size *t)
{
	if (t->width && t->convsp != 'S')
	{
		if (t->error == 1 && (t->convsp != 's' || t->convsp != 'S'))
			t->var_size = 6;
		if (t->pr && t->var_size > 0
			&& t->precision < t->var_size
			&& !(t->convsp == 'c' || t->convsp == 'C'))
			t->print_w = t->width - t->precision;
		else
			t->print_w = t->width - t->var_size;
	}
	else if (t->width && t->convsp == 'S')
	{
		if (t->pr && t->var_size > 0
			&& t->precision < t->var_size)
			t->print_w = t->width - ((t->precision / 3) * 3);
		else
			t->print_w = t->width - t->var_size;
		t->prnt -= t->var_size;
	}
}

static void	ft_print_width(t_size *t)
{
	if (t->precision && t->prnt == t->var_size
		&& (t->convsp == 's' || t->convsp == 'S'))
		t->prnt -= t->var_size;
	if (t->mz != '-')
	{
		if (t->mz == '0')
			while (t->print_w-- > 0)
			{
				ft_putcharr('0');
				t->prnt++;
			}
		else
			while (t->print_w-- > 0)
			{
				ft_putcharr(' ');
				t->prnt++;
			}
	}
}

static void	ft_s(t_size *t, va_list ap)
{
	if (t->error == 1 || t->error == 2)
		ft_error(t, ap);
	else
	{
		if (t->pr && t->precision < t->var_size)
			t->prnt += ft_putstrr(ft_strndupp(va_arg(ap, char *),
						t->precision));
		else
			t->prnt += ft_putstrr(va_arg(ap, char *));
	}
}

static void	ft_cap_s(t_size *t, va_list ap)
{
	wchar_t	*str;

	if (t->error == 1)
		ft_error(t, ap);
	else
	{
		str = va_arg(ap, wchar_t *);
		if (t->pr && t->precision < t->var_size)
		{
			str = ft_strndup_w(str, t->precision / 3);
			ft_putstr_w(str);
			if (ft_strlen_w(str) > 0)
				t->prnt += ft_strlen_w(str);
		}
		else if (t->width)
		{
			ft_putstr_w(str);
			t->prnt += t->var_size;
		}
		else
			ft_putstr_w(str);
	}
}

void		ft_convsp_char(t_size *t, va_list ap)
{
	ft_get_var_size(t, ap);
	ft_get_print_w(t);
	ft_print_width(t);
	if (t->convsp == 's')
		ft_s(t, ap);
	else if (t->convsp == 'S')
		ft_cap_s(t, ap);
	else if (t->convsp == 'c')
	{
		ft_putcharr((char)va_arg(ap, int));
		t->prnt++;
	}
	else if (t->convsp == 'C')
		ft_putcharr_w(va_arg(ap, wchar_t));
	if (t->mz == '-')
		while (t->print_w-- > 0)
		{
			ft_putcharr(' ');
			t->prnt++;
		}
}
