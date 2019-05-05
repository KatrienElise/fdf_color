/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 16:10:01 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/03 15:50:40 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_rot_x(t_fdf *start)
{
	if (start->rx_click == 1)
	{
		if (start->rx == 360)
			start->rx = 0;
		else
			start->rx = start->rx + 1;
	}
	if (start->rx_click == -1)
	{
		if (start->rx == 0)
			start->rx = 359;
		else
			start->rx = start->rx - 1;
	}
	start->rx_click = 0;
}

void	check_rot_y(t_fdf *start)
{
	if (start->ry_click == 1)
	{
		if (start->ry == 360)
			start->ry = 0;
		else
			start->ry = start->ry + 1;
	}
	if (start->ry_click == -1)
	{
		if (start->ry == 0)
			start->ry = 359;
		else
			start->ry = start->ry - 1;
	}
	start->ry_click = 0;
}

void	check_rot_z(t_fdf *start)
{
	if (start->rz_click == 1)
	{
		if (start->rz == 360)
			start->rz = 0;
		else
			start->rz = start->rz + 1;
	}
	if (start->rz_click == -1)
	{
		if (start->rz == 0)
			start->rz = 359;
		else
			start->rz = start->rz - 1;
	}
	start->rz_click = 0;
}

void	check_rot(t_fdf *start)
{
	check_rot_x(start);
	check_rot_y(start);
	check_rot_z(start);
}
