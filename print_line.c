/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:15:03 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/14 13:41:54 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_env *env, int x, int y)
{
	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		env->img.data[(x * (env->img.bpp / 8)) +
			(y * env->img.size_l)] = env->color.blue;
		env->img.data[(x * (env->img.bpp / 8)) +
			(y * env->img.size_l) + 1] = env->color.green;
		env->img.data[(x * (env->img.bpp / 8)) +
			(y * env->img.size_l) + 2] = env->color.red;
	}
}

void	aigu_line(t_env *env, int xincr, int yincr)
{
	int ex;
	int ey;
	int dx;
	int dy;
	int i;

	ex = abs(env->point.x2 - env->point.x1);
	ey = abs(env->point.y2 - env->point.y1);
	dx = 2 * ex;
	dy = 2 * ey;
	i = 0;
	while (i <= (dx / 2))
	{
		ft_pixel_put(env, env->point.x1 + env->img.right_left,
				env->point.y1 + env->img.up_down);
		i++;
		env->point.x1 = env->point.x1 + xincr;
		ex = ex - dy;
		if (ex < 0)
		{
			env->point.y1 = env->point.y1 + yincr;
			ex = ex + dx;
		}
	}
}

void	obtu_line(t_env *env, int xincr, int yincr)
{
	int ex;
	int ey;
	int dx;
	int dy;
	int i;

	ex = abs(env->point.x2 - env->point.x1);
	ey = abs(env->point.y2 - env->point.y1);
	dx = 2 * ex;
	dy = 2 * ey;
	i = 0;
	while (i <= (dy / 2))
	{
		ft_pixel_put(env, env->point.x1 + env->img.right_left,
				env->point.y1 + env->img.up_down);
		i++;
		env->point.y1 = env->point.y1 + yincr;
		ey = ey - dx;
		if (ey < 0)
		{
			env->point.x1 = env->point.x1 + xincr;
			ey = ey + dy;
		}
	}
}

void	trace_line(t_env *env)
{
	int xincr;
	int yincr;

	xincr = 1;
	yincr = 1;
	if (env->point.x1 > env->point.x2)
		xincr = -1;
	if (env->point.y1 > env->point.y2)
		yincr = -1;
	if (abs(env->point.x2 - env->point.x1) > abs(env->point.y2 - env->point.y1))
		aigu_line(env, xincr, yincr);
	else
		obtu_line(env, xincr, yincr);
}
