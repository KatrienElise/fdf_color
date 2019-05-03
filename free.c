/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 17:11:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 11:51:03 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_start(t_fdf *start, int j)
{
	int y;

	y = 0;
	while (y < j)
	{
		free(start->cords[y]);
		y++;
	}
	free(start->cords);
	free(start);
}

void	free_str(char **str)
{
	int		y;

	y = 0;
	while (str[y])
	{
		free(str[y]);
		y++;
	}
	free(str);
}

void	free_all(t_fdf *start)
{
	int y;

	y = 0;
	while (y < start->h)
	{
		free(start->cords[y]);
		y++;
	}
	y = 0;
	while (y < (start->h * start->w))
	{
		free(start->map[y]);
		free(start->reset[y]);
		y++;
	}
	free(start->cords);
	free(start->map);
	free(start->reset);
	free(start->mlx);
	free(start->win);
	free(start->img);
	free(start);
}
