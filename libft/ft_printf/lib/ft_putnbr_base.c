/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 19:43:21 by dshults           #+#    #+#             */
/*   Updated: 2017/07/15 19:43:24 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long	check(char *base)
{
	long	i;
	long	n;

	i = 0;
	n = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		n = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < ' ' || base[i] > '~')
			return (0);
		while (base[n])
		{
			if (base[i] == base[n])
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

static void	ft_put(long long nbr, char *base, int *ret)
{
	long long	length;
	long long	res[1000];
	int			i;

	i = 0;
	length = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putcharr('-');
	}
	while (base[length])
		length++;
	while (nbr)
	{
		res[i] = nbr % length;
		nbr = nbr / length;
		i++;
	}
	*ret = i;
	i--;
	while (i >= 0)
		ft_putcharr(base[res[i--]]);
}

int			ft_putnbr_base(long long nbr, char *base)
{
	int	ret;

	ret = 0;
	if (nbr == 0)
	{
		ft_putcharr('0');
		ret = 1;
	}
	else if (check(base))
		ft_put(nbr, base, &ret);
	return (ret);
}

int			ft_putnbr_base_u(unsigned long long nbr, char *base)
{
	unsigned long long	length;
	unsigned long long	res[1000];
	int					i;
	int					ret;

	i = 0;
	length = 0;
	ret = 0;
	if (check(base))
	{
		while (base[length])
			length++;
		while (nbr)
		{
			res[i] = nbr % length;
			nbr = nbr / length;
			i++;
		}
		ret = i;
		i--;
		while (i >= 0)
			ft_putcharr(base[res[i--]]);
	}
	return (ret);
}
