/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convsp_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:41:37 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 15:41:38 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**	conversion specifiers d D i o O u U x X p %
*/

static void	ft_print_width(t_size *t, va_list ap)
{
	if (t->mz == '0' &&
		(!t->pr || (t->pr && !ft_strchr_no_zeroo("dDoOiuUxXp", t->convsp))))
	{
		ft_zero(t, ap);
	}
	else if (t->mz != '-')
	{
		while (t->print_w-- > 0)
		{
			ft_putcharr(' ');
			t->prnt++;
		}
		if (t->convsp && !ft_strchr_no_zeroo("cCsSdDoOiuUxXp\%", t->convsp))
		{
			ft_putcharr(t->convsp);
			t->prnt++;
			t->convsp = 0;
		}
	}
}

static void	ft_adjust_print_w(t_size *t)
{
	if (t->hash && t->num != 0)
	{
		if (t->convsp == 'o' || t->convsp == 'O')
		{
			if (t->precision - t->var_size < 1)
				t->print_w -= 1;
		}
		else if (t->convsp == 'x' || t->convsp == 'X')
			t->print_w -= 2;
	}
	if (t->ps && t->num >= 0 && t->print_w > 0 &&
		ft_strchr_no_zeroo("dDi", t->convsp))
		t->print_w--;
	if (t->convsp == '%')
		t->print_w = t->width - t->var_size;
	else if (t->convsp == 'p')
		t->print_w -= 2;
}

static void	ft_get_print_w_p(t_size *t)
{
	if (t->width && t->convsp != '%')
	{
		if (t->num == 0 && t->pr && ft_strchr_no_zeroo("dDiuUoOxX", t->convsp))
			if (!((t->convsp == 'o' || t->convsp == 'O') && t->hash))
				t->var_size = 0;
		if (t->precision && t->precision - t->var_size > 0)
			t->print_w = t->width - t->precision;
		else
			t->print_w = t->width - t->var_size;
	}
	if (t->precision && t->convsp != '%')
		t->print_p = t->precision - t->var_size;
	ft_adjust_print_w(t);
}

static void	ft_preprocess(t_size *t, va_list ap)
{
	if (t->width || t->precision)
		ft_get_var_size(t, ap);
	ft_get_print_w_p(t);
	ft_print_width(t, ap);
	ft_plus_minus(t);
	ft_print_hash(t);
	if (t->convsp == 'p')
		t->prnt += ft_putstrr("0x");
	while (t->print_p-- > 0)
		t->prnt += ft_putnbrr(0);
}

void		ft_convsp_num(t_size *t, va_list ap)
{
	ft_preprocess(t, ap);
	if (t->convsp == 'd' || t->convsp == 'D' || t->convsp == 'i')
	{
		if (!(t->num == 0 && t->pr && (t->precision < 1 || t->width > 0)))
			t->prnt += ft_putnbrr(t->num);
	}
	else if (t->convsp == 'o' || t->convsp == 'O')
		ft_o(t);
	else if (t->convsp == 'u' || t->convsp == 'U')
		ft_u(t);
	else if (t->convsp == 'x' || t->convsp == 'X')
		ft_x(t);
	else if (t->convsp == 'p')
		ft_p(t, ap);
	else if (t->convsp == '%')
	{
		ft_putcharr('%');
		t->prnt++;
	}
	if (t->mz == '-')
		ft_minus(t);
}
