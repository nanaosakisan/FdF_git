/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:02:01 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/21 15:02:03 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		zoom_in(t_fdf *global, int key)
{
	int	i;

	i = 116;
	if (key == i)
	{
		global->pad = global->pad + 10;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		zoom_out(t_fdf *global, int key)
{
	int i;

	i = 121;
	if (key == i)
	{
		if (global->pad > 10)
		{
			global->pad = global->pad - 10;
			mlx_destroy_image(global->img.p_mlx, global->img.p_img);
			launch_map(global);
		}
		else
			global->pad = global->pad + 10;
		return (1);
	}
	return (0);
}

int		move_up(t_fdf *global, int key)
{
	int i;

	i = 126;
	if (key == i)
	{
		global->coords.move[0] = global->coords.move[0] - 10;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		move_down(t_fdf *global, int key)
{
	int i;

	i = 125;
	if (key == i)
	{
		global->coords.move[0] = global->coords.move[0] + 10;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}
