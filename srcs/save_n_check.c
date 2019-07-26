/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_n_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:53:51 by abenani           #+#    #+#             */
/*   Updated: 2019/07/17 19:46:40 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data		*check_map(char *file)
{
	int		fd;
	t_data	*var;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Sorry we couldn't find this file :(");
		exit(0);
	}
	var = (t_data*)malloc(sizeof(t_data));
	var->check = 1;
	read_map(fd, var);
	return (var);
}

void		read_map(int fd, t_data *var)
{
	int		rd;
	char	buff[BUFF_SIZE + 1];
	char	*all;
	char	*tmp;

	all = ft_strnew(0);
	if ((rd = read(fd, buff, 0)) < 0)
	{
		ft_putendl("Please enter a valid file ;)");
		exit(0);
	}
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		tmp = ft_strjoin(all, buff);
		free(all);
		all = tmp;
	}
	save_map1(all, var);
	map_coordinates(var);
	free(all);
}

void		save_map1(char *all, t_data *var)
{
	int		i;
	char	**s;

	s = ft_strsplit(all, '\n');
	i = 0;
	while (s[i])
		i++;
	if (i == 0)
	{
		ft_putendl("Please enter a valid file ;)");
		exit(0);
	}
	var->y = i;
	var->map = (int**)malloc(sizeof(int*) * i);
	var->colors = (int**)malloc(sizeof(int*) * i);
	i = 0;
	while (i < var->y)
	{
		save_map2(s[i], var, i, 0);
		i++;
	}
}

void		save_map2(char *all, t_data *var, int num, int i)
{
	char		**s;
	static int	c = 0;

	s = ft_strsplit(all, ' ');
	while (s[i])
		i++;
	if (c == 0)
	{
		var->x = i;
		c = 1337;
	}
	if (i < var->x)
	{
		var->check = 0;
		return ;
	}
	var->map[num] = (int*)malloc(sizeof(int) * var->x);
	var->colors[num] = (int*)malloc(sizeof(int) * var->x);
	i = -1;
	while (++i < var->x)
	{
		var->map[num][i] = ft_atoi(s[i]);
		var->colors[num][i] = ft_atoi_hexbase(s[i]);
	}
}
