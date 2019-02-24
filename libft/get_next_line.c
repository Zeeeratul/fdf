/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:35:11 by frrobert          #+#    #+#             */
/*   Updated: 2018/12/03 14:52:42 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_error(int fd, char **line)
{
	if (fd < 0 || line == NULL)
		return (-1);
	return (0);
}

static int			attribute_line(char **line, char **save, int fd)
{
	int		len;
	char	*temp;

	len = 0;
	while (save[fd][len] != '\n' && save[fd][len] != '\0')
		len++;
	if (save[fd][len] == '\0')
	{
		*line = ft_strdup(save[fd]);
		ft_strdel(&save[fd]);
	}
	else if (save[fd][len] == '\n')
	{
		*line = ft_strsub(save[fd], 0, len);
		temp = ft_strdup(save[fd] + len + 1);
		free(save[fd]);
		save[fd] = temp;
		if (save[fd][0] == '\0')
			ft_strdel(&save[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*save[256];
	char			*temp;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (check_error(fd, line) == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strnew(1);
		temp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		save[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && ((save[fd] == NULL || save[fd][0] == '\0')))
		return (0);
	attribute_line(line, save, fd);
	return (1);
}
