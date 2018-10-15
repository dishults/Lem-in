/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:28:22 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:28:24 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& (unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0')
		i++;
	if ((unsigned char)s1[i] == '\0' && (unsigned char)s2[i] == '\0')
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
