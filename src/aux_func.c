/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:05:40 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/10 16:05:43 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		init_pos(t_fdf *global)
{
	int y;
	int x;
	int y_max;
	int x_max;

	y_max = global->pad * (global->height - 1);
	x_max = global->pad * (global->width - 1);
	y = 0;
	while (y_max++ <= HEIGHT)
		y++;
	x = 0;
	while (x_max++ <= WIDTH)
		x++;
	global->coords.pos[0] = y / 2;
	global->coords.pos[1] = x / 2;
}

void		bonus(t_fdf *global)
{
	global->bonus.p_img_bonus = mlx_new_image(global->img.p_mlx, WIDTH, \
																HEIGHT_BONUS);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img,
					&global->img.bpp, &global->img.size, &global->img.endian);
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 1000, 0xFFFFFF, "QUITTER ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 180, 1000, 0xFFFFFF, ": ECHAP");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 1050, 0xFFFFFF, "REINITIALISER MAP : 0");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 1100, 0xFFFFFF, "ZOOM ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 180, 1100, 0xFFFFFF, ": PAGE UP/DOWN");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 1150, 0xFFFFFF, "DEPLACER MAP ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 180, 1150, 0xFFFFFF, ": FLECHES DIRECTIONNELLES");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 550, 1000, 0xFFFFFF, "ROTATION MAP	");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 760, 1000, 0xFFFFFF, ": </>");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 550, 1050, 0xFFFFFF, "CHANGER AXE ROTATION : CONTROL");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 550, 1100, 0xFFFFFF, "MODIFIER PROFONDEUR  : +/-");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 550, 1150, 0xFFFFFF, "CHANGER COULEUR ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 760, 1150, 0xFFFFFF, ": 1/3/4/6/7/9");
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
										global->bonus.p_img_bonus, HEIGHT, 0);
}
