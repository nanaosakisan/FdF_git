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

static void	init_window(t_fdf *global)
{
	global->img.p_mlx = mlx_init();
	global->img.p_win = mlx_new_window(global->img.p_mlx, WIDTH, HEIGHT,
																global->name);
}

static void	x_gestion(t_fdf *global, int x, int y, float *coord_src)
{
	float coord_dst[3];
	float coord_rot_dst[3];
	float coord_rot_src[3];

	coord_dst[0] = y * global->pad;
	coord_dst[1] = (x + 1) * global->pad;
	coord_dst[2] = global->coords.points[y][x + 1] * global->pad;
	rotation(global, coord_dst, coord_rot_dst);
	rotation(global, coord_src, coord_rot_src);
	coord_rot_src[0] = coord_rot_src[0] + global->coords.pos[0];
	coord_rot_src[1] = coord_rot_src[1] + global->coords.pos[1];
	coord_rot_dst[0] = coord_rot_dst[0] + global->coords.pos[0];
	coord_rot_dst[1] = coord_rot_dst[1] + global->coords.pos[1];
	draw_segment(coord_rot_src, coord_rot_dst, global);
}

static void	y_gestion(t_fdf *global, int x, int y, float *coord_src)
{
	float coord_dst[3];
	float coord_rot_dst[3];
	float coord_rot_src[3];

	coord_dst[0] = (y + 1) * global->pad;
	coord_dst[1] = x * global->pad;
	coord_dst[2] = global->coords.points[y + 1][x] * global->pad;
	rotation(global, coord_dst, coord_rot_dst);
	rotation(global, coord_src, coord_rot_src);
	coord_rot_src[0] = coord_rot_src[0] + global->coords.pos[0];
	coord_rot_src[1] = coord_rot_src[1] + global->coords.pos[1];
	coord_rot_dst[0] = coord_rot_dst[0] + global->coords.pos[0];
	coord_rot_dst[1] = coord_rot_dst[1] + global->coords.pos[1];
	draw_segment(coord_rot_src,	coord_rot_dst, global);
}

void		launch_map(t_fdf *global)
{
	float	coord_src[3];
	int		y;
	int		x;

	y = -1;
	init_pos(global);
	if (!global->img.p_mlx && !global->img.p_win)
		init_window(global);
	global->img.p_img = mlx_new_image(global->img.p_mlx, WIDTH, HEIGHT);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img,
					&global->img.bpp, &global->img.size, &global->img.endian);
	while (++y < global->height)
	{
		x = -1;
		while (++x < global->width)
		{
			coord_src[0] = y * global->pad;
			coord_src[1] = x * global->pad;
			coord_src[2] = global->coords.points[y][x] * global->pad;
			if (x < global->width - 1)
				x_gestion(global, x, y, coord_src);
			if (y < global->height - 1)
				y_gestion(global, x, y, coord_src);
		}
	}
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win,
													global->img.p_img, 0, 0);
}
