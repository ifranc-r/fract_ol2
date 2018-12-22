/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goldenratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 14:31:48 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/05/18 14:31:49 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	main_goldenratio(t_all *all)
{
	all->fractnumb = 7;
	all->coord.r = 180;
	all->coord.g = 82;
	all->coord.b = 47;
	all->coord.stop = 1;
	all->coord.mousex1 = 0;
	all->coord.iteration = 40;
	all->coord.mousey1 = 0;
	all->coord.zoom = 200;
	all->coord.mousey = 0;
	all->coord.mousex = 0;
	all->coord.mousezx = 0;
	all->coord.mousezy = 0;
	goldenratio(&all->coord, &*all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	menu(&*all);
	mlx_mouse_hook(all->win, mlx_funct_mouse, &*all);
	mlx_hook(all->win, 2, 3, mlx_funct_key, &*all);
	mlx_hook(all->win, 6, 64, mlx_hook_mov, &*all);
	mlx_hook(all->win, 17, (1L << 17), mlx_close, &*all);
	mlx_loop(all->mlx);
}

void	init_goldenratio(t_all *all)
{
	all->coord.x = 0;
	all->coord.y = 0;
	if ((all->coord.mousezx) && (all->coord.mousezy))
	{
		all->coord.x1 = all->coord.mousezx;
		all->coord.y1 = all->coord.mousezy;
	}
	else
	{
		all->coord.x1 = -1.6 + all->coord.mousex1;
		all->coord.y1 = -1.3 + all->coord.mousey1;
	}
}

void	init_goldenratio2(t_coord *coord)
{
	coord->c_r = 0.378 + coord->mousex;
	coord->c_i = -0.226 + coord->mousey;
	coord->i = 0;
	coord->z_r = (coord->x / coord->zoom) + coord->x1;
	coord->z_i = (coord->y / coord->zoom) + coord->y1;
}

void	goldenratio_c(t_coord *coord, t_all *all)
{
	if (coord->i == coord->iteration)
		set_color(cos(coord->r), coord->g, sin(coord->b), &all->color);
	else
		set_color(coord->r, coord->i * 255 / coord->iteration,\
			coord->b, &all->color);
}

void	goldenratio(t_coord *coord, t_all *all)
{
	init_goldenratio(&*all);
	coord->x = -1;
	while (++coord->x < I_X)
	{
		coord->y = -1;
		while (++coord->y < I_Y)
		{
			init_goldenratio2(&*coord);
			while ((coord->z_r * coord->z_r + coord->z_i * coord->z_i < 4) &&\
				(coord->i < coord->iteration))
			{
				coord->tmp = coord->z_r;
				coord->z_r = (((1 + sqrt(5)) / 2) * (coord->z_r * coord->z_r))\
				- (((1 + sqrt(5)) / 2) * coord->z_i * coord->z_i) + coord->c_r;
				coord->z_i = ((1 + sqrt(5)) / 2) * coord->z_i *\
				coord->tmp + coord->c_i;
				++coord->i;
			}
			goldenratio_c(&*coord, &*all);
			mlx_pixel_put_image(coord->x, coord->y, &*all);
		}
	}
}
