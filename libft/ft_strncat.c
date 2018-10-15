/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:31:25 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:31:27 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	while (dest[n])
		n++;
	while (src[i] && i < nb)
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (dest);
}
