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

void		init_struct(t_point *coords, int i1, int y1, int x2, int y2)
{

	coords->x = x1;
	coords->y = y1;
	coords->dx = x2 - x1;
	coords->dy = y2 - y1;
	coords->xinc = (coords->dx > 0) ? 1 : -1;
	coords->yinc = (coords->dy > 0) ? 1 : -1;
	coords->dx = abs(coords->dx);
	coords->dy = abs(coords->dy);
}

static void		draw_horizontal_segment(t_point *coords, void *ptr_mlx, void *ptr_win)
{
	int i;
	int cumul;

	cumul = coords->dx / 2;
	i = -1;
	while (++i <= coords->dx)
	{
		coords->x += coords->xinc;
		cumul += coords->dy;
		if (cumul >= coords->dx)
		{
			cumul -= coords->dx;
			coords->y += coords->yinc;
		}
		mlx_pixel_put(ptr_mlx, ptr_win, coords->x, coords->y, 0xFFFFFF);
	}
}

static void		draw_vertical_segment(t_point *coords, void *ptr_mlx, void *ptr_win)
{
	int i;
	int cumul;

	cumul = coords->dy / 2;
	i = -1;
	while (++i <= coords->dy)
	{
		coords->y += coords->yinc;
		cumul += coords->dy;
		if (cumul >= coords->dy)
		{
			cumul -= coords->dy;
			coords->x += coords->xinc;
		}
		mlx_pixel_put(ptr_mlx, ptr_win, coords->x, coords->y, 0xFFFFFF);
	}
}

void			draw_segment(t_point *coords, void *ptr_mlx, void *ptr_win)
{
	mlx_pixel_put(ptr_mlx, ptr_win, coords->x, coords->y, 0xFFFFFF);
	if (coords->dx > coords->dy)
		draw_horizontal_segment(coords, ptr_mlx, ptr_win);
	else
		draw_vertical_segment(coords, ptr_mlx, ptr_win);
}
