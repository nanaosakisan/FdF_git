/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:29:25 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/10 14:29:26 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_coords(t_point *coords)
{
	int x;
	int y;

	y = -1;
	while (coords->points[++y])
	{
		x = -1;
		while (coords->points[y][++x])
		{
			ft_putnbr(coords->points[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
