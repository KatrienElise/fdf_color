/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresem02.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 13:54:08 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/05 08:58:08 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_vert(t_fdf *start, t_bresem line)
{
	if (start->y1 < line.y0)
	{
		while (start->y1 <= line.y0)
		{
			line.y0--;
			line.color = dec_color(start, line);
			put_pixel_to_img(start, line.x0, line.y0, line.color);
		}
	}
	else
	{
		while (line.y0 <= start->y1)
		{
			line.y0++;
			line.color = dec_color(start, line);
			put_pixel_to_img(start, line.x0, line.y0, line.color);
		}
	}
}

void	put_straight_line(t_fdf *start, t_bresem line)
{
	if (line.y0 == start->y1)
	{
		if (line.x0 < start->x1)
		{
			while (line.x0 <= start->x1)
			{
				line.x0++;
				line.color = dec_color(start, line);
				put_pixel_to_img(start, line.x0, line.y0, line.color);
			}
		}
		else
		{
			while (start->x1 <= line.x0)
			{
				line.x0--;
				line.color = dec_color(start, line);
				put_pixel_to_img(start, line.x0, line.y0, line.color);
			}
		}
	}
	if (line.x0 == start->x1)
		put_vert(start, line);
}

void	put_oct0(t_fdf *start, t_bresem line)
{
	line.f = line.dxx / 2;
	while (line.x0 < start->x1)
	{
		line.x0++;
		line.f = line.f - line.dyy;
		if (line.f < 0)
		{
			line.y0++;
			line.f = line.f + line.dxx;
		}
		line.color = dec_color(start, line);
		put_pixel_to_img(start, line.x0, line.y0, line.color);
	}
}

void	put_oct1(t_fdf *start, t_bresem line)
{
	line.f = line.dyy / 2;
	while (line.y0 < start->y1)
	{
		line.y0++;
		line.f = line.f - line.dxx;
		if (line.f < 0)
		{
			line.x0++;
			line.f = line.f + line.dyy;
		}
		line.color = dec_color(start, line);
		put_pixel_to_img(start, line.x0, line.y0, line.color);
	}
}

void	put_oct2(t_fdf *start, t_bresem line)
{
	line.f = line.dyy / 2;
	while (line.y0 < start->y1)
	{
		line.y0++;
		line.f = line.f - line.dxx;
		if (line.f < 0)
		{
			line.x0--;
			line.f = line.f + line.dyy;
		}
		line.color = dec_color(start, line);
		put_pixel_to_img(start, line.x0, line.y0, line.color);
	}
}
