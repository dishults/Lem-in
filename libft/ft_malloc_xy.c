/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:41:42 by dshults           #+#    #+#             */
/*   Updated: 2018/05/28 14:41:43 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_xy(size_t x, size_t y)
{
	char	**map;
	size_t	yy;

	yy = 0;
	map = (char **)malloc(sizeof(char *) * y);
	while (yy < y)
	{
		map[yy] = (char *)malloc(sizeof(char) * x);
		yy++;
	}
	return (map);
}
