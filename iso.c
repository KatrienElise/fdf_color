/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iso.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 13:24:00 by kblum          #+#    #+#                */
/*   Updated: 2019/05/02 19:01:06 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*deze wordt niet gebruikt,
de iso_loop functie is nu onderdeel van de align map*/
void	iso_loop(t_fdf *start)
{
	int i;

	i = 0;
	while (i < start->w * start->h)
	{
		iso(&start->tmp[i][0], &start->tmp[i][1], start->tmp[i][2]);
		i++;
	}
}

void	iso(double *x, double *y, double z)
{
	int previous_x;
	int previous_y;
	previous_x = (int)*x;
	previous_y = (int)*y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (int)-z + (previous_x + previous_y) * sin(0.523599);

}