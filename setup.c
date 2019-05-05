/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 11:13:46 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/03 15:30:54 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_zero2(t_fdf *start, int i)
{
	int		ki;

	ki = i - 1;
	if (i % start->w < start->w && i % start->w != 0)
	{
		ki = i - 1;
		start->lock[i][0] = start->lock[ki][0] + start->dist;
		if (i < start->w)
			start->lock[i][1] = start->lock[ki][1];
	}
	if (i >= start->w)
	{
		if (i % start->w == 0)
			start->lock[i][0] = start->sx;
		ki = i - 1;
		if (i % start->w == 0)
			start->lock[i][1] = start->lock[ki][1] + start->dist;
		if (i % start->w != 0)
			start->lock[i][1] = start->lock[ki][1];
	}
}

void	set_zero3(t_fdf *start, int i)
{
	start->lock[i][0] = start->sx;
	start->lock[i][1] = start->sy;
}

void	set_zero(t_fdf *start)
{
	t_int	b;

	b.i = 0;
	dist_start(start);
	while (b.i < (start->w * start->h))
	{
		if (start->zoom != 0 && start->lock[b.i][2] != 0)
			change_z_zoom(start, b.i);
		if (b.i == 0)
			set_zero3(start, b.i);
		else
			set_zero2(start, b.i);
		b.i++;
	}
	if (start->z_click != 0)
		start->z_click = 0;
	start->zoom = 0;
}

void	setup(t_fdf *start)
{
	start->mlx = mlx_init();
	start->win = mlx_new_window(start->mlx, WINW, WINH, "FDF");
	start->img = mlx_new_image(start->mlx, WINW, WINH);
	start->data_addr = mlx_get_data_addr(start->img,\
	&start->bpp, &start->sl, &start->endian);
	mlx_hook(start->win, 2, 1L << 0, deal_key, start);
	mlx_hook(start->win, 4, 1L << 2, mouse_press, start);
	put_cords_to_map(start);
	copy_map(start);
	draw(start);
	mlx_loop(start->mlx);
}
