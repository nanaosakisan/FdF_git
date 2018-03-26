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

int		zoom(t_fdf *global, int key)
{
	int	i;
	int j;

	i = 116;
	j = 121;
	if (key == i)
	{
		global->pad = global->pad + 10;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
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

int		rotation_z(t_fdf *global, int key)
{
	int i;
	int j;

	i = 69;
	j = 78;
	if (key == i)
	{
		global->coords.angle_z = global->coords.angle_z + 0.1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
	{
		global->coords.angle_z = global->coords.angle_z - 0.1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		rotation_x(t_fdf *global, int key)
{
	int i;
	int j;

	i = 91;
	j = 84;
	if (key == i)
	{
		global->coords.angle_x = global->coords.angle_x + 0.1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
	{
		global->coords.angle_x = global->coords.angle_x - 0.1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		rotation_y(t_fdf *global, int key)
{
	int i;
	int j;

	i = 88;
	j = 86;
	if (key == i)
	{
		global->coords.angle_y = global->coords.angle_y + 0.1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
	{
		global->coords.angle_y = global->coords.angle_y - 0.1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}

	return (0);
}
