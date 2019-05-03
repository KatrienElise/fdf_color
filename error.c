/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 14:54:16 by kblum          #+#    #+#                */
/*   Updated: 2019/04/24 17:05:55 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		error_fd(int nb)
{
	if (nb == 1)
		ft_putstr("error 1 fd opening file\n");
	if (nb == 2)
		ft_putstr("error 2 fd allocating memory start\n");
	exit(1);
}

void		error(int d, t_fdf *start)
{
	if (d == 1 || d == 4)
	{
		ft_putstr("error 1 opening file or closing file\n");
		free(start);
	}
	if (d == 2)
	{
		ft_putstr("error 2 allocating memory\n");
		free(start);
	}
	if (d == 3)
	{
		ft_putstr("error 3 get_next_line\n");
		free(start);
	}
	if (d == 5)
	{
		ft_putstr("error 5 allocating memory of GNL\n");
		free(start->cords);
		free(start);
	}
	exit(1);
}

void		error_gnl(int nb, t_fdf *start, int y, char *line)
{
	if (nb == 6)
	{
		ft_putstr("error 6 during GNL\n");
		if (line)
			free(line);
		free_start(start, y);
	}
	exit(1);
}

void		error_draw(t_fdf *start, int d)
{
	if (d == 1)
	{
		ft_putstr("error_draw malloc mlx 1\n");
		free_start(start, start->h);
	}
	if (d == 2)
	{
		ft_putstr("error_draw 2 malloc win\n");
		free(start->mlx);
		free_start(start, start->h);
	}
	exit(1);
}
