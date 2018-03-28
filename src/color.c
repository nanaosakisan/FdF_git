/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:05:44 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 19:42:31 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	display_color(t_fdf *global)
{
	int			color;

	color = 0xFFFFFF;
	color = color - global->coords.points[global->tmp.y][global->tmp.x] * global->pad_z;
	printf("color = %x\n", color);
	return (color);
}
