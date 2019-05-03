/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_setup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 11:11:09 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/02 19:00:21 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dist_start(t_fdf *start)
{
	int		dist;

	dist = MAX_DIST;
	if (start->scroll != 0)
		change_dist_z(start);
	else if (start->z_click != 0 || start->rx_click != 0 ||\
	start->rz_click != 0 || start->ry_click != 0 || start->move_hor != 0\
	|| start->move_vert != 0 || start->no_event != 0 || start->z_mod != 0\
	|| start->view != 0)
		start->no_event = 0;
	else
		dist_start2(dist, start);
	start->sx = 0 - ((start->w / 2) * start->dist);
	start->sy = 0 - ((start->h / 2) * start->dist);
}

void	put_cords1(t_fdf *start, t_int b)
{
	if (b.i == 0)
	{
		start->map[b.i][0] = start->sx;
		start->map[b.i][1] = start->sy;
		start->map[b.i][2] = start->cords[b.y][b.x];
	}
	if (b.i % start->w < (start->w) && b.i % start->w != 0)
	{
		b.ki = b.i - 1;
		start->map[b.i][0] = start->map[b.ki][0] + start->dist;
		if (b.i < start->w)
			start->map[b.i][1] = start->map[b.ki][1];
		start->map[b.i][2] = start->cords[b.y][b.x];
	}
}

void	put_cords2(t_fdf *start, t_int b)
{
	if (b.i % start->w == 0)
		start->map[b.i][0] = start->sx;
	b.ki = b.i - 1;
	if (b.i % start->w == 0)
		start->map[b.i][0] = start->sx;
	b.ki = b.i - 1;
	if (b.i % start->w == 0)
		start->map[b.i][1] = start->map[b.ki][1] + start->dist;
	if (b.i % start->w != 0)
		start->map[b.i][1] = start->map[b.ki][1];
	start->map[b.i][2] = start->cords[b.y][b.x];
}

void	put_cords_to_map(t_fdf *start)
{
	t_int		b;

	b.i = 0;
	b.y = 0;
	start->map = (int**)malloc(sizeof(int*) * (start->h * start->w));
	while (b.i < (start->w * start->h))
	{
		b.x = 0;
		while (b.x < start->w)
		{
			start->map[b.i] = (int*)malloc(sizeof(int) * 3);
			if (b.i == 0)
				put_cords1(start, b);
			if (b.i % start->w < (start->w) && b.i % start->w != 0)
				put_cords1(start, b);
			if (b.i >= start->w)
				put_cords2(start, b);
			b.i++;
			b.x++;
		}
		b.y++;
	}
}

void	copy_map(t_fdf *start)
{
	int		i;
	int		x;

	i = 0;
	start->tmp = (double**)malloc(sizeof(double*) * (start->h * start->w));
	while (i < (start->w * start->h))
	{
		x = 0;
		start->tmp[i] = (double*)malloc(sizeof(double) * 3);
		while (x < 3)
		{
			start->tmp[i][x] = start->map[i][x];
			if (x == 2)
			{
				if (start->tmp[i][x] > start->max_z)
					start->max_z = start->tmp[i][x];
				if (start->tmp[i][x] < start->min_z)
					start->min_z = start->tmp[i][x];
			}
			x++;
		}
		i++;
	}
	make_reset(start);
}
