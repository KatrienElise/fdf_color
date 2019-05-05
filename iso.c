/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iso.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 13:24:00 by kblum          #+#    #+#                */
/*   Updated: 2019/05/03 15:57:54 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	iso(double *x, double *y, double z)
{
	int previous_x;
	int previous_y;

	previous_x = (int)*x;
	previous_y = (int)*y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (int)-z + (previous_x + previous_y) * sin(0.523599);
}
