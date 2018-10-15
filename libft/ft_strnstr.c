/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:32:45 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:32:46 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		n = 0;
		while (to_find[n] == str[i + n] && i + n < len)
		{
			n++;
			if (to_find[n] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
