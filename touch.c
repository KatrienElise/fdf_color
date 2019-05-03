/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   touch.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:51:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/04/26 13:02:42 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			touch_left(t_fdf *start)
{
	float	ua;
	float	ub;
	float	fx;
	float	fy;

	fx = 0;
	fy = 1200;
	ua = ((fx - 0) * (start->y1 - 0) - (fy - 0) * (start->x0 - 0)) / \
	((fy - 0) * (start->x1 - start->x0) - (fx - 0) * (start->y1 - start->y0));
	ub = ((start->x1 - start->x0) * (start->y0 - 0) - (start->y1 - start->y0)\
	* (start->x0 - 0)) / ((fy - 0) * (start->x1 - start->x0) - (fx - 0) *\
	(start->y1 - start->y0));
	if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1)
		return (1);
	return (-1);
}

int			touch_top(t_fdf *start)
{
	float	ua;
	float	ub;
	float	fx;
	float	fy;

	fx = 2000;
	fy = 0;
	ua = ((fx - 0) * (start->y1 - 0) - (fy - 0) * (start->x0 - 0)) / \
	((fy - 0) * (start->x1 - start->x0) - (fx - 0) * (start->y1 - start->y0));
	ub = ((start->x1 - start->x0) * (start->y0 - 0) - (start->y1 - start->y0)\
	* (start->x0 - 0)) / ((fy - 0) * (start->x1 - start->x0) - (fx - 0) *\
	(start->y1 - start->y0));
	if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1)
		return (1);
	return (-1);
}

int			touch_right(t_fdf *start)
{
	float	ua;
	float	ub;
	float	fx;
	float	fy;

	fx = 2000;
	fy = 0;
	ua = ((fx - 2000) * (start->y1 - 1200) - (fy - 1200) *\
	(start->x0 - 2000)) / ((fy - 1200) * (start->x1 - start->x0)\
	- (fx - 2000) * (start->y1 - start->y0));
	ub = ((start->x1 - start->x0) * (start->y0 - 1200) - (start->y1 -\
	start->y0) * (start->x0 - 2000)) / ((fy - 1200) * (start->x1 - start->x0)\
	- (fx - 2000) * (start->y1 - start->y0));
	if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1)
		return (1);
	return (-1);
}

int			touch_bottom(t_fdf *start)
{
	float	ua;
	float	ub;
	float	fx;
	float	fy;

	fx = 0;
	fy = 2000;
	ua = ((fx - 2000) * (start->y1 - 1200) - (fy - 1200) * (start->x0 - 2000))\
	/ ((fy - 1200) * (start->x1 - start->x0) - (fx - 2000) * (start->y1 -\
	start->y0));
	ub = ((start->x1 - start->x0) * (start->y0 - 1200) - (start->y1 -\
	start->y0) * (start->x0 - 2000)) / ((fy - 1200) * (start->x1 - start->x0)\
	- (fx - 2000) * (start->y1 - start->y0));
	if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1)
		return (1);
	return (-1);
}

int			touch_square(t_fdf *start)
{
	if (touch_left(start) == 1 || touch_top(start) == 1 ||\
	touch_right(start) == 1 || touch_bottom(start) == 1)
		return (1);
	return (-1);
}
