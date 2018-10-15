/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:32:33 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:32:34 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh_str;

	if (!(fresh_str = (char *)malloc(size + 1)))
		return (0);
	ft_bzero(fresh_str, size + 1);
	return (fresh_str);
}
