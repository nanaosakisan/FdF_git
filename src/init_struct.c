/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:47:03 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 18:05:04 by iporsenn         ###   ########.fr       */
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
	global->coords.angle_x = 0.2;
	global->coords.angle_y = -0.1;
	global->coords.angle_z = 0;
	global->coords.color = 0xFFFFFF;
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
	global->tmp.pad_z = global->pad_z;
	global->tmp.x = -1;
	global->tmp.y = -1;
}

void			init_struct_global(t_fdf *global)
{
	global->height = 0;
	global->width = 0;
	global->pad = 50;
	global->pad_z = 0;
	global->function[0] = &init_map;
	global->function[1] = &close_map;
	global->function[2] = &zoom;
	global->function[3] = &move_up_and_down;
	global->function[4] = &move_right_and_left;
	global->function[5] = &rotation_z;
	global->function[6] = &increase_decrease_z;
	global->function[7] = &display_color;
	global->function_mouse[0] = &zoom_clic;
	global->len_array = 8;
	global->len_array_mouse = 1;
	init_struct_coord(global);
	init_struct_img(global);
	init_struct_tmp(global);
}
