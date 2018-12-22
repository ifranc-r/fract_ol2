/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 14:43:55 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/05/18 14:43:57 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	main_mandelbrot(t_all *all)
{
	all->fractnumb = 2;
	all->coord.stop = 1;
	all->coord.mousex1 = 0;
	all->coord.iteration = 40;
	all->coord.mousey1 = 0;
	all->coord.zoom = 200;
	all->coord.mousey = 0;
	all->coord.mousex = 0;
	all->coord.mousezx = 0;
	all->coord.mousezy = 0;
	all->coord.r = 153;
	all->coord.g = 102;
	all->coord.b = 0;
	mandelbrot(&all->coord, &*all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	menu(&*all);
	mlx_mouse_hook(all->win, mlx_funct_mouse, &*all);
	mlx_hook(all->win, 2, 3, mlx_funct_key, &*all);
	mlx_hook(all->win, 6, 64, mlx_hook_mov, &*all);
	mlx_hook(all->win, 17, (1L << 17), mlx_close, &*all);
	mlx_loop(all->mlx);
}

void	init_mandelbrot(t_coord *coord)
{
	coord->x = 0;
	coord->y = 0;
	if ((coord->mousezx) && (coord->mousezy))
	{
		coord->x1 = coord->mousezx;
		coord->y1 = coord->mousezy;
	}
	else
	{
		coord->x1 = -2.1 + coord->mousex1;
		coord->y1 = -1.5 + coord->mousey1;
	}
}

void	init_mandelbrot2(t_coord *coord)
{
	coord->c_r = (coord->x / coord->zoom) + coord->x1;
	coord->c_i = (coord->y / coord->zoom) + coord->y1;
	coord->z_r = 0 + coord->mousex;
	coord->z_i = 0 + coord->mousey;
	coord->i = 0;
}

void	mandelbrot_c(t_coord *coord, t_all *all)
{
	if (coord->i == coord->iteration)
		set_color(coord->r, sin(coord->g), cos(coord->b), &all->color);
	else
		set_color(coord->r, coord->g, coord->i * 255 / tan(coord->iteration),\
			&all->color);
}

void	mandelbrot(t_coord *coord, t_all *all)
{
	init_mandelbrot(&*coord);
	coord->x = -1;
	while (++coord->x < I_X)
	{
		coord->y = -1;
		while (++coord->y < I_Y)
		{
			init_mandelbrot2(&*coord);
			while ((coord->z_r * coord->z_r + coord->z_i * coord->z_i < 4) &&\
				(coord->i < coord->iteration))
			{
				coord->tmp = coord->z_r;
				coord->z_r = coord->z_r * coord->z_r - coord->z_i *\
				coord->z_i + coord->c_r;
				coord->z_i = 2 * coord->z_i * coord->tmp + coord->c_i;
				++coord->i;
			}
			mandelbrot_c(&*coord, &*all);
			mlx_pixel_put_image(coord->x, coord->y, &*all);
		}
	}
}
