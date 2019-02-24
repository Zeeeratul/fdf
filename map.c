/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:42:11 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/14 13:38:37 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_env *env)
{
	int j;

	j = 0;
	while (j < env->map.nb_lines)
	{
		ft_memdel((void**)env->map.map[j]);
		j++;
	}
	ft_memdel((void**)env->map.map);
}

void	attribute_line(t_env *env, int j, int fd)
{
	int		i;
	int		k;
	char	*line;
	char	**buf;

	get_next_line(fd, &line);
	buf = ft_strsplit(line, ' ');
	free(line);
	if (max_value(buf) > env->point.max_value)
		env->point.max_value = max_value(buf);
	i = 0;
	k = 0;
	while (buf[i] != NULL)
	{
		env->map.map[j][i] = ft_atoi(buf[i]);
		free(buf[i]);
		i++;
	}
	free(buf);
}

int		attribute_map(t_env *env, int fd)
{
	int		j;

	j = 0;
	if (!(env->map.map = (int**)malloc(sizeof(int*) * env->map.nb_cols)))
		return (-1);
	env->point.max_value = 0;
	while (j < env->map.nb_lines)
	{
		if (!(env->map.map[j] = (int*)malloc(sizeof(int) * env->map.nb_cols)))
			return (-1);
		attribute_line(env, j, fd);
		j++;
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int		valid_map(int fd, t_env *env, int i, int j)
{
	int		temp;
	char	*line;
	char	**buf;

	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		buf = ft_strsplit(line, ' ');
		free(line);
		while (buf[i] != NULL)
		{
			free(buf[i]);
			i++;
		}
		free(buf);
		if (j != 0 && temp != i)
			return (-1);
		temp = i;
		j++;
	}
	env->map.nb_cols = i;
	env->map.nb_lines = j;
	return (0);
}

int		create_map(t_env *env, char *name_file)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((fd = open(name_file, O_RDONLY)) == -1)
		return (-1);
	if (valid_map(fd, env, j, i) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	if ((fd = open(name_file, O_RDONLY)) == -1)
		return (-1);
	if (attribute_map(env, fd) == -1)
	{
		free_map(env);
		return (-1);
	}
	return (0);
}
