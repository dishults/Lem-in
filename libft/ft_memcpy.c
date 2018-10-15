/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:21:09 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:21:11 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destination;
	char	*source;

	i = 0;
	destination = (char *)dest;
	source = (char *)src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
