/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:40:41 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/29 16:04:11 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	init_mlx(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIN_X, WIN_Y, "fract_ol");
	all->img.img = mlx_new_image(all->mlx, I_X, I_Y);
}

void	set_color(int red, int green, int blue, t_color *color)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
	color->alpha = 0;
}

void	mlx_pixel_put_image(int x, int y, t_all *all)
{
	int		i;

	i = x * 4 + y * all->img.size;
	if (x >= 0 && y >= 0)
	{
		all->img.data[i] = all->color.blue;
		all->img.data[i + 1] = all->color.green;
		all->img.data[i + 2] = all->color.red;
		all->img.data[i + 3] = all->color.alpha;
	}
}
