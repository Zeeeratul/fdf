/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:31:15 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/14 13:03:22 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_mouse(int mousecode, int x, int y, t_env *env)
{
	x = 0;
	y = 0;
	if (mousecode == 4)
		env->point.space += 10;
	else if (mousecode == 5)
	{
		env->point.space -= 10;
		if (env->point.space <= 0)
			env->point.space += 10;
	}
	ft_expose_hook(env);
	return (0);
}

int		deal_key(int key, t_env *env)
{
	if (key == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (key == 78 || key == 69)
		ft_key_alt(key, env);
	else if (key == R_KEY || key == G_KEY || key == B_KEY || key == I_KEY)
		ft_key_color(key, env);
	else if (key == LEFT_KEY || key == RIGHT_KEY || key == DOWN_KEY ||
				key == UP_KEY)
		ft_key_move(key, env);
	else if (key == SP_KEY)
		ft_key_position(env);
	ft_expose_hook(env);
	return (0);
}

int		ft_expose_hook(t_env *env)
{
	env->img.ptr = mlx_new_image(env->ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img.data = mlx_get_data_addr(env->img.ptr, &(env->img.bpp),
			&(env->img.size_l), &(env->img.endian));
	draw(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img.ptr, 0, 0);
	menu(env);
	mlx_destroy_image(env->ptr, env->img.ptr);
	return (0);
}
