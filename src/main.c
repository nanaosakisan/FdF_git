/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:58:32 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/08 14:58:33 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		error(char *str)
{
	ft_putstr(str);
	return (0);
}

void	init_struct(t_point *coords)
{
	coords->points = NULL;
	coords->dx = 0;
	coords->dy = 0;
	coords->xinc = 0;
	coords->yinc = 0;
}

int		main(int ac, char **av)
{
	// void	*ptr_mlx;
	// void	*ptr_win;
	int 	fd;
	int 	cpt;
	int 	ret;
	char 	*line;
	t_point	coords;

	if (ac != 2)
		error("usage: ./fdf filename\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		line = NULL;
		cpt = 0;
		init_struct(&coords);
		while ((ret = get_next_line(fd, &line)) > 0)
			cpt++;
		lseek(fd, 0, SEEK_SET);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			parse_coords(&coords, line, cpt);
			ft_putendl("fin parsing line");
			ft_strdel(&line);
		}
		print_coords(&coords);
	}
	// ptr_mlx = mlx_init();
	// ptr_win = mlx_new_window(ptr_mlx, 500, 500, "Buh");
	// init_struct(&coords, x1, y1, x2, y2);
	// draw_segment(&coords, ptr_mlx, ptr_win);
	// mlx_loop(ptr_mlx);
	return (0);
}
