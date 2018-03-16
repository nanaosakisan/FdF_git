/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:27:17 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/16 13:27:20 by iporsenn         ###   ########.fr       */
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
		if ((global->pad * global->height < HEIGHT) && (global->pad * global->width < WIDTH))
		{
			mlx_destroy_image(global->img.p_mlx, global->img.p_img);
			launch_map(global);
		}
		else
			global->pad = global->pad - 10;
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

int		init_map(t_fdf *global, int key)
{
	int i;

	i = 82;
	if (key == i)
	{
		global->pad = global->tmp.pad;
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
