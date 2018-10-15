/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:37:40 by dshults           #+#    #+#             */
/*   Updated: 2018/01/12 15:37:42 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE  4096

typedef struct	s_gnl
{
	ssize_t		ret;
	char		*old;
	char		buffer[BUFF_SIZE + 1];
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
