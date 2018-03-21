/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lauch_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:53:30 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/14 13:53:32 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_pos(t_fdf *global)
{
	int y;
	int x;
	int y_max;
	int x_max;

	y_max = global->pad * (global->height - 1);
	x_max = global->pad * (global->width - 1);
	y = 0;
	while (y_max++ <= HEIGHT)
		y++;
	x = 0;
	while (x_max++ <= WIDTH)
		x++;
	global->coords.pos[0] = y / 2 + global->coords.move[0];
	global->coords.pos[1] = x / 2 + global->coords.move[1];
}

void		launch_map(t_fdf *global)
{
	int	coord_src[2];
	int	coord_dst[2];
	int x;
	int y;

	y = -1;
	init_pos(global);
	if (!global->img.p_mlx && !global->img.p_win)
	{
		global->img.p_mlx = mlx_init();
		global->img.p_win = mlx_new_window(global->img.p_mlx, WIDTH, HEIGHT, global->name);
	}
	global->img.p_img = mlx_new_image(global->img.p_mlx, WIDTH, HEIGHT);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img, &global->img.bpp, &global->img.size, &global->img.endian);
	while (++y < global->height)
	{
		x = -1;
		while (++x < global->width)
		{
			coord_src[0] = y * global->pad + global->coords.pos[0];
			coord_src[1] = x * global->pad + global->coords.pos[1];
			if (x < global->width - 1)
			{
				coord_dst[0] = y * global->pad + global->coords.pos[0];
				coord_dst[1] = (x + 1) * global->pad + global->coords.pos[1];
				draw_segment(coord_src, coord_dst, global);
			}
			if (y < global->height - 1)
			{
				coord_dst[0] = (y + 1) * global->pad + global->coords.pos[0];
				coord_dst[1] = x * global->pad + global->coords.pos[1];
				draw_segment(coord_src,	coord_dst, global);
			}
		}
	}
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win,
							global->img.p_img, 0, 0);
}
