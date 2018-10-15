/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:33:17 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:33:19 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int n;

	i = 0;
	if (!to_find[i])
		return ((char *)str);
	while (str[i])
	{
		n = 0;
		while (to_find[n] == str[i + n])
		{
			if (to_find[n + 1] == '\0')
				return ((char *)str + i);
			n++;
		}
		i++;
	}
	return (0);
}
