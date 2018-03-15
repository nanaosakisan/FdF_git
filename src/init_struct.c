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
	global->coords.dx = 0;
	global->coords.dy = 0;
	global->coords.xinc = 0;
	global->coords.yinc = 0;
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

void			init_struct_global(t_fdf *global)
{
	global->height = 0;
	global->width = 0;
	global->pad = 30;
	init_struct_coord(global);
	init_struct_img(global);
}
