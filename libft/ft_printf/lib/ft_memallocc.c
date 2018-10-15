/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memallocc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:14:45 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:14:47 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	*ft_memsett(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void		*ft_memallocc(size_t size)
{
	void	*fresh_mem;

	if (!(fresh_mem = (size_t *)malloc(size)) || size > 4294967295)
		return (0);
	else
		return (ft_memsett(fresh_mem, 0, size));
}
