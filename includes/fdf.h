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


# define	HEIGHT	500
# define	WIDTH	500
# define	PADDING 30

typedef	struct	s_point
{
	int **points;
	int dx;
	int dy;
	int	xinc;
	int yinc;
}				t_point;

typedef struct	s_fdf
{
	t_point coords;
	int		height;
	int 	width;
}				t_fdf;

int				main(int ac, char **av);
int				error(char *str);
void			init_struct(t_fdf *global);
t_fdf			*parse_coords(t_fdf *coords, char *line, int cpt);
void			print_coords(t_fdf *global);
void			draw_segment(int x1, int y1, int x2, int y2, void *p_mlx, void *p_win);
void			init_coords(t_point *coords);

#endif
