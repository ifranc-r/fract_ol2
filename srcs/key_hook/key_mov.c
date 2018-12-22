/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:13:00 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/11/23 14:13:05 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		mlx_funct_mouse(int keymouse, int x, int y, t_all *all)
{
	if (keymouse == 4)
	{
		all->coord.x_r = (x / all->coord.zoom) + all->coord.x1;
		all->coord.y_r = (y / all->coord.zoom) + all->coord.y1;
		all->coord.zoom *= 1.1;
		all->coord.mousezx = all->coord.x_r - (x / all->coord.zoom);
		all->coord.mousezy = all->coord.y_r - (y / all->coord.zoom);
		get_fract(&*all);
		mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
		menu(&*all);
	}
	if (keymouse == 5 && all->coord.zoom >= 0)
	{
		all->coord.x_r = (x / all->coord.zoom) + all->coord.x1;
		all->coord.y_r = (y / all->coord.zoom) + all->coord.y1;
		all->coord.zoom /= 1.1;
		all->coord.mousezx = all->coord.x_r - (x / all->coord.zoom);
		all->coord.mousezy = all->coord.y_r - (y / all->coord.zoom);
		get_fract(&*all);
		mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
		menu(&*all);
	}
	return (0);
}

int		mlx_hook_mov(int x, int y, t_all *all)
{
	t_coord coord;

	coord = all->coord;
	if (!(all->coord.stop % 2))
	{
		all->coord.mousex = ((double)x - (I_Y)) / 1000;
		all->coord.mousey = ((double)y - (I_Y / 2)) / 1000;
		get_fract(&*all);
		mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
		menu(&*all);
	}
	return (0);
}

void	mlx_funct(int keycode, t_all *all)
{
	if (keycode == ARROW_RIGHT)
		all->coord.mousezx = all->coord.x1 + (20 / all->coord.zoom);
	else if (keycode == ARROW_LEFT)
		all->coord.mousezx = all->coord.x1 - (20 / all->coord.zoom);
	else if (keycode == ARROW_UP)
		all->coord.mousezy = all->coord.y1 + (20 / all->coord.zoom);
	else if (keycode == ARROW_DOWN)
		all->coord.mousezy = all->coord.y1 - (20 / all->coord.zoom);
}
