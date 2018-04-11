/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:05:15 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/06 15:05:18 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_coord(t_fdf *global)
{
	int i;

	i = -1;
	while (++i < global->height)
		ft_memdel((void**)&global->coords.points[i]);
	ft_memdel((void**)&global->coords.points);
}

void free_array(char **array, int len_array)
{
	int i;

	i = -1;
	while (++i < len_array)
		ft_memdel((void**)&array[i]);
	ft_memdel((void**)&array);
}
