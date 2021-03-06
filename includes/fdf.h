/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:59:34 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 18:11:47 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"
# include <math.h>

# define HEIGHT		1000
# define WIDTH		1000
# define HEIGHT_UI	200

typedef	struct	s_img
{
	void	*p_mlx;
	void	*p_win;
	void	*p_img;
	char	*img_addr;
	int		bpp;
	int		size;
	int		endian;
}				t_img;

typedef	struct	s_point
{
	int		**points;
	int		pos[2];
	int		move[2];
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		color;
}				t_point;

typedef struct	s_tmp
{
	float	pad;
	float	pad_z;
	int		x;
	int		y;
	int		diff_y;
	int		diff_x;
}				t_tmp;

typedef struct	s_bonus
{
	void	*p_img_bonus;
}				t_bon;

typedef struct	s_fdf
{
	t_point coords;
	t_img	img;
	t_tmp	tmp;
	t_bon	bonus;
	int		(*function[8]) (struct s_fdf*, int);
	int		len_array;
	char	*name;
	int		height;
	int		width;
	float	pad;
	float	pad_z;
}				t_fdf;

int				main(int ac, char **av);
int				close_map(t_fdf *global, int key);
int				deal_key(int key, t_fdf *global);
int				display_color(t_fdf *global, int key);
void			draw_segment(float *coord_src, float *coord_dst, t_fdf *global);
int				error(char *str);
void			free_array(char **array, int len_array);
void			free_coord(t_fdf *global);
int				increase_decrease_z(t_fdf *global, int key);
int				init_map(t_fdf *global, int key);
void			init_pos(t_fdf *global);
void			init_struct_global(t_fdf *global);
void			launch_map(t_fdf *global);
t_fdf			*launch_parse(int fd, t_fdf *global, char **av);
void			left_ui(t_fdf *global);
int				move_up_and_down(t_fdf *global, int key);
int				move_right_and_left(t_fdf *global, int key);
void			rotation(t_fdf *global, float *coord, float *point_rot);
int				rotation_z(t_fdf *global, int key);
int				zoom(t_fdf *global, int key);

#endif
