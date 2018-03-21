/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:52:12 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/21 16:52:14 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	*isometric(int x, int y)
{
	float new_points[2]

	new_points[1] = (x - y) * (PADDING / 2);
	new_points[0] = (x + y) * (PADDING / 2);
	return(new_points);
}
