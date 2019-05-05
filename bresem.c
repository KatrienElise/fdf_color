/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresem.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 17:54:40 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/05 13:11:04 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		decide_line(t_fdf *start, t_bresem line)
{
	if (line.x0 == start->x1 || line.y0 == start->y1)
		put_straight_line(start, line);
	if (line.dxx >= line.dyy && line.dx > 0 && line.dy > 0)
		put_oct0(start, line);
	else if (line.dyy > line.dxx && line.dx > 0 && line.dy > 0)
		put_oct1(start, line);
	else if (line.dyy >= line.dxx && line.dx < 0 && line.dy > 0)
		put_oct2(start, line);
	else if (line.dxx > line.dyy && line.dx < 0 && line.dy > 0)
		put_oct3(start, line);
	else if (line.dxx >= line.dyy && line.dx < 0 && line.dy < 0)
		put_oct4(start, line);
	else if (line.dyy > line.dxx && line.dx < 0 && line.dy < 0)
		put_oct5(start, line);
	else if (line.dyy >= line.dxx && line.dx > 0 && line.dy < 0)
		put_oct6(start, line);
	else if (line.dxx > line.dyy && line.dx > 0 && line.dy < 0)
		put_oct7(start, line);
}

void		draw_line(t_fdf *start, t_bresem line)
{
	line.color = dec_first_color(start, line);
	put_pixel_to_img(start, line.x0, line.y0, line.color);
	line.dx = start->x1 - line.x0;
	line.dxx = ft_abs(line.dx);
	line.dy = start->y1 - line.y0;
	line.dyy = ft_abs(line.dy);
	decide_line(start, line);
}

void		put_line(t_fdf *start)
{
	t_bresem	line;

	line.dx = 0;
	line.dy = 0;
	line.dxx = 0;
	line.dyy = 0;
	line.f = 0;
	line.color = 0;
	line.x0 = start->x0;
	line.y0 = start->y0;
	draw_line(start, line);
}
