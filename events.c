/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 11:29:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/02 18:18:23 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		deal_key2(int keycode, t_fdf *start)
{
	if (keycode == 49)
	{
		start->reset_click = 1;
		start->add_vert = 0;
		start->add_hor = 0;
	}
	else if (keycode == 126)
		start->move_vert = 1;
	else if (keycode == 125)
		start->move_vert = -1;
	else if (keycode == 123)
		start->move_hor = 1;
	else if (keycode == 124)
		start->move_hor = -1;
	else if (keycode == 257)
		start->crazy = 1;
	else if (keycode == 34)
	{
		start->reset_click = 1;
		start->add_vert = 0;
		start->add_hor = 0;
		start->view = 1;
	}
	else
		start->no_event = 1;
	return (0);
}

int		deal_key(int keycode, t_fdf *start)
{
	if (keycode == 53)
	{
		free_all(start);
		exit(0);
	}
	else if (keycode == 27)
		start->z_mod -= .8;
	else if (keycode == 24)
		start->z_mod += .8;
	else if (keycode == 7)
		start->rx_click = 1;
	else if (keycode == 8)
		start->rx_click = -1;
	else if (keycode == 16)
		start->ry_click = 1;
	else if (keycode == 32)
		start->ry_click = -1;
	else if (keycode == 6)
		start->rz_click = 1;
	else if (keycode == 0)
		start->rz_click = -1;
	else
		deal_key2(keycode, start);
	draw(start);
	return (0);
}

int		mouse_press(int button, int x, int y, t_fdf *start)
{
	if (x > 0 && x < WINW && y > 0 && y < WINH)
	{
		if (button == 4)
			start->scroll = 1;
		if (button == 5)
			start->scroll = -1;
		draw(start);
	}
	return (0);
}
