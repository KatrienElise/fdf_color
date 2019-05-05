/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 16:57:09 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/03 15:56:16 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fdf_fill_cords(t_fdf *start, char **str, int y)
{
	t_int		b;

	b.x = 0;
	while (str[b.x])
	{
		b.ki = 0;
		b.i = 0;
		b.c = b.i;
		while (str[b.x][b.i])
		{
			b.c++;
			if (str[b.x][b.i] == ',')
			{
				b.ki = 1;
				fill_digit(start, str, b, y);
			}
			b.i++;
		}
		if (b.ki != 1)
			start->cords[y][b.x] = ft_atoi(str[b.x]);
		b.x++;
	}
	fill_rest(start, b, y);
}

void	fdf_get_co(int fd, t_fdf *start)
{
	char	**str;
	char	*line;
	int		y;
	int		gnl;

	y = 0;
	start->cords = (int**)malloc(sizeof(int*) * start->h);
	if (!start->cords)
		error(2, start);
	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		str = ft_strsplit((char const*)line, ' ');
		check_error(start, str, y, line);
		start->cords[y] = (int*)malloc(sizeof(int) * start->w);
		if (!start->cords[y])
			error_gnl(6, start, y, line);
		fdf_fill_cords(start, str, y);
		y++;
		free(line);
		free_str(str);
		gnl = get_next_line(fd, &line);
	}
	check_error_get_co(start, line, y, gnl);
}

int		fdf_get_w(char *line)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (line[i] != '\0')
	{
		if (line[i] && line[i] != ' ')
		{
			while (line[i] && line[i] != ' ')
				i++;
			w++;
		}
		if (line[i])
			i++;
	}
	return (w);
}

void	fdf_get_wh(int fd, t_fdf *start)
{
	int		h;
	int		i;
	int		w;
	char	*line;

	h = 0;
	i = 0;
	if (get_next_line(fd, &line) == 1)
	{
		w = fdf_get_w(line);
		free(line);
		h++;
	}
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		h++;
	}
	if (h == 0)
		error(3, start);
	start->w = w;
	start->h = h;
}

int		ft_fdf(char *file)
{
	int		fd1;
	int		fd2;
	t_fdf	*start;

	fd1 = open(file, O_RDONLY);
	if (fd1 == -1)
		error_fd(1);
	start = NEW(t_fdf);
	if (!start)
		error_fd(2);
	fdf_get_wh(fd1, start);
	if (close(fd1) == -1)
		error(4, start);
	fd2 = open(file, O_RDONLY);
	if (fd2 == -1)
		error(1, start);
	fdf_get_co(fd2, start);
	if (close(fd2) == -1)
		error(4, start);
	dist_start(start);
	setup(start);
	return (0);
}
