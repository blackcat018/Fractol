/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:02:57 by moel-idr          #+#    #+#             */
/*   Updated: 2025/04/03 00:24:04 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	handle_escape(mlx_key_data_t keydata, t_params *p)
{
	if (keydata.key == KEY_ESCAPE)
		mlx_close_window(p->mlx);
	choose_fractol(p);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_params	*p;

	p = (t_params *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		handle_escape(keydata, p);
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
		zoom_in(param);
	else if (ydelta < 0)
		zoom_out(p);
	choose_fractol(p);
}
