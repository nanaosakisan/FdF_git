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
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	void	*p_mlx;
	void	*p_win;
	int 	fd;
	int 	cpt;
	int 	ret;
	char 	*line;
	t_fdf	global;
	int		x;
	int		y;

	if (ac != 2 || !av)
		error("usage: ./fdf filename");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			error("open() failed");
		line = NULL;
		cpt = 0;
		init_struct(&global);
		while ((ret = get_next_line(fd, &line)) > 0)
			cpt++;
		if ((lseek(fd, 0, SEEK_SET)) == -1)
			error("lseek() failed");
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			parse_coords(&global, line, cpt);
			ft_strdel(&line);
		}
		// print_coords(&global);
		p_mlx = mlx_init();
		p_win = mlx_new_window(p_mlx, 500, 500, "Buh");
		y = 0;
		while (y < global.height)
		{
			x = 0;
			while (x < global.width)
			{
				if (x < global.width - 1)
					draw_segment(x * PADDING, y * PADDING, (x + 1) * PADDING, y * PADDING, p_mlx, p_win);
				if (y < global.height - 1)
					draw_segment(x * PADDING, y * PADDING, x * PADDING, (y + 1) * PADDING, p_mlx, p_win);
				x++;
			}
			y++;
		}
		mlx_loop(p_mlx);
		if ((close(fd)) == -1)
			error("closed() failed");
	}
	return (0);
}
