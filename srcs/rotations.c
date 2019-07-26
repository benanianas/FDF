/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:17:50 by abenani           #+#    #+#             */
/*   Updated: 2019/07/13 13:12:37 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_projection(int *x, int *y)
{
	int px;
	int py;

	px = *x;
	py = *y;
	*x = (px - py) * cos(0.523599);
	*y = (px + py) * sin(0.523599);
}

void	rotation(float r, int *y)
{
	int p_y;

	p_y = *y;
	*y = p_y * cos(0 + r);
}

void	projection_net(int p, t_point *a, t_point *b, t_point *c)
{
	if (p == 1)
	{
		iso_projection(&a->x, &a->y);
		iso_projection(&b->x, &b->y);
		iso_projection(&c->x, &c->y);
	}
}

void	projection_line(int p, t_point *a, t_point *b)
{
	if (p == 1)
	{
		iso_projection(&a->x, &a->y);
		iso_projection(&b->x, &b->y);
	}
}

void	rotation_net(float r, t_point *a, t_point *b, t_point *c)
{
	rotation(r, &a->y);
	rotation(r, &b->y);
	rotation(r, &c->y);
}
