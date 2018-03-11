/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:47:03 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/11 13:47:07 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_struct(t_fdf *global)
{
	global->coords.points = NULL;
	global->coords.dx = 0;
	global->coords.dy = 0;
	global->coords.xinc = 0;
	global->coords.yinc = 0;
	global->y_max = 0;
	global->x_max = 0;
}