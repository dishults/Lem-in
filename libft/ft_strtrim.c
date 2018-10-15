/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:34:04 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:34:06 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	len = (int)ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
