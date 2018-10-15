/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrconvert_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:04:45 by dshults           #+#    #+#             */
/*   Updated: 2018/01/28 18:04:46 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long		check(char *base)
{
	long		i;
	long		n;

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

/*
** ! Only for ft_printf !
** As it handles only unsigned numbers
** No support for signed negative ones
*/

char			*ft_nbrconvert_base(size_t nbr, char *base)
{
	long		length;
	long		res[1000];
	int			i;
	char		*s;

	i = 0;
	length = 0;
	s = (char *)malloc(sizeof(s));
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
		length = 0;
		while (--i >= 0)
			s[length++] = base[res[i]];
		s[length] = '\0';
	}
	return (s);
}
