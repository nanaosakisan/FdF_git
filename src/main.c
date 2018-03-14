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

int		deal_key(int key, t_fdf *global)
{
	if (key == 116)
	{
		global->pad = global->pad + 10;
		launch_map(p_mlx, p_win, global);

	}
	return (0);
}

int		main(int ac, char **av)
{
	void	*p_mlx;
	void	*p_win;
	int 	fd;
	t_fdf	global;

	if (ac != 2 || !av)
		error("usage: ./fdf filename");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			error("open() failed");
		launch_parse(fd, &global);
		global->p_mlx = mlx_init();
		global->p_win = mlx_new_window(p_mlx, WIDTH, HEIGHT, "Buh");
		launch_map(&global);
		mlx_key_hook(p_win, deal_key, (void*)&global);
		mlx_mouse_hook(p_win, deal_key, (void*)0);
		mlx_loop(p_mlx);
		if ((close(fd)) == -1)
			error("closed() failed");
	}
	return (0);
}
