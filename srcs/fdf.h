/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:56:07 by abenani           #+#    #+#             */
/*   Updated: 2019/07/20 16:22:49 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"
# define BUFF_SIZE 100000
# define IMG_W 1000
# define IMG_H 800

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_points
{
	t_point		a;
	t_point		b;
}				t_points;

typedef struct	s_dynamic
{
	int			zoom;
	int			mvx;
	int			mvy;
	float		rot;
	int			p;
	float		r;
	int			c;
	float		l;
}				t_dynamic;

typedef struct	s_data
{
	int			y;
	int			x;
	int			**map;
	int			**colors;
	char		**s;
	t_point		**crd;
	int			check;
	t_dynamic	dc;
}				t_data;

typedef struct	s_img
{
	void		*ptr;
	int			*tab;
	int			bpp;
	int			s_l;
	int			edn;
}				t_img;

typedef struct	s_ptr
{
	void		*mlx;
	void		*win;
}				t_ptr;

typedef struct	s_event
{
	t_ptr		ptr;
	t_img		*img;
	t_data		*var;
}				t_event;

typedef struct	s_dl
{
	int			p;
	int			px;
	int			py;
	int			dx;
	int			dy;
}				t_dl;

typedef struct	s_dm
{
	int			i;
	int			j;
	int			mvx;
	int			mvy;
	int			mvz;
	int			ds;
	t_point		a;
	t_point		b;
	t_point		c;
}				t_dm;

typedef struct	s_atoi
{
	int			i;
	int			n;
	int			k;
	int			som;
	int			p;
}				t_atoi;

t_data			*check_map(char *file);
void			read_map(int fdi, t_data *var);
void			save_map1(char *all, t_data *var);
void			save_map2(char *all, t_data *var, int num, int i);
int				is_it_valid(t_data var);
void			msg_error(void);
void			draw_line(t_img *img, t_point a, t_point b, int col);
void			draw_first_case(t_dl dl, t_points p, t_img *img, int col);
void			draw_second_case(t_dl dl, t_points p, t_img *img, int col);
void			drawing_map(t_data *my, t_img *img);
int				ft_atoi_hexbase(char *s);
void			map_coordinates(t_data *var);
void			*call_img(t_ptr ptr, t_data *var);
void			redo(t_event *event);
int				key_press(int keycode, void *param);
int				mouse_press(int button, int x, int y, void *param);
void			key_press2(int keycode, t_event *event);
void			iso_projection(int *x, int *y);
void			rotation(float r, int *y);
void			projection_net(int p, t_point *a, t_point *b, t_point *c);
void			projection_line(int p, t_point *a, t_point *b);
void			rotation_net(float r, t_point *a, t_point *b, t_point *c);
void			rotation_line(float r, t_point *a, t_point *b);
void			free_all(t_data *var);
#endif
