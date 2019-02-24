/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:40:40 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/14 13:45:41 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "libft/libft.h"
# include "mlx_keycode.h"

# define WIN_WIDTH 2500
# define WIN_HEIGHT 1300

typedef struct	s_map
{
	int		**map;
	int		nb_cols;
	int		nb_lines;
}				t_map;

typedef struct	s_color
{
	int		color;
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_point
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		xincr;
	int		yincr;
	int		space;
	int		max_value;
	int		pos;
	float	alt_iso;
	float	cte;
}				t_point;

typedef struct	s_img
{
	void	*ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		right_left;
	int		up_down;
}				t_img;

typedef struct	s_env
{
	void	*ptr;
	void	*win;
	int		start_x;
	int		start_y;
	t_map	map;
	t_point	point;
	t_img	img;
	t_color	color;
}				t_env;

void			menu(t_env *env);
void			color_altitude(t_env *env, int alt, int alt2);
int				create_map(t_env *env, char *name_file);
void			free_map(t_env *env);
void			trace_line(t_env *env);
void			ft_pixel_put(t_env *env, int x, int y);
void			draw(t_env *env);
int				fdf(t_env *env);
int				deal_key(int key, t_env *env);
int				deal_mouse(int mousecode, int x, int y, t_env *env);
int				ft_expose_hook(t_env *env);
void			ft_key_move(int key, t_env *env);
void			ft_key_color(int key, t_env *env);
void			ft_key_position(t_env *env);
void			ft_key_alt(int key, t_env *env);
void			point_line(t_env *env, int j, int i, int alt);
void			point_cols(t_env *env, int j, int i, int alt);
int				max_value(char **buf);

#endif
