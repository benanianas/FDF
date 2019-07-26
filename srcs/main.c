/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:11:50 by abenani           #+#    #+#             */
/*   Updated: 2019/07/13 21:49:40 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	msg_error(void)
{
	ft_putendl("Sorry, we found wrong line length. by");
	exit(0);
}

void	*call_img(t_ptr ptr, t_data *var)
{
	t_img		*img;

	img = (t_img*)malloc(sizeof(t_img));
	img->ptr = mlx_new_image(ptr.mlx, IMG_W, IMG_H);
	img->tab = (int*)mlx_get_data_addr(img->ptr, &img->bpp,
			&img->s_l, &img->edn);
	drawing_map(var, img);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img->ptr, 300, 0);
	return (img);
}

void	start(t_data *var)
{
	var->dc.zoom = 0;
	var->dc.rot = 0.0174533;
	var->dc.mvx = 0;
	var->dc.mvy = 0;
	var->dc.p = 0;
	var->dc.r = 0;
	var->dc.l = 1;
	var->dc.c = 0;
}

void	window_legend(t_ptr ptr)
{
	mlx_string_put(ptr.mlx, ptr.win, 30, 40, 0x1fffcb,
			"Press ESC to exit");
	mlx_string_put(ptr.mlx, ptr.win, 30, 200, 0x1fffcb,
			"I : Isometric Projection");
	mlx_string_put(ptr.mlx, ptr.win, 30, 230, 0x1fffcb,
			"P : Parallel Projection");
	mlx_string_put(ptr.mlx, ptr.win, 30, 290, 0x1fffcb,
			"Press + to rotate UP");
	mlx_string_put(ptr.mlx, ptr.win, 30, 320, 0x1fffcb,
			"Press - to rotate DOWN");
	mlx_string_put(ptr.mlx, ptr.win, 30, 380, 0x1fffcb,
			"W to increase the altitude");
	mlx_string_put(ptr.mlx, ptr.win, 30, 410, 0x1fffcb,
			"S to decrease the altitude");
	mlx_string_put(ptr.mlx, ptr.win, 30, 470, 0x1fffcb,
			"Scroll up to Zoom IN");
	mlx_string_put(ptr.mlx, ptr.win, 30, 500, 0x1fffcb,
			"Scroll down to Zoom Out");
	mlx_string_put(ptr.mlx, ptr.win, 30, 560, 0x1fffcb,
			"Use Arrows to move the map");
}

int		main(int argc, char **argv)
{
	t_data		*var;
	t_ptr		ptr;
	t_event		event;

	if (argc != 2)
		ft_putendl("Usage : ./fdf <filename> [ map data ]");
	else
	{
		var = check_map(argv[1]);
		if (!var->check)
			msg_error();
		ptr.mlx = mlx_init();
		ptr.win = mlx_new_window(ptr.mlx, 1300, 800, "FDF");
		event.ptr.mlx = ptr.mlx;
		event.ptr.win = ptr.win;
		start(var);
		window_legend(ptr);
		event.img = call_img(ptr, var);
		event.var = var;
		mlx_hook(ptr.win, 2, 0, key_press, (void*)&event);
		mlx_hook(ptr.win, 4, 0, mouse_press, (void*)&event);
		mlx_loop(ptr.mlx);
	}
}
