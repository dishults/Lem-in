/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isasciii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:18:40 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:18:41 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int	ft_isasciii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isasciii_wstr(wchar_t *s)
{
	char	*s1;

	s1 = (char *)s;
	if (s == NULL)
		return (1);
	else if (s1[0] == '\0')
		return (-1);
	while (*s)
	{
		if (ft_isasciii(*s))
			s++;
		else
			return (0);
	}
	return (1);
}
