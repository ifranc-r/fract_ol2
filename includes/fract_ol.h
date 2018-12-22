/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:37:14 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/11/23 10:20:33 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include <math.h> //2560 x 1600
# define WIN_X 600
# define WIN_Y 600
# define I_X 600
# define I_Y 600
# define PI 3.14159265359
# define N_CALL 8
# define ARROW_UP 125
# define ARROW_DOWN 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define PLUS_RED 15
# define LESS_RED 17
# define PLUS_BLUE 11
# define LESS_BLUE 45
# define PLUS_GREEN 5
# define LESS_GREEN 4

typedef struct		s_color
{
	int				red;
	int				blue;
	int				green;
	int				alpha;
}					t_color;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				r;
	int				g;
	int				b;
	double			x_r;
	double			y_r;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	double			mousex;
	double			mousey;
	double			mousex1;
	double			mousey1;
	double			mousezy;
	double			mousezx;
	int				i;
	int				stop;
	int				iteration;
	double			zoom;
}					t_coord;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bitpx;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_all
{
	struct s_coord	coord;
	struct s_color	color;
	struct s_img	img;
	void			*mlx;
	void			*win;
	int				fractnumb;
	int				m;
}					t_all;

typedef struct		s_callback
{
	char			*s;
	void			(*fct)(t_all *);
}					t_callback;

typedef struct		s_callfract
{
	int				number;
	void			(*fct)(t_all *);
}					t_callfract;

void				menu_itoa(t_all *all);
void				mlx_funct(int keycode, t_all *all);
int					mlx_close(int keycode, t_all *all);
void				menu_charac(t_all *all);
void				get_fract(t_all *all);
void				main_tricorn(t_all *all);
void				tricorn(t_coord *coord, t_all *all);
void				main_goldenratio(t_all *all);
void				goldenratio(t_coord *coord, t_all *all);
void				hotblood(t_coord *coord, t_all *all);
void				main_hotblood(t_all *all);
void				shiva(t_coord *coord, t_all *all);
void				main_shiva(t_all *all);
void				yolo(t_coord *coord, t_all *all);
void				main_yolo(t_all *all);
void				main_burningship(t_all *all);
void				main_mandelbrot(t_all *all);
int					mlx_hook_mov(int x, int y, t_all *all);
void				main_julia(t_all *all);
int					mlx_funct_mouse(int keymouse, int x, int y, t_all *all);
void				mlx_pixel_put_image(int x, int y, t_all *all);
void				init_mlx(t_all *all);
void				set_color(int red, int green, int blue, t_color *color);
int					mlx_funct_key(int keycode, t_all *all);
void				mandelbrot(t_coord *coord, t_all *all);
void				init_mandelbrot2(t_coord *coord);
void				init_mandelbrot(t_coord *coord);
void				init_julia(t_coord *coord);
void				init_julia2(t_coord *coord);
void				julia(t_coord *coord, t_all *all);
void				burningship(t_coord *coord, t_all *all);
void				init_burningship2(t_coord *coord);
void				init_burningship(t_coord *coord);
void				menu(t_all *all);

#endif
