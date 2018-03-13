/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:47:45 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/10 11:47:46 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		draw_horizontal_segment(int x1, int y1, int dx, int dy, int xinc, int yinc, void *ptr_mlx, void *ptr_win)
{
	int i;
	int cumul;

	cumul = dx / 2;
	i = -1;
	while (++i < dx)
	{
		x1 += xinc;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			y1 += yinc;
		}
		mlx_pixel_put(ptr_mlx, ptr_win, x1, y1, 0xFFFFFF);
	}
}

static void		draw_vertical_segment(int x1, int y1, int dx, int dy, int xinc, int yinc, void *ptr_mlx, void *ptr_win)
{
	int i;
	int cumul;

	cumul = dy / 2;
	i = -1;
	while (++i < dy)
	{
		y1 += yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			x1 += xinc;
		}
		mlx_pixel_put(ptr_mlx, ptr_win, x1, y1, 0xFFFFFF);
	}
}

void			draw_segment(int x1, int y1, int x2, int y2, void *ptr_mlx, void *ptr_win)
{
	int dx;
	int dy;
	int xinc;
	int yinc;

	dx = x2 - x1;
	dy = y2 - y1;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(ptr_mlx, ptr_win, x1, y1, 0xFFFFFF);
	if (dx > dy)
		draw_horizontal_segment(x1, y1, dx, dy, xinc, yinc, ptr_mlx, ptr_win);
	else
		draw_vertical_segment(x1, y1, dx, dy, xinc, yinc, ptr_mlx, ptr_win);
}
