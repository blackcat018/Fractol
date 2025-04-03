/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:02:57 by moel-idr          #+#    #+#             */
/*   Updated: 2025/04/03 00:44:27 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	handle_key_action(mlx_key_data_t keydata, t_params *p, t_complex center)
{
	if (keydata.key == KEY_W || keydata.key == KEY_X || keydata.key == KEY_C
		|| keydata.key == KEY_V)
		julia_args_ch(keydata.key, p);
	else if (keydata.key == KEY_R || keydata.key == KEY_G
		|| keydata.key == KEY_B)
		handle_rgb(keydata.key, p);
	else if (keydata.key == KEY_PLUS)
		zoom_in(p, center.r, center.i);
	else if (keydata.key == KEY_MINUS)
		zoom_out(p, center.r, center.i);
	else if (keydata.key == KEY_RIGHT || keydata.key == KEY_LEFT
		|| keydata.key == KEY_DOWN || keydata.key == KEY_UP)
		key_arrows(keydata.key, p);
	else if (keydata.key == KEY_ESCAPE)
		mlx_close_window(p->mlx);
	choose_fractol(p);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_params	*p;
	t_complex	center;

	p = (t_params *)param;
	center.r = p->min_r + (p->max_r - p->min_r) * 0.5;
	center.i = p->min_i + (p->max_i - p->min_i) * 0.5;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		handle_key_action(keydata, p, center);
}

void	zoom(t_params *p, double zoom_factor, double mouse_r, double mouse_i)
{
	double	new_width;
	double	new_height;
	double	center_r;
	double	center_i;

	center_r = (p->max_r + p->min_r) / 2.0;
	center_i = (p->max_i + p->min_i) / 2.0;
	new_width = (p->max_r - p->min_r) / zoom_factor;
	new_height = (p->max_i - p->min_i) / zoom_factor;
	p->min_r = mouse_r - (mouse_r - p->min_r) / zoom_factor;
	p->max_r = mouse_r + (p->max_r - mouse_r) / zoom_factor;
	p->min_i = mouse_i - (mouse_i - p->min_i) / zoom_factor;
	p->max_i = mouse_i + (p->max_i - mouse_i) / zoom_factor;
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_params	*p;
	t_complex	mouse_pos;
	int32_t		mouse_x;
	int32_t		mouse_y;

	p = (t_params *)param;
	(void)xdelta;
	mlx_get_mouse_pos(p->mlx, &mouse_x, &mouse_y);
	mouse_pos.r = p->min_r + (p->max_r - p->min_r) * mouse_x / (W_WIDTH - 1.0);
	mouse_pos.i = p->max_i - (p->max_i - p->min_i) * mouse_y / (W_HEIGHT - 1.0);
	if (ydelta > 0)
		zoom(p, 1.1, mouse_pos.r, mouse_pos.i);
	else if (ydelta < 0)
		zoom(p, 1.0 / 1.25, mouse_pos.r, mouse_pos.i);
	choose_fractol(p);
}
