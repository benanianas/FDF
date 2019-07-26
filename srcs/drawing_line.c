/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:50:02 by abenani           #+#    #+#             */
/*   Updated: 2019/07/12 17:43:58 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	turn_on_p(t_img *img, int x, int y, int col)
{
	int i;

	if (x < 0 || y < 0 || x >= IMG_W || y >= IMG_H)
		return ;
	i = x + y * IMG_W;
	if (i < IMG_W * IMG_H)
		img->tab[i] = col;
}

void	draw_line(t_img *img, t_point a, t_point b, int col)
{
	float		m;
	t_dl		dl;
	t_points	p;

	p.a = a;
	p.b = b;
	dl.py = a.y < b.y ? 1 : -1;
	dl.px = a.x < b.x ? 1 : -1;
	dl.dx = abs(b.x - a.x);
	dl.dy = abs(b.y - a.y);
	m = (float)(b.y - a.y) / (b.x - a.x);
	if (m <= 1 && m >= -1)
		draw_first_case(dl, p, img, col);
	else
		draw_second_case(dl, p, img, col);
}

void	draw_first_case(t_dl dl, t_points p, t_img *img, int col)
{
	dl.p = 2 * dl.dy - dl.dx;
	while (1)
	{
		if (p.a.x == p.b.x && p.a.y == p.b.y)
			break ;
		if (dl.p <= 0)
		{
			turn_on_p(img, p.a.x, p.a.y, col);
			dl.p = dl.p + 2 * dl.dy;
			p.a.x += dl.px;
		}
		else
		{
			turn_on_p(img, p.a.x, p.a.y, col);
			dl.p = dl.p + 2 * dl.dy - 2 * dl.dx;
			p.a.x += dl.px;
			p.a.y += dl.py;
		}
	}
}

void	draw_second_case(t_dl dl, t_points p, t_img *img, int col)
{
	dl.p = 2 * dl.dx - dl.dy;
	while (1)
	{
		if (p.a.x == p.b.x && p.a.y == p.b.y)
			break ;
		if (dl.p <= 0)
		{
			turn_on_p(img, p.a.x, p.a.y, col);
			dl.p = dl.p + 2 * dl.dx;
			p.a.y += dl.py;
		}
		else
		{
			turn_on_p(img, p.a.x, p.a.y, col);
			dl.p = dl.p + 2 * dl.dx - 2 * dl.dy;
			p.a.x += dl.px;
			p.a.y += dl.py;
		}
	}
}
