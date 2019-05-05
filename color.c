/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 08:28:50 by kblum          #+#    #+#                */
/*   Updated: 2019/05/05 13:12:18 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bresem    difference(t_fdf *start, t_bresem line)
{
    int val;

    if (start->z0 < start->z1)
        val = start->z0;
    else
        val = start->z1;
   if (val > -10 && val <= 2)
		line = mini_color(val, line);
	else if (val >= 3 && val < 5)
		line.color = 0xff004c;
	else if (val >= 5 && val < 7)
		line.color = 0xffff00;
	else if (val >= 7 && val < 10)
		line.color = 0x800080;
	else if (val >= 10 && val <= 110)
		line = big_color_pos(val, line);
	else if (val <= -10 && val >= -110)
		line = big_color_neg(val, line);
    
	else
		line.color = 0xff0000;
    return (line);
}

int     dec_first_color(t_fdf *start, t_bresem line)
{
    if (start->z0 == start->min_z && start->z1 == start->min_z)
        line.color = 0x1a128e;
    else if (start->z0 == start->max_z && start->z1 == start->max_z)
        line.color = 0x1a30f2;
    else if (start->z0 == start->z1)
        line.color = 0x27bc39;
    else
        line = difference(start, line);
    return (line.color);
}

int     dec_color(t_fdf *start, t_bresem line)
{
    int a;

    if (start->dec == 1)
        a = -50;
    else if (start->dec == 2)
        a = 11;
    else if (start->dec == 3)
        a = 50000;
    else if (start->dec == 4)
        a = 0;
    else
        a = 0;
    if (start->z0 == start->min_z && start->z1 == start->min_z)
        line.color = 0x1a128e;
    else if (start->z0 == start->max_z && start->z1 == start->max_z)
        line.color = 0xc8f4f1;
    else if (start->z0 == start->z1)
    {
        if (start->dec == 1)
            line.color = 0x8c48c4;
        else if (start->dec == 2)
            line.color = 0x59b293;
        else if (start->dec == 3)
            line.color = 0xef0e0e;
        else
            line.color = 0x27bc39; 
    } 
    else
        line.color = line.color + (a * 100);
    return (line.color);
}

t_bresem	big_color_pos(int val, t_bresem line)
{
	if (val >= 10 && val < 15)
		line.color = 0xe2e51b;
	if (val >= 15 && val < 18)
		line.color = 0xddff00;
	if (val >= 18 && val < 20)
		line.color = 0xc3ff00;
	if (val >= 20 && val < 30)
		line.color = 0x94ff00;
	if (val >= 30 && val < 35)
		line.color = 0x37ff00;
	if (val >= 35 && val < 40)
		line.color = 0x00ff21;
	if (val >= 40 && val < 50)
		line.color = 0x27c463;
	if (val >= 50 && val < 60)
		line.color = 0x1be5e5;
	if (val >= 60 && val < 70)
		line.color = 0xed28d2;
	if (val >= 70 && val < 80)
		line.color = 0xbc21a8;
	if (val >= 80 && val < 90)
		line.color = 0x8c217e;
	if (val >= 90 && val < 110)
		line.color = 0x5b1552;
	return (line);
}

t_bresem	mini_color(int val, t_bresem line)
{
	if (val > -10 && val <= -5)
		line.color = 0x00ffd0;
	else if (val > -5 && val <= -3)
		line.color = 0x269b86;
	else if (val > -3 && val < 0)
		line.color = 0x216d5f;
	else if (val == 0)
		line.color = 0xf70e39;
	else if (val > 0 && val < 3)
		line.color = 0x0b3a32;
	return (line);
}
