/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:58:39 by abenani           #+#    #+#             */
/*   Updated: 2019/07/20 16:24:30 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int keycode, void *param)
{
	t_event *event;

	event = (t_event*)param;
	if (keycode == 53)
	{
		free_all(event->var);
		free(event->img);
		exit(0);
	}
	if (keycode == 126)
		event->var->dc.mvy -= 8;
	if (keycode == 125)
		event->var->dc.mvy += 8;
	if (keycode == 124)
		event->var->dc.mvx += 8;
	if (keycode == 123)
		event->var->dc.mvx -= 8;
	if (keycode == 34)
	{
		event->var->dc.p = 1;
		event->var->dc.r = 0;
	}
	key_press2(keycode, event);
	redo(event);
	return (0);
}

void	key_press2(int keycode, t_event *event)
{
	if (keycode == 35)
	{
		event->var->dc.p = 0;
		event->var->dc.r = 0;
	}
	if (keycode == 78)
		event->var->dc.r += 0.0174533;
	if (keycode == 69)
		event->var->dc.r -= 0.0174533;
	if (keycode == 13)
		event->var->dc.l += 0.05;
	if (keycode == 1)
		event->var->dc.l -= 0.05;
	if (keycode == 8)
		event->var->dc.c += 5;
	if (keycode == 9)
		event->var->dc.c = 0;
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_event *event;

	event = (t_event*)param;
	y = x;
	if (button == 5)
		event->var->dc.zoom++;
	if (button == 4)
		event->var->dc.zoom--;
	redo(event);
	return (0);
}

void	redo(t_event *event)
{
	mlx_destroy_image(event->ptr.mlx, event->img->ptr);
	free(event->img);
	event->img = call_img(event->ptr, event->var);
}
