/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 01:10:47 by mbennis           #+#    #+#             */
/*   Updated: 2018/12/12 17:23:30 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_savermnd(char **line, char **rmnd, const int fd)
{
	unsigned int		len;
	char				*tmp;

	if (!rmnd[fd] || rmnd[fd][0] == '\0')
		return (0);
	if (!(ft_strchr(rmnd[fd], 10)))
	{
		*line = ft_strdup(rmnd[fd]);
		ft_strdel(&rmnd[fd]);
	}
	else if (ft_strchr(rmnd[fd], 10))
	{
		len = 0;
		while (rmnd[fd][len] != '\n')
			len++;
		if (!(*line = ft_strsub(rmnd[fd], 0, len)))
			return (-1);
		if (!(tmp = ft_strsub(rmnd[fd], len + 1, ft_strlen(rmnd[fd]) - len
																		- 1)))
			return (-1);
		free(rmnd[fd]);
		rmnd[fd] = tmp;
	}
	return (1);
}

int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	ssize_t				ret;
	static char			*rmnd[4896];
	char				*tmp;

	if (line == NULL || fd < 0 || fd > 4895 || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!rmnd[fd])
		{
			if (!(rmnd[fd] = ft_strnew(0)))
				return (-1);
		}
		if (!(tmp = ft_strjoin(rmnd[fd], buf)))
			return (-1);
		free(rmnd[fd]);
		rmnd[fd] = tmp;
		if (ft_strchr(buf, 10))
			break ;
	}
	return (ft_savermnd(&*line, rmnd, fd));
}
