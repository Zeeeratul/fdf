/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:37:08 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/09 12:49:27 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_single_lines(t_env *env, int j, int i)
{
	int alt;
	int alt2;

	while (i < env->map.nb_cols - 1)
	{
		alt = env->map.map[j][i];
		alt2 = env->map.map[j][i + 1];
		point_line(env, j, i, alt);
		i++;
		color_altitude(env, alt, alt2);
	}
}

void	draw_lines(t_env *env)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (j < env->map.nb_lines)
	{
		draw_single_lines(env, j, i);
		j++;
	}
}

void	draw_single_cols(t_env *env, int i, int j)
{
	int alt;
	int alt2;

	while (j < env->map.nb_lines - 1)
	{
		alt = env->map.map[j][i];
		alt2 = env->map.map[j + 1][i];
		point_cols(env, j, i, alt);
		j++;
		color_altitude(env, alt, alt2);
	}
}

void	draw_cols(t_env *env)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < env->map.nb_cols)
	{
		draw_single_cols(env, i, j);
		i++;
	}
}

void	draw(t_env *env)
{
	draw_lines(env);
	draw_cols(env);
}
