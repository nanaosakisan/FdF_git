/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:05:44 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/26 17:05:46 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	select_color(t_fdf *global)
{
	int color;
	int i;

	color = 0xFFFFFF;
	i = 0;
	while (i < global->bonus.buh)
		color = color - 20;
	return (color);
}
