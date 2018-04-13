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

static int		check_map(char *line, int len_array)
{
	int			i;
	static int	cpt_x = 0;

	if (cpt_x == 0)
		cpt_x = len_array;
	if ((cpt_x != len_array) || (len_array == 0))
		error("not a valid map");
	i = -1;
	while (line[++i])
	{
		if ((line[i] == ' ') || (line[i] == '-')
			|| (line[i] >= '0' && line[i] <= '9'))
			;
		else
			error("not a valid map");
	}
	return (1);
}

static void		*init_tab(t_point *coords, int len_array, int cpt)
{
	int i;

	if (!(coords->points = (int**)ft_memalloc(sizeof(int*) * cpt)))
		return (NULL);
	i = -1;
	while (++i < cpt)
	{
		if (!(coords->points[i] = (int*)ft_memalloc(sizeof(int) * len_array)))
			return (NULL);
	}
	return (NULL);
}

static void		fill_tab(t_point *coords, char **array, int y, int len_array)
{
	int x;

	x = -1;
	while (++x < len_array)
		coords->points[y][x] = ft_atoi(array[x]);
}

static t_fdf	*parse_coords(t_fdf *global, char *line, int cpt)
{
	char		**array;
	int			len_array;
	static int	y = -1;

	len_array = count_word(line, ' ');
	y++;
	if ((check_map(line, len_array)) == 1)
	{
		array = ft_strsplit(line, ' ');
		if (!global->coords.points)
			init_tab(&global->coords, len_array, cpt);
		fill_tab(&global->coords, array, y, len_array);
		global->width = len_array;
		global->height = cpt;
		free_array(array, len_array);
	}
	else
		return (0);
	return (global);
}

t_fdf			*launch_parse(int fd, t_fdf *global, char **av)
{
	int		ret;
	int		cpt;
	char	*line;

	line = NULL;
	cpt = 0;
	init_struct_global(global);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		cpt++;
	}
	if ((close(fd)) == -1)
		error("closed() failed");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("open() failed");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		parse_coords(global, line, cpt);
		ft_strdel(&line);
	}
	return (global);
}
