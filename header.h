/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/05 13:12:10 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define WINW 2000
# define MAX_W 1800
# define MID_W 1000
# define WINH 1200
# define MAX_H 1000
# define MID_H 600
# define MAX_DIST 120
# define NEW(x) (x*)ft_memalloc(sizeof(x))

typedef	struct 		s_int
{
	int				i;
	int				x;
	int				y;
	int				ki;
	int				c;
}					t_int;

typedef struct		s_bresem
{
	int				dx;
	int				dy;
	int				dxx;
	int				dyy;
	int				f;
	int				color;
	int				x0;
	int				y0;
	int				percen;
}					t_bresem;

typedef struct		s_rot
{
	int				x;
	int				y;
	int				z;
}					t_rot;


typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	int				w;
	int				h;
	char			*data_addr;
	int				bpp;
	int				sl;
	int				endian;
	double			dist;
	int				sx;
	int				sy;
	int				**cords;
	int				**map;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				z0;
	int				z1;
	double			**tmp;
	double			**lock;
	double			**reset;
	int				z_click;
	int				max_z;
	int				min_z;
	double			add_z;
	int				scroll;
	int				zoom;
	double			zoom_perc;
	double			rx;
	double			ry;
	double			rz;
	int				rx_click;
	int				ry_click;
	int				rz_click;
	int				reset_click;
	int				move_vert;
	int				move_hor;
	int				add_vert;
	int				add_hor;
	int				no_event;
	int				crazy;
	int				view;
	double			z_mod;
	int				dec;
}					t_fdf;

/* ************************************************************************** */
/*          error.c                                                           */
/* ************************************************************************** */
void				error_fd(int nb);
void				error(int d, t_fdf *start);
void				error_gnl(int nb, t_fdf *start, int y, char *line);
void				error_draw(t_fdf *start, int d);
/* ************************************************************************** */
/*          color.c                                                           */
/* ************************************************************************** */
int					dec_first_color(t_fdf *start, t_bresem line);
int					dec_color(t_fdf *start, t_bresem line);
t_bresem			difference(t_fdf *start, t_bresem line);
t_bresem			big_color_pos(int val, t_bresem line);
t_bresem			mini_color(int val, t_bresem line);

/* ************************************************************************** */
/*          fdf.c                                                             */
/* ************************************************************************** */
int					ft_fdf(char *file);
void				fdf_get_wh(int fd, t_fdf *start);
int					fdf_get_w(char *line);
void				fdf_get_co(int fd, t_fdf *start);
void				fdf_fill_cords(t_fdf *start, char **str, int y);

/* ************************************************************************** */
/*          fdf2.c                                                             */
/* ************************************************************************** */
void				fill_digit(t_fdf *start, char **str, t_int b, int y);
void				fill_rest(t_fdf *start, t_int b, int y);

/* ************************************************************************** */
/*          events.c                                                          */
/* ************************************************************************** */
int					deal_key(int keycode, t_fdf *start);
int					deal_key2(int keycode, t_fdf *start);
int					deal_key3(int keycode, t_fdf *start);
int					mouse_press(int button, int x, int y, t_fdf *start);
void				events_reset(t_fdf *start);

/* ************************************************************************** */
/*          actions.c                                                         */
/* ************************************************************************** */
void				check_rot_x(t_fdf *start);
void				check_rot_y(t_fdf *start);
void				check_rot_z(t_fdf *start);
void				check_rot(t_fdf *start);

/* ************************************************************************** */
/*          funcs.c                                                           */
/* ************************************************************************** */
void				dist_start2(int dist, t_fdf *start);
int					digit_count(char *s, int i);
int					get_val(char *s, int i);
void				make_reset(t_fdf *start);
t_bresem			big_color_neg(int val, t_bresem line);

/* ************************************************************************** */
/*          setup.c                                                           */
/* ************************************************************************** */
void				setup(t_fdf *start);
void				align_map(t_fdf *start);
void				set_zero(t_fdf *start);
void				set_zero2(t_fdf *start, int i);
void				set_zero3(t_fdf *start, int i);

/* ************************************************************************** */
/*          setup_align.c                                                     */
/* ************************************************************************** */
void				check_align(t_fdf *start);
void				align_map(t_fdf *start);

/* ************************************************************************** */
/*          draw.c                                                            */
/* ************************************************************************** */
void				put_view_to_img(t_fdf *start);
void				put_view_to_img2(t_fdf *start, t_int b);
void				put_pixel_to_img(t_fdf *start, int x, int y, int color);
int					draw(t_fdf *start);
void				to_put_or_not_to_put(t_fdf *start);

/* ************************************************************************** */
/*          calc_setup.c                                                      */
/* ************************************************************************** */
void				dist_start(t_fdf *start);
void				put_cords1(t_fdf *start, t_int b);
void				put_cords2(t_fdf *start, t_int b);
void				put_cords_to_map(t_fdf *start);
void				copy_map(t_fdf *start);

/* ************************************************************************** */
/*          calc_setup_dist_z.c                                               */
/* ************************************************************************** */
void				change_dist_z(t_fdf *start);
void				change_z_zoom(t_fdf *start, int i);

/* ************************************************************************** */
/*          check.c                                                           */
/* ************************************************************************** */
int					check_num(char **str);
void				check_error(t_fdf *start, char **str, int y, char *line);
void				check_error_get_co(t_fdf *start, char *line, int y,\
int 				gnl);
void				check_reset(t_fdf *start);

/* ************************************************************************** */
/*          free.c                                                            */
/* ************************************************************************** */
void				free_start(t_fdf *start, int j);
void				free_str(char **str);
void				free_all(t_fdf *start);

/* ************************************************************************** */
/*          rot.c                                                             */
/* ************************************************************************** */
void				rot_x(t_fdf *start, int i);
void				rot_y(t_fdf *start, int i);
void				rot_z(t_fdf *start, int i);
void				rot_map(t_fdf *start);

/* ************************************************************************** */
/*          bresem.c                                                          */
/* ************************************************************************** */
void				put_line(t_fdf *start);
void				draw_line(t_fdf *start, t_bresem line);
void				decide_line(t_fdf *start, t_bresem line);

/* ************************************************************************** */
/*          bresem02.c                                                        */
/* ************************************************************************** */
void				put_vert(t_fdf *start, t_bresem line);
void				put_straight_line(t_fdf *start, t_bresem line);
void				put_oct0(t_fdf *start, t_bresem line);
void				put_oct1(t_fdf *start, t_bresem line);
void				put_oct2(t_fdf *start, t_bresem line);

/* ************************************************************************** */
/*          bresem37.c                                                        */
/* ************************************************************************** */
void				put_oct3(t_fdf *start, t_bresem line);
void				put_oct4(t_fdf *start, t_bresem line);
void				put_oct5(t_fdf *start, t_bresem line);
void				put_oct6(t_fdf *start, t_bresem line);
void				put_oct7(t_fdf *start, t_bresem line);

/* ************************************************************************** */
/*          touch.c                                                           */
/* ************************************************************************** */
int					touch_left(t_fdf *start);
int					touch_top(t_fdf *start);
int					touch_right(t_fdf *start);
int					touch_bottom(t_fdf *start);
int					touch_square(t_fdf *start);

/* ************************************************************************** */
/*          inside.c                                                          */
/* ************************************************************************** */
int					inside_square(t_fdf *start);

/* ************************************************************************** */
/*          iso.c                                                          */
/* ************************************************************************** */
void 				iso(double *x, double *y, double z);

#endif
