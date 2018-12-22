#include "../includes/fract_ol.h"


void	main_fractal_tree(t_all *all)
{
	all->fractnumb = 9;
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
	fractal_tree(&all->coord, &*all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	mlx_mouse_hook(all->win, mlx_funct_mouse, &*all);
	mlx_hook(all->win, 2, 3, mlx_funct_key, &*all);
	mlx_hook(all->win, 6, 64, mlx_hook_mov, &*all);
	mlx_hook(all->win, 17, (1L << 17), mlx_close, &*all);
	menu(&*all);
	mlx_loop(all->mlx);
}/*reprendre la fonction draw_line
 dans fdf pour pouvoir dessiner une line.*/