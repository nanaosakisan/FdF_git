/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:47:45 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 18:54:00 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			mlx_pixel_put_to_image(t_fdf *global, int x, int y, int color)
{
	int i;

	if (global->img.endian == 0)
	{
		i = (global->img.size * y) + (x * (global->img.bpp / 8));
		global->img.img_addr[i] = mlx_get_color_value(global->img.p_mlx, color);
		global->img.img_addr[i + 1] = mlx_get_color_value(global->img.p_mlx, \
																	color >> 8);
		global->img.img_addr[i + 2] = mlx_get_color_value(global->img.p_mlx, \
																color >> 16);
	}
	else
	{
		i = (global->img.size * y) + (x * (global->img.bpp / 8));
		global->img.img_addr[i] = mlx_get_color_value(global->img.p_mlx, \
																color >> 16);
		global->img.img_addr[i + 1] = mlx_get_color_value(global->img.p_mlx, \
																	color >> 8);
		global->img.img_addr[i + 2] = mlx_get_color_value(global->img.p_mlx, \
																		color);
	}
}

static void		draw_horizon(float *coord, int *diff, int *inc, t_fdf *global)
{
	int		i;
	int		cumul;

	cumul = diff[1] / 2;
	i = -1;
	while (++i < diff[1])
	{
		coord[1] += inc[1];
		cumul += diff[0];
		if (cumul >= diff[1])
		{
			cumul -= diff[1];
			coord[0] += inc[0];
		}
		if ((coord[1] > 0 && coord[1] < WIDTH) && (coord[0] > 0 && coord[0] < \
																		HEIGHT))
			mlx_pixel_put_to_image(global, coord[1], coord[0], \
														global->coords.color);
	}
}

static void		draw_vertical(float *coord, int *diff, int *inc, t_fdf *global)
{
	int i;
	int cumul;

	cumul = diff[0] / 2;
	i = -1;
	while (++i < diff[0])
	{
		coord[0] += inc[0];
		cumul += diff[1];
		if (cumul >= diff[0])
		{
			cumul -= diff[0];
			coord[1] += inc[1];
		}
		if ((coord[1] > 0 && coord[1] < WIDTH) && (coord[0] > 0 && coord[0] < \
																		HEIGHT))
			mlx_pixel_put_to_image(global, coord[1], coord[0], \
														global->coords.color);
	}
}

void			draw_segment(float *coord_src, float *coord_dst, t_fdf *global)
{
	int diff[2];
	int inc[2];

	diff[0] = coord_dst[0] - coord_src[0];
	diff[1] = coord_dst[1] - coord_src[1];
	inc[0] = (diff[0] > 0) ? 1 : -1;
	inc[1] = (diff[1] > 0) ? 1 : -1;
	diff[0] = abs(diff[0]);
	diff[1] = abs(diff[1]);
	if ((coord_src[1] > 0 && coord_src[1] < WIDTH) && (coord_src[0] > 0 && \
														coord_src[0] < HEIGHT))
		mlx_pixel_put_to_image(global, coord_src[1], coord_src[0], \
														global->coords.color);
	if (diff[1] > diff[0])
		draw_horizon(coord_src, diff, inc, global);
	else
		draw_vertical(coord_src, diff, inc, global);
}
