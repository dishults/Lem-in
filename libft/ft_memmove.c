/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:21:38 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:21:39 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;

	destination = (char *)dest;
	source = (char *)src;
	if (source < destination)
	{
		source += n - 1;
		destination += n - 1;
		while (n > 0)
		{
			*destination-- = *source--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*destination++ = *source++;
			n--;
		}
	}
	return (dest);
}
