/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 11:05:01 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 12:06:30 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_print_map(double **map, int h, int w)
{
	int i;
	int j;

	i = 0;
	while (i < (h * w))
	{
		ft_putstr("x: ");
		ft_putnbr(map[i][0]);
		ft_putstr(" y: ");
		ft_putnbr(map[i][1]);
		ft_putstr(" z: ");
		ft_putnbr(map[i][2]);
		ft_putstr(" : ");
		j = i;
		i++;
/*		if (i < (h * w))
		{
			ft_putstr("difference between x's: \n");
			ft_putnbr(map[i][0] - map[j][0]);
			ft_putchar('\n');
		}
*/	}
}

void		ft_print_co(t_fdf *start)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < start->h)
	{
		x = 0;
		while (x < start->w)
		{
			ft_putnbr(start->cords[y][x]);
			if (x < start->w)
				ft_putchar(' ');
			x++;
		}
		if (y < start->h)
			ft_putchar('\n');
		y++;
	}
}
