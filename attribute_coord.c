/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:23:24 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/09 15:10:44 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point_line(t_env *env, int j, int i, int alt)
{
	int coef;

	coef = env->point.space;
	if (env->point.pos == 0)
	{
		alt = (env->map.map[j][i] * -1);
		env->point.x1 = coef * (i + env->point.cte * alt);
		env->point.y1 = coef * (j + (env->point.cte / 2) * alt);
		i++;
		alt = (env->map.map[j][i] * -1);
		env->point.x2 = coef * (i + env->point.cte * alt);
		env->point.y2 = coef * (j + (env->point.cte / 2) * alt);
	}
	else if (env->point.pos == 1)
	{
		alt = (env->map.map[j][i] * -1);
		env->point.x1 = coef * ((0.5 * i) - (0.5 * j));
		env->point.y1 = coef * (alt * env->point.alt_iso + 0.25 * i + 0.25 * j);
		i++;
		alt = (env->map.map[j][i] * -1);
		env->point.x2 = coef * ((0.5 * i) - (0.5 * j));
		env->point.y2 = coef * (alt * env->point.alt_iso + 0.25 * i + 0.25 * j);
	}
}

void	point_cols(t_env *env, int j, int i, int alt)
{
	int coef;

	coef = env->point.space;
	if (env->point.pos == 0)
	{
		alt = (env->map.map[j][i] * -1);
		env->point.x1 = coef * (i + env->point.cte * alt);
		env->point.y1 = coef * (j + (env->point.cte / 2) * alt);
		j++;
		alt = (env->map.map[j][i] * -1);
		env->point.x2 = coef * (i + env->point.cte * alt);
		env->point.y2 = coef * (j + (env->point.cte / 2) * alt);
	}
	else if (env->point.pos == 1)
	{
		alt = (env->map.map[j][i] * -1);
		env->point.x1 = coef * ((0.5 * i) - (0.5 * j));
		env->point.y1 = coef * (alt * env->point.alt_iso + 0.25 * i + 0.25 * j);
		j++;
		alt = (env->map.map[j][i] * -1);
		env->point.x2 = coef * ((0.5 * i) - (0.5 * j));
		env->point.y2 = coef * (alt * env->point.alt_iso + 0.25 * i + 0.25 * j);
	}
}
