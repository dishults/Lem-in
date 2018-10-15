/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:19:47 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:19:49 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh_mem;

	if (!(fresh_mem = (size_t *)malloc(size)) || size > 4294967295)
		return (0);
	else
		return (ft_memset(fresh_mem, 0, size));
}
