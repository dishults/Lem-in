/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:37:29 by dshults           #+#    #+#             */
/*   Updated: 2018/01/12 15:37:30 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void		ft_read(char **s, int fd, char **line, char *old)
{
	unsigned int	start;
	unsigned int	len;

	if (ft_strchr_no_zero(s[fd], '\n'))
	{
		len = (unsigned int)(ft_strchr_no_zero(s[fd], '\n') - s[fd]);
		*line = ft_strsub(s[fd], 0, len);
		start = len + 1;
		old = s[fd];
		s[fd] = ft_strsub(s[fd], start, ft_strlen(s[fd]) - start);
		free(old);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
}

int					get_next_line(const int fd, char **line)
{
	t_gnl			t;
	static char		**s;

	if (!line || fd < 0)
		return (-1);
	if (!s)
		s = (char **)malloc(sizeof(char *) * 4096 + 1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	while (!(ft_strchr_no_zero(s[fd], '\n')))
	{
		t.ret = read(fd, t.buffer, BUFF_SIZE);
		if (t.ret == -1)
			return (-1);
		else if (t.ret < 1)
			break ;
		t.buffer[t.ret] = '\0';
		t.old = s[fd];
		s[fd] = ft_strjoin(s[fd], t.buffer);
		free(t.old);
	}
	ft_read(s, fd, line, t.old);
	if (!s[fd] && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
