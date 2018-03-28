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
	int	i;
	int j;

	i = 116;
	j = 121;
	if (key == i)
	{
		global->pad = global->pad + 1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
	{
		if (global->pad > 0)
		{
			global->pad = global->pad - 1;
			mlx_destroy_image(global->img.p_mlx, global->img.p_img);
			launch_map(global);
		}
		else
			global->pad = global->pad + 1;
		return (1);
	}
	return (0);
}

int		rotation_z(t_fdf *global, int key)
{
	static int	cpt;
	int			i;
	int			j;
	int			k;

	k = 256;
	if (key == k)
	{
		if (cpt == 2)
			cpt = 0;
		else
			cpt++;
	}
	i = 47;
    j = 43;
    if (key == i)
	{		
		(cpt == 0) ? (global->coords.angle_x = global->coords.angle_x + 0.1) : (global->coords.angle_x = global->coords.angle_x);
		(cpt == 1) ? (global->coords.angle_y = global->coords.angle_y + 0.1) : (global->coords.angle_y = global->coords.angle_y);
		(cpt == 2) ? (global->coords.angle_z = global->coords.angle_z + 0.1) : (global->coords.angle_z = global->coords.angle_z);
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
	{
		(cpt == 0) ? (global->coords.angle_x = global->coords.angle_x - 0.1) : (global->coords.angle_x = global->coords.angle_x);
		(cpt == 1) ? (global->coords.angle_y = global->coords.angle_y - 0.1) : (global->coords.angle_y = global->coords.angle_y);
		(cpt == 2) ? (global->coords.angle_z = global->coords.angle_z - 0.1) : (global->coords.angle_z = global->coords.angle_z);
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		increase_decrease_z(t_fdf *global, int key)
{
	int i;
	int j;

	i = 69;
	j = 78;
	if (key == i)
	{
		global->pad_z = global->pad_z + 1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
	{
		global->pad_z = global->pad_z - 1;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}
