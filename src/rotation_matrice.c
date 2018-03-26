/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:38:48 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/22 14:38:51 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	x_rot(t_fdf *global, float *coord, float *point_rot)
{
	point_rot[0] = (cos(global->coords.angle_x) * coord[0]) - (sin(global->coords.angle_x) * coord[2]);
	point_rot[1] = coord[1];
	point_rot[2] = (sin(global->coords.angle_x) * coord[0]) + (cos(global->coords.angle_x) * coord[2]);
}

static void	y_rot(t_fdf *global, float *coord, float *point_rot)
{
	point_rot[0] = coord[0];
	point_rot[1] = (cos(global->coords.angle_y) * coord[1]) + (sin(global->coords.angle_y) * coord[2]);
	point_rot[2] = (-sin(global->coords.angle_y) * coord[1]) + (cos(global->coords.angle_y) * coord[2]);
}

static void	z_rot(t_fdf *global, float *coord, float *point_rot)
{
	point_rot[0] = (sin(global->coords.angle_z) * coord[1]) + (cos(global->coords.angle_z) * coord[0]);
	point_rot[1] = (cos(global->coords.angle_z) * coord[1]) - (sin(global->coords.angle_z) * coord[0]);
	point_rot[2] = coord[2];
}

void rotation(t_fdf *global, float *coord, float *point_rot)
{
	float rot_x[3];
	float rot_y[3];

	x_rot(global, coord, rot_x);
	y_rot(global, rot_x, rot_y);
	z_rot(global, rot_y, point_rot);
}
