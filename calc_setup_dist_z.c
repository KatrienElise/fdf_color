/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_setup_dist_z.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/28 16:54:13 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/03 15:31:31 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_dist_z(t_fdf *start)
{
	double	begin;
	double	eind;

	begin = start->dist;
	if (start->scroll > 0)
	{
		start->zoom = 1;
		if (start->dist > 20)
			start->dist = start->dist - 5;
		else if (start->dist > 1)
			start->dist = start->dist - 1;
		else if (start->dist <= 1)
			start->dist = 1;
	}
	else if (start->scroll < 0)
	{
		start->zoom = -1;
		if (start->dist > 20)
			start->dist = start->dist + 5;
		else
			start->dist = start->dist + 1;
	}
	eind = start->dist;
	start->zoom_perc = (ft_abs(eind - begin) / begin);
	start->scroll = 0;
}

void	change_z_zoom(t_fdf *start, int i)
{
	if (start->zoom < 0)
		start->lock[i][2] += (start->lock[i][2] * start->zoom_perc);
	if (start->zoom > 0)
		start->lock[i][2] -= (start->lock[i][2] * start->zoom_perc);
}
