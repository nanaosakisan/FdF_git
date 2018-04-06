/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:02:01 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 15:55:18 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		zoom(t_fdf *global, int key)
{
	if (key != 116 && key != 121)
		return (0);
	if (key == 116)
	{
		global->pad = global->pad + 1;
		global->coords.pos[0] = global->coords.pos[0] - 5;
		global->coords.pos[1] = global->coords.pos[1] - 9;
	}
	if (key == 121)
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

int		rotation_z(t_fdf *global, int key)
{
	static int	cpt;

	if (key != 256 && key != 47 && key != 43)
		return (0);
	if (key == 256)
	{
		if (cpt == 2)
			cpt = 0;
		else
			cpt++;
	}
    if (key == 47)
	{
		(cpt == 0) ? (global->coords.angle_x = global->coords.angle_x + 0.1) :
							(global->coords.angle_x = global->coords.angle_x);
		(cpt == 1) ? (global->coords.angle_y = global->coords.angle_y + 0.1) :
							(global->coords.angle_y = global->coords.angle_y);
		(cpt == 2) ? (global->coords.angle_z = global->coords.angle_z + 0.1) :
							(global->coords.angle_z = global->coords.angle_z);

	}
	if (key == 43)
	{
		(cpt == 0) ? (global->coords.angle_x = global->coords.angle_x - 0.1) :
							(global->coords.angle_x = global->coords.angle_x);
		(cpt == 1) ? (global->coords.angle_y = global->coords.angle_y - 0.1) :
							(global->coords.angle_y = global->coords.angle_y);
		(cpt == 2) ? (global->coords.angle_z = global->coords.angle_z - 0.1) :
							(global->coords.angle_z = global->coords.angle_z);
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	launch_map(global);
	return (1);
}

int		increase_decrease_z(t_fdf *global, int key)
{
	if (key != 69 && key != 78)
		return (0);
	if (key == 69)
		global->pad_z = global->pad_z + 1;
	if (key == 78)
		global->pad_z = global->pad_z - 1;
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	launch_map(global);
	return (1);
}

int		display_color(t_fdf *global, int key)
{
	if (key != 83 && key != 85 && key !=86 && key != 88 && key != 89 && key != 92)
		return (0);
	if (key == 89 || key == 92)
		(key == 92) ? (global->coords.color = global->coords.color + 0x080000) : (global->coords.color = global->coords.color - 0x080000);
	if (key == 86 || key == 88)
		(key == 88) ? (global->coords.color = global->coords.color + 0x000800) : (global->coords.color = global->coords.color - 0x000800);
	if (key == 83 || key == 85)
		(key == 85) ? (global->coords.color = global->coords.color - 0x000008) : (global->coords.color = global->coords.color + 0x000008);
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	launch_map(global);
	return (1);
}
