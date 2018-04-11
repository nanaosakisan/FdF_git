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

static void	right_ui(t_fdf *global)
{
	mlx_string_put(global->img.p_mlx, global->img.p_win, 550, 1010, 0xFFFFFF, \
															"ROTATION MAP	");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 760, 1010, 0xFFFFFF, \
																	": </>");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 550, 1040, 0xFFFFFF, \
											"CHANGER AXE ROTATION : CONTROL");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 550, 1070, 0xFFFFFF, \
												"MODIFIER PROFONDEUR  : +/-");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 550, 1100, 0xFFFFFF, \
															"CHANGER COULEUR ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 760, 1100, 0xFFFFFF, \
																	": CYAN ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 859, 1100, 0xFFFFFF, \
																	": 7/9");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 760, 1130, 0xFFFFFF, \
															": MAGENTA : 4/6");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 760, 1160, 0xFFFFFF, \
																": YELLOW ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 1160, 0xFFFFFF, \
																	": 1/3");
}

void		left_ui(t_fdf *global)
{
	global->bonus.p_img_bonus = mlx_new_image(global->img.p_mlx, WIDTH, \
																HEIGHT_UI);
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 1010, 0xFFFFFF, \
																	"QUITTER ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 190, 1010, 0xFFFFFF, \
																	": ECHAP");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 1040, 0xFFFFFF, \
													"REINITIALISER MAP : 0");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 1070, 0xFFFFFF, \
																	"ZOOM ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 190, 1070, 0xFFFFFF, \
															": PAGE UP/DOWN");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 1100, 0xFFFFFF, \
															"DEPLACER MAP ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 190, 1100, 0xFFFFFF, \
												": FLECHES DIRECTIONNELLES");
	right_ui(global);
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
										global->bonus.p_img_bonus, HEIGHT, 0);
}
