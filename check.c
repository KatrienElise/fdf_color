/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 15:08:42 by rsteigen       #+#    #+#                */
/*   Updated: 2019/04/29 15:10:53 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_error(t_fdf *start, char **str, int y, char *line)
{
	if (!str)
		error_gnl(6, start, y, line);
	if (check_num(str) == -1)
	{
		ft_putstr("check.c: error na check_num\n");
		error_gnl(6, start, y, line);
	}
}

int		check_num(char **str)
{
	int		x;
	int		y;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (((str[y][x] < '0' || str[y][x] > '9') && str[y][x] != '-'\
			&& str[y][x] != ',') || (str[y][x] == '-' && (str[y][x + 1] < '0'\
			|| str[y][x + 1] > '9')))
				return (-1);
			if (str[y][x] == ',')
			{
				while (str[y][x] && str[y][x] != ' ')
					x++;
			}
			if (str[y][x])
				x++;
		}
		y++;
	}
	return (0);
}

void	check_error_get_co(t_fdf *start, char *line, int y, int gnl)
{
	if (y == 0 && gnl == -1)
		error(5, start);
	else if (gnl == -1)
		error_gnl(6, start, y, line);
}

void	check_reset(t_fdf *start)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (start->reset_click == 1)
	{
		start->rx = 0;
		start->ry = 0;
		start->rz = 0;
		while (i < start->w * start->h)
		{
			x = 0;
			while (x < 3)
			{
				start->lock[i][x] = start->reset[i][x];
				x++;
			}
			i++;
		}
	}
	start->reset_click = 0;
}
