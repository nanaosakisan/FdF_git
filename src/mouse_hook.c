/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:45:45 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/02 15:59:39 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int zoom_clic(t_fdf *global, int key, int x, int y)
{
	if (!x && !y && key != 1 && key != 2)
		return (0);
	if (key == 1)
	{
		global->pad = global->pad + 1;
		global->coords.pos[0] = global->coords.pos[0] - 5;
		global->coords.pos[1] = global->coords.pos[1] - 9;
	}
	if (key == 2)
	{
		if (global->pad > 0)
		{
			global->pad = global->pad - 1;
			global->coords.pos[0] = global->coords.pos[0] + 5;
			global->coords.pos[1] = global->coords.pos[1] + 9;
		}
		else
			global->pad = global->pad;
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	launch_map(global);
	return (1);
}

int		mouse_hook(int key, int x, int y, t_fdf *global)
{
	int i;

	i = 0;
	while ((i < global->len_array_mouse) && !global->function_mouse[i](global, key, x, y))
		i++;
	return (0);
}
