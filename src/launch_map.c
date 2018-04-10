/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lauch_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:53:30 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 18:14:02 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_window(t_fdf *global)
{
	int x;
	int y;

	global->img.p_mlx = mlx_init();
	global->img.p_win = mlx_new_window(global->img.p_mlx, WIDTH, \
										HEIGHT + HEIGHT_BONUS, global->name);
	x = global->pad * global->width - 1;
	y = global->pad * global->height - 1;
	while (x > WIDTH || y > HEIGHT)
	{
		global->pad = global->pad - 1;
		x = global->pad * global->width - 1;
		y = global->pad * global->height - 1;
	}
	global->tmp.pad = global->pad;
}

static void	x_gestion(t_fdf *global, int x, int y, float *coord_src)
{
	float	coord_dst[3];
	float	coord_rot_dst[3];
	float	coord_rot_src[3];

	coord_dst[0] = y * global->pad;
	coord_dst[1] = (x + 1) * global->pad;
	coord_dst[2] = global->coords.points[y][x + 1] * (global->pad + \
																global->pad_z);
	rotation(global, coord_dst, coord_rot_dst);
	rotation(global, coord_src, coord_rot_src);
	coord_rot_src[0] += global->coords.pos[0] + global->coords.move[0];
	coord_rot_src[1] += global->coords.pos[1] + global->coords.move[1];
	coord_rot_dst[0] += global->coords.pos[0] + global->coords.move[0];
	coord_rot_dst[1] += global->coords.pos[1] + global->coords.move[1];
	draw_segment(coord_rot_src, coord_rot_dst, global);
}

static void	y_gestion(t_fdf *global, int x, int y, float *coord_src)
{
	float	coord_dst[3];
	float	coord_rot_dst[3];
	float	coord_rot_src[3];

	coord_dst[0] = (y + 1) * global->pad;
	coord_dst[1] = x * global->pad;
	coord_dst[2] = global->coords.points[y + 1][x] * (global->pad + \
																global->pad_z);
	rotation(global, coord_dst, coord_rot_dst);
	rotation(global, coord_src, coord_rot_src);
	coord_rot_src[0] += global->coords.pos[0] + global->coords.move[0];
	coord_rot_src[1] += global->coords.pos[1] + global->coords.move[1];
	coord_rot_dst[0] += global->coords.pos[0] + global->coords.move[0];
	coord_rot_dst[1] += global->coords.pos[1] + global->coords.move[1];
	draw_segment(coord_rot_src, coord_rot_dst, global);
}

static void	lauch_draw(t_fdf *global)
{
	float		coord_src[3];

	global->tmp.y = -1;
	while (++global->tmp.y < global->height)
	{
		global->tmp.x = -1;
		while (++global->tmp.x < global->width)
		{
			coord_src[0] = global->tmp.y * global->pad;
			coord_src[1] = global->tmp.x * global->pad;
			coord_src[2] = global->coords.points[global->tmp.y][global->tmp.x] \
												* (global->pad + global->pad_z);
			if (global->tmp.x < global->width - 1)
				x_gestion(global, global->tmp.x, global->tmp.y, coord_src);
			if (global->tmp.y < global->height - 1)
				y_gestion(global, global->tmp.x, global->tmp.y, coord_src);
		}
	}
}

void		launch_map(t_fdf *global)
{
	static int	cpt = 0;

	if (!global->img.p_mlx && !global->img.p_win)
	{
		init_window(global);
		init_pos(global);
	}
	global->img.p_img = mlx_new_image(global->img.p_mlx, WIDTH, HEIGHT);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img,
					&global->img.bpp, &global->img.size, &global->img.endian);
	lauch_draw(global);
	cpt++;
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
													global->img.p_img, 0, 0);
	bonus(global);
}
