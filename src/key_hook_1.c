/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:02:55 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/21 15:02:57 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		move_up_and_down(t_fdf *global, int key)
{
	int i;
	int j;

	i = 126;
	j = 125;
	if (key == i)
	{
		global->coords.move[0] = global->coords.move[0] - 10;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
	{
		global->coords.move[0] = global->coords.move[0] + 10;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		move_right_and_left(t_fdf *global, int key)
{
	int i;
	int j;

	i = 124;
	j = 123;
	if (key == i)
	{
		global->coords.move[1] = global->coords.move[1] + 10;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	if (key == j)
	{
		global->coords.move[1] = global->coords.move[1] - 10;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		init_map(t_fdf *global, int key)
{
	int i;

	i = 82;
	if (key == i)
	{
		global->pad = global->tmp.pad;
		global->coords.move[0] = 0;
		global->coords.move[1] = 0;
		global->coords.angle_x = 0;
		global->coords.angle_y = 0;
		global->coords.angle_z = 0;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		launch_map(global);
		return (1);
	}
	return (0);
}

int		close_map(t_fdf *global, int key)
{
	int i;

	i = 53;
	if (key == i)
	{
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		global->img.p_mlx = NULL;
		global->img.p_win = NULL;
		global->img.p_img = NULL;
		global->img.img_addr = NULL;
		exit(EXIT_FAILURE);
	}
	return (0);
}

int		deal_key(int key, t_fdf *global)
{
	int i;

	i = 0;
	while ((i < global->len_array) && !global->function[i](global, key))
		i++;
	return (0);
}
