/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_n_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 07:55:58 by abenani           #+#    #+#             */
/*   Updated: 2019/07/12 17:31:02 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		map_coordinates(t_data *var)
{
	int i;
	int j;

	var->crd = (t_point**)malloc(sizeof(t_point*) * var->y);
	i = 0;
	while (i < var->y)
	{
		var->crd[i] = (t_point*)malloc(sizeof(t_point) * var->x);
		i++;
	}
	i = 0;
	while (i < var->y)
	{
		j = 0;
		while (j < var->x)
		{
			var->crd[i][j].x = j - var->x / 2;
			var->crd[i][j].y = i - var->y / 2;
			j++;
		}
		i++;
	}
}

void		rotation_line(float r, t_point *a, t_point *b)
{
	rotation(r, &a->y);
	rotation(r, &b->y);
}
