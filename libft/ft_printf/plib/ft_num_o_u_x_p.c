/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_o_u_x_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:41:54 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 15:41:56 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_o(t_size *t)
{
	if (t->num == 0)
	{
		if (!t->pr ||
			(t->pr && (t->hash || !(t->precision < 1 || t->width > 0))))
			t->prnt += ft_putnbrr(0);
	}
	else if (t->len == 'l' || t->len == '2' ||
		t->len == 'z' || t->len == 'j' || t->convsp == 'O')
	{
		if (t->len == '2' || t->len == 'z' || t->len == 'j')
			t->prnt += ft_putnbr_base_u((unsigned long long)t->num, OCTAL_BASE);
		else
			t->prnt += ft_putnbr_base_u((unsigned long)t->num, OCTAL_BASE);
	}
	else
	{
		if (t->num < 0)
			t->prnt += ft_putnbr_base_u((unsigned int)t->num, OCTAL_BASE);
		else
			t->prnt += ft_putnbr_base_u(t->num, OCTAL_BASE);
	}
}

void		ft_u(t_size *t)
{
	if (!(t->num == 0 && t->pr && (t->precision < 1 || t->width > 0)))
	{
		if (t->num < 0 && (t->len == 'l' || t->len == '2' || t->convsp == 'U'))
		{
			if (t->len == '2')
				t->prnt += ft_putnbr_u((unsigned long long)t->num);
			else
				t->prnt += ft_putnbr_u((unsigned long)t->num);
		}
		else if (t->num < 0 && !(t->len == 'j' || t->len == 'z'))
			t->prnt += ft_putnbr_u((unsigned int)t->num);
		else
			t->prnt += ft_putnbr_u(t->num);
	}
}

static void	ft_cap_x(t_size *t)
{
	if (t->len == 'l' || t->len == '2' || t->len == 'z' || t->len == 'j')
	{
		if (t->len == '2' || t->len == 'z' || t->len == 'j')
			t->prnt += ft_putnbr_base_u((unsigned long long)t->num,
														HEX_BASE_CAPS);
		else
			t->prnt += ft_putnbr_base_u((unsigned long)t->num, HEX_BASE_CAPS);
	}
	else
	{
		if (t->num < 0)
			t->prnt += ft_putnbr_base_u((unsigned int)t->num, HEX_BASE_CAPS);
		else
			t->prnt += ft_putnbr_base_u(t->num, HEX_BASE_CAPS);
	}
}

void		ft_x(t_size *t)
{
	if (t->num == 0 &&
		(!t->pr || (t->pr && !(t->precision < 1 || t->width > 0))))
		t->prnt += ft_putnbrr(0);
	if (t->convsp == 'x')
	{
		if (t->len == 'l' || t->len == '2' || t->len == 'z' || t->len == 'j')
		{
			if (t->len == '2' || t->len == 'z' || t->len == 'j')
				t->prnt += ft_putnbr_base_u((unsigned long long)t->num,
																	HEX_BASE);
			else
				t->prnt += ft_putnbr_base_u((unsigned long)t->num, HEX_BASE);
		}
		else
		{
			if (t->num < 0)
				t->prnt += ft_putnbr_base_u((unsigned int)t->num, HEX_BASE);
			else
				t->prnt += ft_putnbr_base_u(t->num, HEX_BASE);
		}
	}
	else
		ft_cap_x(t);
}

void		ft_p(t_size *t, va_list ap)
{
	t->num = va_arg(ap, long);
	if (!(t->num == 0 && t->precision == 0 && t->pr))
		t->prnt += ft_putnbr_base(t->num, HEX_BASE);
	t->convsp = 0;
}
