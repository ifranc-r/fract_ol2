/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:35:46 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/25 17:35:56 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	menu(t_all *all)
{
	if (!(all->m % 2))
	{
		mlx_string_put(all->mlx, all->win, 60, 4, 0xFF0000,\
			ft_itoa(all->coord.r));
		mlx_string_put(all->mlx, all->win, 60, 20, 0x00FF00,\
			ft_itoa(all->coord.g));
		mlx_string_put(all->mlx, all->win, 60, 40, 0x0000FF,\
			ft_itoa(all->coord.b));
		mlx_string_put(all->mlx, all->win, 110, 60, 0xFFFFFF,\
			ft_itoa(all->coord.iteration));
		mlx_string_put(all->mlx, all->win, 110, 80, 0xFFFFFF,\
			ft_itoa((int)all->coord.zoom));
		menu_charac(&*all);
	}
	else
		mlx_string_put(all->mlx, all->win, 3, 4, 0xFF0FF0, "Press shift");
}

void	menu_charac(t_all *all)
{
	mlx_string_put(all->mlx, all->win, 3, 4, 0xFF0000, "RED:");
	mlx_string_put(all->mlx, all->win, 3, 20, 0x00FF00, "GREEN:");
	mlx_string_put(all->mlx, all->win, 3, 40, 0x0000FF, "BLEU:");
	mlx_string_put(all->mlx, all->win, 3, 60, 0xFFFFFF, "iteration:");
	mlx_string_put(all->mlx, all->win, 3, 80, 0xFFFFFF, "zoom:");
	mlx_string_put(all->mlx, all->win, 3, 100, 0xFFFFFF, "n img:");
	mlx_string_put(all->mlx, all->win, 3, 120, 0xFFFFFF, "n real:");
	mlx_string_put(all->mlx, all->win, 110, 100, 0xFFFFFF,\
		ft_ditoa(all->coord.c_i, 6));
	mlx_string_put(all->mlx, all->win, 110, 120, 0xFFFFFF,\
		ft_ditoa(all->coord.c_r, 6));
}

void	menu_itoa(t_all *all)
{
	mlx_string_put(all->mlx, all->win, 110, 100, 0xFFFFFF,\
		ft_ditoa(all->coord.c_i, 6));
	mlx_string_put(all->mlx, all->win, 110, 120, 0xFFFFFF,\
		ft_ditoa(all->coord.c_r, 6));
	mlx_string_put(all->mlx, all->win, 110, 140, 0xFFFFFF,\
		ft_ditoa(all->coord.z_i, 6));
	mlx_string_put(all->mlx, all->win, 110, 160, 0xFFFFFF,\
		ft_ditoa(all->coord.z_r, 6));
	mlx_string_put(all->mlx, all->win, 110, 180, 0xFFFFFF,\
		ft_ditoa(all->coord.x1, 6));
	mlx_string_put(all->mlx, all->win, 110, 200, 0xFFFFFF,\
		ft_ditoa(all->coord.y1, 6));
	mlx_string_put(all->mlx, all->win, 110, 220, 0xFFFFFF,\
		ft_itoa(all->coord.x));
	mlx_string_put(all->mlx, all->win, 110, 240, 0xFFFFFF,\
		ft_itoa(all->coord.y));
}

int		mlx_close(int keycode, t_all *all)
{
	if (keycode)
		exit((int)all->mlx);
	return (0);
}
