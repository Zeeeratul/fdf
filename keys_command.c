/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:10:02 by frrobert          #+#    #+#             */
/*   Updated: 2018/12/14 12:43:55 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_color(int key, t_env *env)
{
	if (key == 15)
		env->color.color = 1;
	if (key == 11)
		env->color.color = 2;
	if (key == 5)
		env->color.color = 3;
	if (key == 34)
		env->color.color = 4;
}

void	ft_key_move(int key, t_env *env)
{
	if (key == 123)
		env->img.right_left -= 25;
	if (key == 124)
		env->img.right_left += 25;
	if (key == 125)
		env->img.up_down += 25;
	if (key == 126)
		env->img.up_down -= 25;
}

void	ft_key_position(t_env *env)
{
	if (env->point.pos == 0)
		env->point.pos = 1;
	else if (env->point.pos == 1)
		env->point.pos = 0;
}

void	ft_key_alt(int key, t_env *env)
{
	if (key == 78)
	{
		if (env->point.pos == 0)
			env->point.cte *= 0.9;
		else if (env->point.pos == 1)
			env->point.alt_iso *= 0.90;
	}
	else if (key == 69)
	{
		if (env->point.pos == 0)
			env->point.cte /= 0.9;
		else if (env->point.pos == 1)
			env->point.alt_iso /= 0.90;
	}
}
