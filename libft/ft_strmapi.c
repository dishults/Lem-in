/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:31:10 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:31:12 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh_str;
	unsigned int	i;

	i = 0;
	if (!(fresh_str = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[i])
	{
		fresh_str[i] = f(i, s[i]);
		i++;
	}
	return (fresh_str);
}
