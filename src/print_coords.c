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

void	print_coords(t_fdf *global)
{
	int x;
	int y;

	y = -1;
	while (++y < global->height)
	{
		x = -1;
		while (++x < global->width)
		{
			ft_putnbr(global->coords.points[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
