/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:29:23 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:29:24 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		i;
	int		length;
	char	*copy;

	i = 0;
	length = 0;
	while (s[length])
		length++;
	if (!(copy = (char*)malloc(sizeof(char) * (length + 1))))
		return (0);
	else
	{
		while (i < length)
		{
			copy[i] = s[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
}
