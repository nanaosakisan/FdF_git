/* **********p**************************************************************** */
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

typedef	struct s_img
{
	void 	*p_mlx;
	void	*p_win;
	void	*p_img;
	char	*img_addr;
	int		bpp;
	int		size;
	int 	endian;
}				t_img;

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
	t_img	img;
	char 	*name;
	int		height;
	int 	width;
	int		pad;
}				t_fdf;


int				main(int ac, char **av);
int				error(char *str);
void			init_struct_global(t_fdf *global);
void			launch_map(t_fdf *global);
t_fdf			*launch_parse(int fd, t_fdf *global);
void			print_coords(t_fdf *global);
void			draw_segment(int *coord_src, int *coord_dst, t_fdf *global);

#endif
