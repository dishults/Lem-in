/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:29:23 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:29:24 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies from SRC to DST till C character is found
**
**			DST has to be passed with &
**
**	Example
**			char *dst;
**			ft_strdup_c("hey there", &dst, ' ');
*/

int		ft_strdup_c(const char *src, char **dst, char c)
{
	int		n;

	n = 0;
	while (src[n])
	{
		if (src[n] == c)
		{
			*dst = ft_strndup(src, n);
			return (n);
		}
		n++;
	}
	return (0);
}
