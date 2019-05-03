/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 15:39:26 by rsteigen       #+#    #+#                */
/*   Updated: 2019/04/29 11:28:03 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_fdf(argv[1]);
	else
		ft_putstr("usage: ./fdf name_file\n");
	getchar();
	return (0);
}
