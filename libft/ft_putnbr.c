/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:47:01 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:47:03 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	tmp;
	unsigned int	length;

	length = 1;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	tmp = n;
	while ((tmp /= 10) > 0)
	{
		length *= 10;
	}
	tmp = n;
	while (length)
	{
		ft_putchar((char)((tmp / length)) + 48);
		tmp %= length;
		length /= 10;
	}
}
