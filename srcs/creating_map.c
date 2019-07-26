/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@45.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 5019/07/05 14:15:55 by abenani           #+#    #+#             */
/*   Updated: 2019/07/13 13:08:29 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	net_creation(t_data *var, t_img *img, t_dm dm)
{
	dm.a.x = var->crd[dm.i][dm.j].x * dm.ds;
	dm.a.y = var->crd[dm.i][dm.j].y * dm.ds;
	dm.b.x = var->crd[dm.i][dm.j + 1].x * dm.ds;
	dm.b.y = var->crd[dm.i][dm.j + 1].y * dm.ds;
	dm.c.x = var->crd[dm.i + 1][dm.j].x * dm.ds;
	dm.c.y = var->crd[dm.i + 1][dm.j].y * dm.ds;
	projection_net(var->dc.p, &dm.a, &dm.b, &dm.c);
	rotation_net(var->dc.r, &dm.a, &dm.b, &dm.c);
	dm.a.y -= (var->map[dm.i][dm.j] * var->dc.l) * dm.ds;
	dm.b.y -= (var->map[dm.i][dm.j + 1] * var->dc.l) * dm.ds;
	dm.c.y -= (var->map[dm.i + 1][dm.j] * var->dc.l) * dm.ds;
	dm.a.x += dm.mvx;
	dm.a.y += dm.mvy;
	dm.b.x += dm.mvx;
	dm.b.y += dm.mvy;
	dm.c.x += dm.mvx;
	dm.c.y += dm.mvy;
	draw_line(img, dm.a, dm.b, var->colors[dm.i][dm.j] + var->dc.c);
	draw_line(img, dm.a, dm.c, var->colors[dm.i][dm.j] + var->dc.c);
}

void	buttom_line(t_data *var, t_img *img, t_dm dm)
{
	dm.i = var->y - 1;
	dm.j = 0;
	while (dm.j < var->x - 1)
	{
		dm.a.x = var->crd[dm.i][dm.j].x * dm.ds;
		dm.a.y = var->crd[dm.i][dm.j].y * dm.ds;
		dm.b.x = var->crd[dm.i][dm.j + 1].x * dm.ds;
		dm.b.y = var->crd[dm.i][dm.j + 1].y * dm.ds;
		projection_line(var->dc.p, &dm.a, &dm.b);
		rotation_line(var->dc.r, &dm.a, &dm.b);
		dm.a.y -= (var->map[dm.i][dm.j] * var->dc.l) * dm.ds;
		dm.b.y -= (var->map[dm.i][dm.j + 1] * var->dc.l) * dm.ds;
		dm.a.x += dm.mvx;
		dm.a.y += dm.mvy;
		dm.b.x += dm.mvx;
		dm.b.y += dm.mvy;
		draw_line(img, dm.a, dm.b, var->colors[dm.i][dm.j] + var->dc.c);
		dm.j++;
	}
}

void	right_line(t_data *var, t_img *img, t_dm dm)
{
	dm.i = 0;
	dm.j = var->x - 1;
	while (dm.i < var->y - 1)
	{
		dm.a.x = var->crd[dm.i][dm.j].x * dm.ds;
		dm.a.y = var->crd[dm.i][dm.j].y * dm.ds;
		dm.b.x = var->crd[dm.i + 1][dm.j].x * dm.ds;
		dm.b.y = var->crd[dm.i + 1][dm.j].y * dm.ds;
		projection_line(var->dc.p, &dm.a, &dm.b);
		rotation_line(var->dc.r, &dm.a, &dm.b);
		dm.a.y -= (var->map[dm.i][dm.j] * var->dc.l) * dm.ds;
		dm.b.y -= (var->map[dm.i + 1][dm.j] * var->dc.l) * dm.ds;
		dm.a.x += dm.mvx;
		dm.a.y += dm.mvy;
		dm.b.x += dm.mvx;
		dm.b.y += dm.mvy;
		draw_line(img, dm.a, dm.b, var->colors[dm.i][dm.j] + var->dc.c);
		dm.i++;
	}
}

int		dis(t_data *var)
{
	int ret;
	int ret1;

	ret = 500 / var->x;
	ret1 = 400 / var->y;
	if (ret1 < ret)
		ret = ret1;
	if (ret < 1)
		return (1);
	else
		return (ret);
}

void	drawing_map(t_data *var, t_img *img)
{
	t_dm	dm;

	dm.ds = dis(var) + var->dc.zoom;
	if (dm.ds < 1)
	{
		dm.ds = 1;
		var->dc.zoom++;
	}
	dm.i = 0;
	dm.mvx = 500 + var->dc.mvx;
	dm.mvy = 400 + var->dc.mvy;
	while (dm.i < var->y - 1)
	{
		dm.j = -1;
		while (++dm.j < var->x - 1)
			net_creation(var, img, dm);
		dm.i++;
	}
	buttom_line(var, img, dm);
	right_line(var, img, dm);
}
