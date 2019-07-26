/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:27:52 by abenani           #+#    #+#             */
/*   Updated: 2019/07/16 17:48:46 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi_hexbase(char *s)
{
	t_atoi	v;

	v.i = 1;
	v.n = 0;
	v.k = 1;
	v.som = 0;
	v.p = 0;
	while (s[v.i] != 'x' && s[v.i])
		v.i++;
	v.n = 0;
	while (s[v.n++])
		v.k++;
	while (v.k >= v.i)
	{
		if (s[v.k] >= 48 && s[v.k] <= 57)
			v.som = v.som + (s[v.k] - '0') * pow(16, v.p++);
		if (s[v.k] >= 97 && s[v.k] <= 102)
			v.som = v.som + (s[v.k] - 87) * pow(16, v.p++);
		if (s[v.k] >= 65 && s[v.k] <= 70)
			v.som = v.som + (s[v.k] - 55) * pow(16, v.p++);
		v.k--;
	}
	if (v.som == 0)
		return (0x1fffcb);
	return (v.som);
}

void	free_all(t_data *var)
{
	int i;

	i = 0;
	while (i < var->y)
	{
		free(var->map[i]);
		free(var->colors[i]);
		free(var->crd[i]);
		i++;
	}
	free(var->map);
	free(var->colors);
	free(var->crd);
}
