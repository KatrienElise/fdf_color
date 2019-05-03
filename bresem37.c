/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresem37.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 13:54:53 by rsteigen       #+#    #+#                */
/*   Updated: 2019/04/25 15:22:45 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_oct3(t_fdf *start, t_bresem line)
{
	line.f = line.dxx / 2;
	while (line.x0 > start->x1)
	{
		line.x0--;
		line.f = line.f - line.dyy;
		if (line.f < 0)
		{
			line.y0++;
			line.f = line.f + line.dxx;
		}
		put_pixel_to_img(start, line.x0, line.y0, line.color);
	}
}

void	put_oct4(t_fdf *start, t_bresem line)
{
	line.f = line.dxx / 2;
	while (line.x0 > start->x1)
	{
		line.x0--;
		line.f = line.f - line.dyy;
		if (line.f < 0)
		{
			line.y0--;
			line.f = line.f + line.dxx;
		}
		put_pixel_to_img(start, line.x0, line.y0, line.color);
	}
}

void	put_oct5(t_fdf *start, t_bresem line)
{
	line.f = line.dyy / 2;
	while (line.y0 > start->y1)
	{
		line.y0--;
		line.f = line.f - line.dxx;
		if (line.f < 0)
		{
			line.x0--;
			line.f = line.f + line.dyy;
		}
		put_pixel_to_img(start, line.x0, line.y0, line.color);
	}
}

void	put_oct6(t_fdf *start, t_bresem line)
{
	line.f = line.dyy / 2;
	while (line.y0 > start->y1)
	{
		line.y0--;
		line.f = line.f - line.dxx;
		if (line.f < 0)
		{
			line.x0++;
			line.f = line.f + line.dyy;
		}
		put_pixel_to_img(start, line.x0, line.y0, line.color);
	}
}

void	put_oct7(t_fdf *start, t_bresem line)
{
	line.f = line.dxx / 2;
	while (line.x0 < start->x1)
	{
		line.x0++;
		line.f = line.f - line.dyy;
		if (line.f < 0)
		{
			line.y0--;
			line.f = line.f + line.dxx;
		}
		put_pixel_to_img(start, line.x0, line.y0, line.color);
	}
}
