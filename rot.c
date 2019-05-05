/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rot.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 15:53:09 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/02 17:24:43 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		rot_x(t_fdf *start, int i)
{
	int		y;
	int		z;

	y = start->tmp[i][1];
	z = start->tmp[i][2];
	start->tmp[i][1] = y * cos(start->rx * M_PI / 180)\
	+ z * sin(start->rx * M_PI / 180);
	start->tmp[i][2] = -y * sin(start->rx * M_PI / 180)\
	+ z * cos(start->rx * M_PI / 180);
}

void		rot_y(t_fdf *start, int i)
{
	int x;
	int z;

	x = start->tmp[i][0];
	z = start->tmp[i][2];
	start->tmp[i][0] = x * cos(start->ry * M_PI / 180)\
	+ z * sin(start->ry * M_PI / 180);
	start->tmp[i][2] = -x * sin(start->ry * M_PI / 180)\
	+ z * cos(start->ry * M_PI / 180);
}

void		rot_z(t_fdf *start, int i)
{
	int x;
	int y;

	x = start->tmp[i][0];
	y = start->tmp[i][1];
	start->tmp[i][0] = x * cos(start->rz * M_PI / 180)\
	- (y * sin(start->rz * M_PI / 180));
	start->tmp[i][1] = x * sin(start->rz * M_PI / 180)\
	+ y * cos(start->rz * M_PI / 180);
}

void		rot_map(t_fdf *start)
{
	int		i;

	i = 0;
	if (start->view == 1)
	{
		start->rx = 30;
		start->ry = 30;
	}
	while (i < (start->h * start->w))
	{
		if (start->z_mod == 0)
			start->z_mod = 8;
		start->tmp[i][0] = start->lock[i][0];
		start->tmp[i][1] = start->lock[i][1];
		start->tmp[i][2] = start->lock[i][2] * start->z_mod;
		rot_x(start, i);
		rot_y(start, i);
		rot_z(start, i);
		i++;
	}
}
