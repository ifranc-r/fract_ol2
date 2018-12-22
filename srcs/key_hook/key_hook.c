/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 13:05:58 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/11/23 14:35:26 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void 	get_fract(t_all	*all)
{
	mlx_clear_window(all->mlx, all->win);
	if (all->fractnumb == 1)
		julia(&all->coord, &*all);
	if (all->fractnumb == 2)
		mandelbrot(&all->coord, &*all);
	if (all->fractnumb == 3)
		burningship(&all->coord, &*all);
	if (all->fractnumb == 4)
		yolo(&all->coord, &*all);
	if (all->fractnumb == 5)
		shiva(&all->coord, &*all);
	if (all->fractnumb == 6)
		hotblood(&all->coord, &*all);
	if (all->fractnumb == 7)
		goldenratio(&all->coord, &*all);
	if (all->fractnumb == 8)
		tricorn(&all->coord, &*all);
}

static t_callfract	*restfract(void)
{
	static t_callfract	tmp[N_CALL] = {
		{ 18, main_julia },
		{ 19, main_mandelbrot },
		{ 20, main_burningship },
		{ 21, main_yolo },
		{ 23, main_shiva },
		{ 22, main_hotblood },
		{ 26, main_goldenratio },
		{ 28, main_tricorn },
	};

	return (tmp);
}

void				reset_fract(t_all *all, int key)
{
	static t_callfract	*resfract;
	int					i;

	i = 0;
	resfract = restfract();
	while (i < N_CALL)
	{
		if (key == resfract[i].number)
			resfract[i].fct(&*all);
		i++;
	}

	if (key == 53)
	{
		mlx_destroy_window(all->mlx, all->win);
		mlx_destroy_image(all->mlx, all->img.img);
		exit((int)all->mlx);
	}
}

int					mlx_funct_key(int keycode, t_all *all)
{
	keycode == 257 ? ++all->m : 0;
	keycode == 24 ? ++all->coord.iteration : 0;
	keycode == 27 && all->coord.iteration > 1 ?\
	--all->coord.iteration : 0;
	keycode == 49 ? ++all->coord.stop : 0;

	keycode == PLUS_RED && all->coord.r < 255 ? all->coord.r += 1 : 0;
	keycode == LESS_RED && all->coord.r > 0 ? all->coord.r -= 1 : 0;
	keycode == PLUS_GREEN && all->coord.g < 255 ? all->coord.g += 1 : 0;
	keycode == LESS_GREEN && all->coord.g > 0 ? all->coord.g -= 1 : 0;
	keycode == PLUS_BLUE && all->coord.b < 255 ? all->coord.b += 1 : 0;
	keycode == LESS_BLUE && all->coord.b > 0 ? all->coord.b -= 1 : 0;
	if (keycode == ARROW_RIGHT)
		all->coord.mousezx = all->coord.x1 + (20 / all->coord.zoom);
	else if (keycode == ARROW_LEFT)
		all->coord.mousezx = all->coord.x1 - (20 / all->coord.zoom);
	else if (keycode == ARROW_UP)
		all->coord.mousezy = all->coord.y1 + (20 / all->coord.zoom);
	else if (keycode == ARROW_DOWN)
		all->coord.mousezy = all->coord.y1 - (20 / all->coord.zoom);
	mlx_funct(keycode, &*all);
	reset_fract(&*all, keycode);
	get_fract(&*all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	menu(&*all);
	return (0);
}
