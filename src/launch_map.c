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

static int	*init_pos(int *pos, t_fdf *global)
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
	pos[0] = y / 2;
	pos[1] = x / 2;
	return (pos);
}

void		launch_map(void *p_mlx, void *p_win, t_fdf *global)
{
	int	coord_src[2];
	int	coord_dst[2];
	int x;
	int y;
	int pos[2];

	y = -1;
	init_pos(pos, global);
	while (++y < global->height)
	{
		x = -1;
		while (++x < global->width)
		{
			coord_src[0] = y * global->pad + pos[0];
			coord_src[1] = x * global->pad + pos[1];
			if (x < global->width - 1)
			{
				coord_dst[0] = y * global->pad + pos[0];
				coord_dst[1] = (x + 1) * global->pad + pos[1];
				draw_segment(coord_src, coord_dst, p_mlx, p_win);
			}
			if (y < global->height - 1)
			{
				coord_dst[0] = (y + 1) * global->pad + pos[0];
				coord_dst[1] = x * global->pad + pos[1];
				draw_segment(coord_src,	coord_dst, p_mlx, p_win);
			}
		}
	}
}
