/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_altitude.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 08:55:39 by frrobert          #+#    #+#             */
/*   Updated: 2018/12/09 13:17:41 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_red(t_env *env, int alt, int alt2)
{
	if (alt == 0 && alt2 == 0)
	{
		env->color.red = 255;
		env->color.green = 0;
		env->color.blue = 0;
	}
	else if (alt > 100)
	{
		env->color.red = 125;
		env->color.green = 0;
		env->color.blue = 125;
	}
	else
	{
		env->color.red = 255;
		env->color.green = 0;
		env->color.blue = 200;
	}
}

void	color_green(t_env *env, int alt, int alt2)
{
	if (alt == 0 && alt2 == 0)
	{
		env->color.red = 0;
		env->color.green = 255;
		env->color.blue = 0;
	}
	else if (alt > 100)
	{
		env->color.red = 0;
		env->color.green = 125;
		env->color.blue = 125;
	}
	else
	{
		env->color.red = 0;
		env->color.green = 255;
		env->color.blue = 200;
	}
}

void	color_blue(t_env *env, int alt, int alt2)
{
	if (alt == 0 && alt2 == 0)
	{
		env->color.red = 0;
		env->color.green = 0;
		env->color.blue = 255;
	}
	else if (alt > 100)
	{
		env->color.red = 75;
		env->color.green = 75;
		env->color.blue = 75;
	}
	else
	{
		env->color.red = 120;
		env->color.green = 70;
		env->color.blue = 255;
	}
}

void	color_real_map(t_env *env, int alt, int alt2)
{
	if (alt == 0 && alt2 == 0)
	{
		env->color.red = 65;
		env->color.green = 105;
		env->color.blue = 225;
	}
	else if (alt > 100)
	{
		env->color.red = 139;
		env->color.green = 69;
		env->color.blue = 19;
	}
	else
	{
		env->color.red = 127;
		env->color.green = 255;
		env->color.blue = 0;
	}
}

void	color_altitude(t_env *env, int alt, int alt2)
{
	if (env->color.color == 1)
		color_red(env, alt, alt2);
	else if (env->color.color == 2)
		color_green(env, alt, alt2);
	else if (env->color.color == 3)
		color_blue(env, alt, alt2);
	else if (env->color.color == 4)
		color_real_map(env, alt, alt2);
	trace_line(env);
}
