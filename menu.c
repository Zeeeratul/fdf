/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:10:46 by frrobert          #+#    #+#             */
/*   Updated: 2018/12/14 12:45:14 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_env *env)
{
	mlx_string_put(env->ptr, env->win, WIN_WIDTH - 500,
			WIN_HEIGHT - 80, 0xFFFF00, "R G B I key for color");
	mlx_string_put(env->ptr, env->win, 10, 10, 0xFF0000, "Press esc to quit ");
	mlx_string_put(env->ptr, env->win, WIN_WIDTH - 500,
			WIN_HEIGHT - 120, 0xFFFFFF, "Press up down left right to move map");
	mlx_string_put(env->ptr, env->win,
			WIN_WIDTH - 500, WIN_HEIGHT - 160, 0xFFFFFF,
			"Press + - to increase decrease altitude");
	mlx_string_put(env->ptr, env->win, WIN_WIDTH - 500,
			WIN_HEIGHT - 200, 0xFFFFFF, "Press space to change view");
	mlx_string_put(env->ptr, env->win, WIN_WIDTH - 500,
			WIN_HEIGHT - 240, 0xFFFFFF, "Use mouse scrolling to zoom / dezoom");
}
