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
#include <stdio.h>

void	free_coord(t_fdf *global)
{
	int i;

	i = -1;
	ft_putendl("buh");
	while (++i < global->height)
	{
		printf("adress before-> %p\n", global->coords.points[i]);
		free((void*)(global->coords.points[i]));
		printf("adress after-> %p\n", global->coords.points[i]);
		ft_putendl("nyup");
	}
	printf("pointer adress before-> %p\n", global->coords.points);
	free((void*)(global->coords.points));
	printf("pointer adress after-> %p\n", global->coords.points);
	ft_putendl("Jah");
}

void free_array(char **array, int len_array)
{
	int i;

	i = -1;
	while (++i < len_array)
		ft_memdel((void**)&array[i]);
	ft_memdel((void**)&array);
}
