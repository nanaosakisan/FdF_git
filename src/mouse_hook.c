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
	int i;

	i = 1;
	if (!x && !y)
		return (0);
	if (key == i)
	{
		global->pad = global->pad + 1;
		global->coords.move[0] = global->coords.move[0];
		global->coords.move[1] = global->coords.move[1];
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		mouse_hook(int key, int x, int y, t_fdf *global)
{
	int i;

	i = 0;
	while ((i < global->len_array_mouse) && !global->function_mouse[i](global, key, x, y))
		i++;
	return (0);
}
