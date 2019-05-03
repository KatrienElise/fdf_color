/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_align.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/28 15:14:15 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/02 17:19:47 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	align_map(t_fdf *start)
{
	int		add_x;
	int		add_y;
	int		i;
	int		align_x;
	int		align_y;

	align_x = MID_W - ((start->w / 2) * start->dist);
	align_y = MID_H - ((start->h / 2) * start->dist);
	check_align(start);
	add_x = (align_x - start->sx) + start->add_hor;
	add_y = (align_y - start->sy) + start->add_vert;
	i = 0;
	while (i < (start->w * start->h))
	{
		if (start->view == 1)
			iso(&start->tmp[i][0], &start->tmp[i][1], start->tmp[i][2]);
		start->tmp[i][0] = start->tmp[i][0] + add_x;
		start->tmp[i][1] = start->tmp[i][1] + add_y;
		i++;
	}
	start->view = 0;
}

void		check_align(t_fdf *start)
{
	if (start->move_vert != 0 || start->move_hor != 0)
	{
		if (start->move_vert < 0)
			start->add_vert += 10;
		if (start->move_vert > 0)
			start->add_vert -= 10;
		if (start->move_hor < 0)
			start->add_hor += 10;
		if (start->move_hor > 0)
			start->add_hor -= 10;
		start->move_vert = 0;
		start->move_hor = 0;
	}
}
