/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:33:40 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:33:41 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!(sub = ft_strnew(len)))
		return (0);
	i = 0;
	while (len)
	{
		sub[i++] = s[start++];
		len--;
	}
	return (sub);
}
