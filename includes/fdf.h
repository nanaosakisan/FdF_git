/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:59:34 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/08 14:59:35 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include	"../minilibx_macos/mlx.h"
# include	"../libft/include/libft.h"

typedef	struct	s_point
{
	int **points;
	int dx;
	int dy;
	int	xinc;
	int yinc;
}				t_point;

int				main(int ac, char **av);
t_point			*parse_coords(t_point *coords, char *line, int cpt);
void			print_coords(t_point *coords);
// void			draw_segment(t_point *coords, void *ptr_mlx, void *ptr_win);
// void			init_struct(t_point *coords, int x1, int y1, int x2, int y2);

#endif
