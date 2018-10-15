/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:30:41 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:30:42 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_strlenn(const char *str)
{
	int length;

	length = 0;
	if (str == NULL)
		return (0);
	else if (str[0] == '\0')
		return (-1);
	while (str[length])
	{
		length++;
	}
	return (length);
}

/*
**	Count the number of bytes needed
**	to convert wchar_t to UTF-8
**	in order to print it using char
**
**	127 2047 65537 1114111
*/

char		ft_chrlen_w(const wchar_t chr)
{
	char bytes;

	if (chr <= 0x7F)
		bytes = 1;
	else if (chr <= 0x7FF)
		bytes = 2;
	else if (chr <= 0xFFFF)
		bytes = 3;
	else if (chr <= 0x10FFFF)
		bytes = 4;
	else
		bytes = 0;
	return (bytes);
}

intmax_t	ft_strlen_w(const wchar_t *str)
{
	intmax_t	length;
	char		*str1;

	length = 0;
	str1 = (char *)str;
	if (str == NULL)
		return (0);
	else if (str1[0] == '\0')
		return (-1);
	while (*str)
	{
		length += ft_chrlen_w(*str);
		str++;
	}
	return (length);
}
