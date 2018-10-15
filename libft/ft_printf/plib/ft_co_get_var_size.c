/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_co_get_var_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:41:18 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 15:41:20 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_size_s(t_size *t, va_list tmp)
{
	wchar_t *str;

	if (t->convsp == 's')
		t->var_size = ft_strlenn(va_arg(tmp, char *));
	else
	{
		str = va_arg(tmp, wchar_t *);
		if (ft_isasciii_wstr(str))
		{
			t->convsp = 's';
			t->error = 2;
		}
		t->var_size = ft_strlen_w(str);
	}
	if (t->var_size == -1)
		t->var_size = 0;
	else if (t->var_size == 0)
		t->error = 1;
	if (t->convsp == 'S')
		t->prnt += t->var_size;
}

static void	ft_size_u(t_size *t)
{
	if (t->convsp == 'u' && (t->width || t->precision))
	{
		if (ft_strchr_no_zeroo("l2jz", t->len))
			t->var_size = ft_num_lenn((size_t)t->num);
		else
			t->var_size = ft_num_lenn((unsigned int)t->num);
	}
	else if (t->convsp == 'U' && (t->width || t->precision))
		t->var_size = ft_num_lenn((unsigned long)t->num);
	else
		t->var_size = ft_num_lenn_u(t->num);
}

static void	ft_size_o(t_size *t)
{
	if (t->num == 0)
		t->var_size = 1;
	else if (t->convsp == 'o' && (t->width || t->precision))
	{
		if (ft_strchr_no_zeroo("l2jz", t->len))
			t->var_size = ft_strlenn(
				ft_nbrconvert_base((size_t)t->num, OCTAL_BASE));
		else
			t->var_size = ft_strlenn(
				ft_nbrconvert_base((unsigned int)t->num, OCTAL_BASE));
	}
	else if (t->convsp == 'O' && (t->width || t->precision))
	{
		if (ft_strchr_no_zeroo("l2jz", t->len))
			t->var_size = ft_strlenn(
				ft_nbrconvert_base((size_t)t->num, OCTAL_BASE));
		else
			t->var_size = ft_strlenn(
				ft_nbrconvert_base((unsigned long)t->num, OCTAL_BASE));
	}
	else
		t->var_size = ft_strlenn(ft_nbrconvert_base(t->num, OCTAL_BASE));
}

static void	ft_size_x_p(t_size *t, va_list tmp)
{
	if (t->convsp == 'x' || t->convsp == 'X')
	{
		if (t->num == 0)
			t->var_size = 1;
		else if (t->width || t->precision)
		{
			if (ft_strchr_no_zeroo("l2jz", t->len))
				t->var_size = ft_strlenn(
					ft_nbrconvert_base((size_t)t->num, HEX_BASE));
			else
				t->var_size = ft_strlenn(
					ft_nbrconvert_base((unsigned int)t->num, HEX_BASE));
		}
		else
			t->var_size = ft_strlenn(ft_nbrconvert_base(t->num, HEX_BASE));
	}
	else if (t->convsp == 'p')
	{
		t->var_size = ft_strlenn(
			ft_nbrconvert_base(va_arg(tmp, long), HEX_BASE));
		if (t->var_size == -1)
			t->var_size += 2;
		else if (t->var_size == 0)
			t->var_size += 1;
	}
}

void		ft_get_var_size(t_size *t, va_list ap)
{
	va_list tmp;

	va_copy(tmp, ap);
	if (t->convsp == 's' || t->convsp == 'S')
		ft_size_s(t, tmp);
	else if (t->convsp == 'C')
	{
		t->var_size = ft_chrlen_w(va_arg(tmp, wchar_t));
		t->prnt += t->var_size;
	}
	else if (t->convsp == 'i' || t->convsp == 'd' || t->convsp == 'D')
	{
		t->var_size = ft_num_lenn(t->num);
		if (t->num < 0)
			t->var_size++;
	}
	else if (t->convsp == 'u' || t->convsp == 'U')
		ft_size_u(t);
	else if (t->convsp == 'o' || t->convsp == 'O')
		ft_size_o(t);
	else if (t->convsp == 'x' || t->convsp == 'X' || t->convsp == 'p')
		ft_size_x_p(t, tmp);
	else
		t->var_size = 1;
	va_end(tmp);
}
