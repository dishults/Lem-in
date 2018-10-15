/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:41:47 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 15:41:48 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_hash(t_size *t)
{
	if (t->hash && ft_strchr_no_zeroo("xXoO", t->convsp) && t->num != 0)
	{
		if (t->convsp == 'x')
		{
			t->prnt += ft_putstrr("0x");
			t->hash = 0;
		}
		else if (t->convsp == 'X')
		{
			t->prnt += ft_putstrr("0X");
			t->hash = 0;
		}
		else if ((t->convsp == 'o' || t->convsp == 'O')
			&& (t->precision - t->var_size < 1) && t->print_p < 1)
		{
			t->prnt += ft_putnbrr(0);
			t->hash = 0;
		}
	}
}

void	ft_plus_minus(t_size *t)
{
	if (t->ps && t->num >= 0)
	{
		if (ft_strchr_no_zeroo("dDi", t->convsp))
		{
			ft_putcharr(t->ps);
			t->prnt++;
			t->ps = 0;
		}
	}
}

void	ft_zero(t_size *t, va_list ap)
{
	if (t->ps)
		ft_plus_minus(t);
	if (t->hash)
		ft_print_hash(t);
	if (t->convsp == 'p')
	{
		t->prnt += ft_putstrr("0x");
		ft_p(t, ap);
	}
	while (t->print_w-- > 0)
		t->prnt += ft_putnbrr(0);
	if (t->convsp && !ft_strchr_no_zeroo("cCsSdDoOiuUxXp\%", t->convsp))
	{
		ft_putcharr(t->convsp);
		t->prnt++;
		t->convsp = 0;
	}
}

void	ft_minus(t_size *t)
{
	if (t->convsp && !ft_strchr_no_zeroo("cCsSdDoOiuUxXp\%", t->convsp))
	{
		ft_putcharr(t->convsp);
		t->prnt++;
		t->convsp = 0;
	}
	while (t->print_w-- > 0)
	{
		ft_putcharr(' ');
		t->prnt++;
	}
}
