/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:25:12 by anttran           #+#    #+#             */
/*   Updated: 2019/01/06 13:59:36 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_new_line(char **s, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len])
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = s[fd];
		s[fd] = ft_strdup(tmp + len + 1);
		free(tmp);
		if (!s[fd][0])
			ft_strdel(&s[fd]);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[4064];
	char		*buf;
	char		*tmp;
	int			ret;

	buf = (char*)ft_memalloc(sizeof(char) * (9000 + 1));
	while ((ret = read(fd, buf, 9000)) > 0)
	{
		if (!s[fd])
			s[fd] = ft_strnew(1);
		tmp = s[fd];
		s[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
		ft_strdel(&buf);
		buf = (char*)ft_memalloc(sizeof(char) * (9000 + 1));
	}
	ft_strdel(&buf);
	if (fd < 0 || !line || ret < 0)
		return (-1);
	return (!s[fd] ? 0 : ft_new_line(s, line, fd));
}
