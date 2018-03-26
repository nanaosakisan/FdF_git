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
	int 	fd;
	t_fdf	global;

	if (ac != 2 || !av)
		error("usage: ./fdf filename");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			error("open() failed");
		global.name = av[1];
		launch_parse(fd, &global);
		launch_map(&global);
		mlx_key_hook(global.img.p_win, deal_key, (void*)&global);
		// mlx_mouse_hook(global.img.p_win, deal_key, (void*)0);
		mlx_loop(global.img.p_mlx);
		if ((close(fd)) == -1)
			error("closed() failed");
	}
	return (0);
}
