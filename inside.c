/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inside.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 16:41:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/04/29 10:46:11 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		inside_square(t_fdf *start)
{
	if (start->x0 > 0 && start->x0 < WINW && start->y0 > 0 && start->y0 < WINH)
		return (1);
	else if (start->x1 > 0 && start->x1 < WINW && start->y1 > 0 &&\
	start->y1 < WINH)
		return (1);
	return (0);
}
