/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 15:31:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/05 13:46:25 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_pixel_to_img(t_fdf *start, int x, int y, int color)
{
	if (x > 0 && x < WINW && y > 0 && y < WINH)
		ft_memcpy(&start->data_addr[(4 * y * WINW) + (4 * x)], &color, 4);
}

void	put_view_to_img2(t_fdf *start, t_int b)
{
	start->x0 = start->tmp[b.i][0];
	start->y0 = start->tmp[b.i][1];
	start->z0 = start->lock[b.i][2];
}

void	to_put_or_not_to_put(t_fdf *start)
{
	if (inside_square(start) == 1)
		put_line(start);
	else if (touch_square(start) == 1)
		put_line(start);
}

void	put_view_to_img(t_fdf *start)
{
	t_int	b;

	b.i = 0;
	while (b.i < (start->w * start->h))
	{
		if(start->crazy == 1)
			iso(&start->tmp[b.i][0], &start->tmp[b.i][1], start->tmp[b.i][2]);
		put_view_to_img2(start, b);
		if (b.i >= start->w)
		{
			b.ki = b.i - start->w;
			start->x1 = start->tmp[b.ki][0];
			start->y1 = start->tmp[b.ki][1];
			start->z1 = start->lock[b.ki][2];
			to_put_or_not_to_put(start);
		}
		if (b.i % start->w < (start->w - 1))
		{
			b.i++;
			start->x1 = start->tmp[b.i][0];
			start->y1 = start->tmp[b.i][1];
			start->z1 = start->lock[b.i][2];
			b.i--;
			to_put_or_not_to_put(start);
		}
		b.i++;
	}
	start->crazy = 0;
}

int		draw(t_fdf *start)
{
	ft_bzero(start->data_addr, (WINW * WINH) * 4);
	check_reset(start);
	set_zero(start);
	check_rot(start);
	rot_map(start);
	align_map(start);
	put_view_to_img(start);
	mlx_put_image_to_window(start->mlx, start->win, start->img, 0, 0);
	mlx_string_put(start->mlx, start->win, 800, 10, 0xf4f1e6, "roos & katrien");
	mlx_string_put(start->mlx, start->win, 100, 20, 0xf4f1e6, "color: 		1, 2, 3, 4");
	mlx_string_put(start->mlx, start->win, 100, 35, 0xf4f1e6, "crazy: 		shift");
	mlx_string_put(start->mlx, start->win, 100, 50, 0xf4f1e6, "turn x-as: 	x & c");
	mlx_string_put(start->mlx, start->win, 100, 65, 0xf4f1e6, "turn y-as:	y & u");
	mlx_string_put(start->mlx, start->win, 100, 80, 0xf4f1e6, "turn z-as:	z & a");
	mlx_string_put(start->mlx, start->win, 100, 95, 0xf4f1e6, "dept:		+ & -");
	mlx_string_put(start->mlx, start->win, 100, 110, 0xf4f1e6, "reset:		spatie");
	mlx_string_put(start->mlx, start->win, 100, 125, 0xf4f1e6, "zoom:		scroll mouse");
	return (0);
}
