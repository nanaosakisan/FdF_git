/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:38:33 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/10 13:38:35 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		*init_tab(t_point *coords, int len_array, int cpt)
{
	int i;

	ft_putendl("init tab");
	if (!(coords->points = (int**)ft_memalloc(sizeof(int*) * cpt)))
		return (NULL);
	i = -1;
	while (++i < cpt)
	{
		if (!(coords->points[i] = (int*)ft_memalloc(sizeof(int) * len_array)))
			return (NULL);
	}
	return (coords);
}

static t_point	*fill_tab(t_point *coords, char **array, int y, int len_array)
{
	int x;
	int i;

	x = -1;
	i = -1;
	ft_putstr("len_array = ");
	ft_putnbr_endl(len_array);
	ft_putstr("y = ");
	ft_putnbr_endl(y);
	while (++i < len_array)
	{
		ft_putnbr(ft_atoi(array[i]));
		ft_putchar(' ');
	}
	ft_putchar('\n');
	while (++x < len_array)
	{
		ft_putstr("x = ");
		ft_putnbr_endl(x);
		coords->points[y][x] = ft_atoi(array[x]);
		ft_putstr("z = ");
		ft_putnbr_endl(ft_atoi(array[x]));
	}
	return (coords);

}

t_point			*parse_coords(t_point *coords, char *line, int cpt)
{
	char		**array;
	int			len_array;
	static int 	y = -1;

	len_array = count_word(line, ' ');
	// ft_putstr("line = ");
	// ft_putendl(line);
	if (!coords->points)
		init_tab(coords, len_array, cpt);
	y++;
	array = ft_strsplit(line, ' ');
	fill_tab(coords, array, y, len_array);
	return (coords);
}
