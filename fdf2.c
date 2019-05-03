/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf2.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 11:36:44 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/02 12:00:02 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_digit(t_fdf *start, char **str, t_int b, int y)
{
	char	*digit;

	digit = ft_strsub(str[b.x], 0, b.c - 1);
	start->cords[y][b.x] = ft_atoi(digit);
	free(digit);
}

void	fill_rest(t_fdf *start, t_int b, int y)
{
	while (b.x <= start->w)
	{
		start->cords[y][b.x] = 0;
		b.x++;
	}
}