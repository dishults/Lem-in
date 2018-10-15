/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:30:16 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:30:17 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	n = 0;
	while (s1[i])
		str[n++] = s1[i++];
	i = 0;
	while (s2[i])
		str[n++] = s2[i++];
	str[n] = '\0';
	return (str);
}
