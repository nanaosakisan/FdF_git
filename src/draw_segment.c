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

static void		draw_hor_segment(int *coord, int *diff, int *inc, void **ptr)
{
	int i;
	int cumul;
	int x1;

	x1 = coord[1];
	cumul = diff[1] / 2;
	i = -1;
	while (++i < diff[1])
	{
		x1 += inc[1];
		cumul += diff[0];
		if (cumul >= diff[1])
		{
			cumul -= diff[1];
			coord[0] += inc[0];
		}
		mlx_pixel_put(ptr[0], ptr[1], x1, coord[0], 0xFFFFFF);
	}
}

static void		draw_ver_segment(int *coord, int *diff, int *inc, void **ptr)
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
		mlx_pixel_put(ptr[0], ptr[1], coord[1], coord[0], 0xFFFFFF);
	}
}

void			draw_segment(int *coord_src, int *coord_dst, void *p_mlx, void *p_win)
{
	int diff[2];
	int inc[2];
	void *ptr[2];

	diff[0] = coord_dst[0] - coord_src[0];
	diff[1] = coord_dst[1] - coord_src[1];
	inc[0] = (diff[0] > 0) ? 1 : -1;
	inc[1] = (diff[1] > 0) ? 1 : -1;
	diff[0] = abs(diff[0]);
	diff[1] = abs(diff[1]);
	ptr[0] = p_mlx;
	ptr[1] = p_win;
	mlx_pixel_put(p_mlx, p_win, coord_src[1], coord_src[0], 0xFFFFFF);
	if (diff[1] > diff[0])
		draw_hor_segment(coord_src, diff, inc, ptr);
	else
		draw_ver_segment(coord_src, diff, inc, ptr);
}
