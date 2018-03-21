/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:47:03 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/11 13:47:07 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_struct_coord(t_fdf *global)
{
	global->coords.points = NULL;
	global->coords.pos[0] = 0;
	global->coords.pos[1] = 0;
	global->coords.move[0] = 0;
	global->coords.move[1] = 0;
}

static void		init_struct_img(t_fdf *global)
{

	global->img.bpp = 0;
	global->img.size = 0;
	global->img.endian = 0;
	global->img.p_mlx = NULL;
	global->img.p_win = NULL;
	global->img.p_img = NULL;
	global->img.img_addr = NULL;
}

static void		init_struct_tmp(t_fdf *global)
{
	global->tmp.pad = global->pad;
}

void			init_struct_global(t_fdf *global)
{
	global->height = 0;
	global->width = 0;
	global->pad = 30;
	global->function[0] = &init_map;
	global->function[1] = &close_map;
	global->function[2] = &zoom_out;
	global->function[3] = &zoom_in;
	global->function[4] = &move_up;
	global->function[5] = &move_down;
	global->function[6] = &move_right;
	global->function[7] = &move_left;
	global->len_array = 8;
	init_struct_coord(global);
	init_struct_img(global);
	init_struct_tmp(global);
}
