/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresem.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 17:54:40 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/03 17:06:22 by kblum         ########   odam.nl         */
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

t_bresem	minicolor(t_bresem line)
{
	if (line.tc > -10 && line.tc <= -5)
		line.color = 0x00ffd0;
	else if (line.tc > -5 && line.tc <= -3)
		line.color = 0x269b86;
	else if (line.tc > -3 && line.tc < 0)
		line.color = 0x216d5f;
	else if (line.tc == 0)
		line.color = 0xf70e39;
	else if (line.tc > 0 && line.tc < 3)
		line.color = 0x0b3a32;
	return (line);
}

t_bresem	big_color_pos(t_bresem line)
{
	if (line.tc >= 10 && line.tc < 15)
		line.color = 0xe2e51b;
	if (line.tc >= 15 && line.tc < 18)
		line.color = 0xddff00;
	if (line.tc >= 18 && line.tc < 20)
		line.color = 0xc3ff00;
	if (line.tc >= 20 && line.tc < 30)
		line.color = 0x94ff00;
	if (line.tc >= 30 && line.tc < 35)
		line.color = 0x37ff00;
	if (line.tc >= 35 && line.tc < 40)
		line.color = 0x00ff21;
	if (line.tc >= 40 && line.tc < 50)
		line.color = 0x27c463;
	if (line.tc >= 50 && line.tc < 60)
		line.color = 0x1be5e5;
	if (line.tc >= 60 && line.tc< 70)
		line.color = 0xed28d2;
	if (line.tc >= 70 && line.tc < 80)
		line.color = 0xbc21a8;
	if (line.tc >= 80 && line.tc < 90)
		line.color = 0x8c217e;
	if (line.tc >= 90 && line.tc < 110)
		line.color = 0x5b1552;
	return (line);
}

void		draw_line(t_fdf *start, t_bresem line)
{
	if ((start->z0 * start->z_mod) == start->min_z && (start->z1 * start->z_mod) == start->min_z)
		line.color = 0xbef4d5; // (lichtgroen/wit)
	else if ((start->z0 * start->z_mod) == start->max_z && (start->z1 * start->z_mod) == start->max_z)
		line.color = 0x113d23; //(donkergroen)
	else if(start->z0 == start->z1)
		line.color = 0x1cc12e5; // (roze)
	else if (line.tc > -10 && line.tc < 3)
		line = minicolor(line);
	else if (line.tc >= 3 && line.tc < 5)
		line.color = 0x0000ff;
	else if (line.tc >= 5 && line.tc < 7)
		line.color = 0xffff00;
	else if (line.tc >= 7 && line.tc < 1)
		line.color = 0x3571ba;
	else if (line.tc >= 10 && line.tc <= 110)
		line = big_color_pos(line);
	else if (line.tc <= -10 && line.tc >= -110)
		line = big_color_neg(line);
	else
		line.color = 0xe57812;
	
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
	if (start->z1 > start->z0)
		line.tc = start->z1;
	if (start->z0 > start-> z1)
		line.tc = start->z0;
	draw_line(start, line);
}