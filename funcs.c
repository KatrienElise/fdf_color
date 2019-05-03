/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   funcs.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 15:47:09 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/03 15:15:15 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dist_start2(int dist, t_fdf *start)
{
	if ((MAX_W / start->w) > (MAX_H / start->h))
	{
		if ((MAX_H / start->h) < dist)
			dist = MAX_H / start->h;
	}
	else
	{
		if ((MAX_W / start->w) < dist)
			dist = MAX_W / start->w;
	}
	start->dist = dist;
}

int		digit_count(char *s, int i)
{
	int count;

	count = 0;
	while (s[i] != ' ')
	{
		count++;
		i++;
	}
	return (count);
}

int		get_val(char *s, int i)
{
	char	*value;
	int		val;
	int		count;

	count = digit_count(s, i);
	value = ft_strsub(s, i, count);
	val = ft_atoi(value);
	return (val);
}

t_bresem	big_color_neg(t_bresem line)
{
	if (line.tc <= -10 && line.tc > -15)
		line.color = 0x162b28;
	if (line.tc <= -15 && line.tc > -18)
		line.color = 0x8a7ded;
	if (line.tc <= -18 && line.tc >  -20)
		line.color = 0x7361f4;
	if (line.tc <= -20 && line.tc > -30)
		line.color = 0x321cd8;
	if (line.tc <= -30 && line.tc > -35)
		line.color = 0x3828af;
	if (line.tc <= -35 && line.tc > -40)
		line.color = 0x2b1d93;
	if (line.tc <= -40 && line.tc > -50)
		line.color = 0x24187c;
	if (line.tc <= -50 && line.tc > -60)
		line.color = 0x1be5e5;
	if (line.tc <= -60 && line.tc > -70)
		line.color = 0xed28d2;
	if (line.tc <= -70 && line.tc > -80)
		line.color = 0xbc21a8;
	if (line.tc <= -80 && line.tc > -90)
		line.color = 0x8c217e;
	if (line.tc <= -90 && line.tc > -110)
		line.color = 0x5b1552;
	return (line);
}

void	make_reset(t_fdf *start)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	start->reset = (double**)malloc(sizeof(double*) * (start->h * start->w));
	start->lock = (double**)malloc(sizeof(double*) * (start->h * start->w));
	while (i < start->w * start->h)
	{
		x = 0;
		start->reset[i] = (double*)malloc(sizeof(double) * 3);
		start->lock[i] = (double*)malloc(sizeof(double) * 3);
		while (x < 3)
		{
			start->reset[i][x] = start->tmp[i][x];
			start->lock[i][x] = start->tmp[i][x];
			x++;
		}
		i++;
	}
}
