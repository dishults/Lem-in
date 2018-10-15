/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:14:45 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:14:47 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_check(const char *nptr)
{
	int		len;

	len = 0;
	while (nptr[len] && nptr[len] >= '0' && nptr[len] <= '9')
		len++;
	if (len > 10)
		return (0);
	else
		return (1);
}

int			ft_atoii(const char *nptr)
{
	long	res;
	long	sign;
	long	i;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
	|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (ft_check(nptr + i) == 0)
	{
		if (*nptr == '-')
			return (0);
		else
			return (-1);
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + nptr[i++] - '0';
	return (sign * res);
}
