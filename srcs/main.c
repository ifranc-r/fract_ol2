/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:35:46 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/11/23 10:37:45 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void				show(void)
{
	ft_putendl_fd(" 			maps avaible :", 2);
	ft_putendl_fd("			1		julia", 2);
	ft_putendl_fd("			2		mandelbrot", 2);
	ft_putendl_fd("			3		burningship", 2);
	ft_putendl_fd("			4		yolo", 2);
	ft_putendl_fd("			5		shiva", 2);
	ft_putendl_fd("			6		hotblood", 2);
	ft_putendl_fd("			7		goldenratio", 2);
	ft_putendl_fd("			8		tricorn", 2);
	ft_putendl_fd("			9		tree", 2);
}

void				show2(void)
{
	ft_putendl_fd("=================== FRACT_OL ===============\n", 2);
	ft_putendl_fd("########### HERE A LITTLE TUTO #############\n", 2);
	ft_putendl_fd("******************* COLORS *****************\n", 2);
	ft_putendl_fd(" 	r = more RED\n	t = less RED\n    g = more GREEN", 2);
	ft_putendl_fd("    h = less GREEN\n b = more BLUE\n n = less BLUE\n", 2);
	ft_putendl_fd("___________________FORMS____________________\n", 2);
	ft_putendl_fd("           + = more ITERATION", 2);
	ft_putendl_fd("           - = less ITERATION", 2);
	ft_putendl_fd("     SPACE = MODE CHANG of c >ON< and >OFF<", 2);
	ft_putendl_fd("  When MODE CHANG is >ON< move the mouse for ", 2);
	ft_putendl_fd("	   	modify your fractol \n", 2);
	ft_putendl_fd(">>>>>>>>>>>>>>>> MOVEMENT <<<<<<<<<<<<<<<<<<<\n", 2);
	ft_putendl_fd(" Roll the mouse for ZOOMING and ZOOMING BACK.", 2);
	ft_putendl_fd("  Press the key right, up, down and left ", 2);
	ft_putendl_fd("        for move into the fractol.\n", 2);
	ft_putendl_fd("------------------ SWIPING -----------------\n", 2);
	ft_putendl_fd("You can swip all the fractols by using the key", 2);
	ft_putendl_fd("number:\n1 = Julia 2 = mandelbrot 3 = Burningship", 2);
	ft_putendl_fd("4 = Yolo 5 = Shiva 6 = Hotblood", 2);
	ft_putendl_fd("	7 = Goldenratio 8 = tricorn\n", 2);
	ft_putendl_fd("	for my dears correctors !\n	Kiss and love ;) ", 2);
}

static t_callback	*callback(void)
{
	static t_callback tmp[N_CALL] = {
		{ "julia", main_julia },
		{ "mandelbrot", main_mandelbrot },
		{ "burningship", main_burningship },
		{ "yolo", main_yolo },
		{ "shiva", main_shiva },
		{ "hotblood", main_hotblood },
		{ "goldenratio", main_goldenratio },
		{ "tricorn", main_tricorn },
	};

	return (tmp);
}

int					main(int argc, char **argv)
{
	t_all				all;
	static t_callback	*tab;
	int					i;

	i = -1;
	tab = callback();
	all.m = 1;
	if (argc == 2)
	{
		init_mlx(&all);
		all.img.data = mlx_get_data_addr(all.img.img, &all.img.bitpx,\
			&all.img.size, &all.img.endian);
		show2();
		while (++i < (N_CALL))
		{
			if (ft_strcmp(argv[1], tab[i].s) == 0)
				tab[i].fct(&all);
		}
	}
	else
		show();
	return (0);
}
