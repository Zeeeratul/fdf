/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:55:28 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/14 13:00:39 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max_value(char **buf)
{
	int i;
	int max;
	int temp;

	i = 0;
	max = -21478648;
	while (buf[i] != NULL)
	{
		temp = ft_atoi(buf[i]);
		if (temp > max)
			max = temp;
		i++;
	}
	return (max);
}

void	calcule_space(t_env *env)
{
	if (env->map.nb_cols <= 20)
		env->point.space = 25;
	else if (env->map.nb_cols >= 20 && env->map.nb_cols <= 50)
		env->point.space = 20;
	else if (env->map.nb_cols >= 50 && env->map.nb_cols <= 100)
		env->point.space = 15;
	else if (env->map.nb_cols >= 100 && env->map.nb_cols <= 200)
		env->point.space = 5;
	else
		env->point.space = 1;
}

void	init(t_env *env)
{
	env->ptr = mlx_init();
	env->win = mlx_new_window(env->ptr, WIN_WIDTH, WIN_HEIGHT, "Fdf");
	env->point.pos = 0;
	env->point.cte = env->point.max_value / 200.00;
	env->point.alt_iso = 1.0;
	env->color.red = 255;
	env->color.green = 255;
	env->color.blue = 255;
	env->color.color = 0;
	calcule_space(env);
	env->img.right_left = (WIN_WIDTH / 2) - (env->map.nb_cols *
	env->point.space / 2);
	env->img.up_down = (WIN_HEIGHT / 2) - (env->map.nb_lines
	* env->point.space / 2);
}

int		fdf(t_env *env)
{
	init(env);
	mlx_key_hook(env->win, &deal_key, env);
	mlx_mouse_hook(env->win, &deal_mouse, env);
	mlx_expose_hook(env->win, ft_expose_hook, env);
	mlx_loop(env->ptr);
	return (0);
}
