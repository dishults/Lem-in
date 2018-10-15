/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:19:32 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:19:34 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	unsigned int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	num_len;

	num = n;
	num_len = ft_num_len(n);
	if (n < 0)
	{
		num = -n;
		num_len++;
	}
	if (!(str = ft_strnew(num_len)))
		return (0);
	str[--num_len] = num % 10 + '0';
	while (num /= 10)
		str[--num_len] = num % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
