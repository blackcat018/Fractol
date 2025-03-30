/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:02:57 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/30 03:03:32 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	handle_key_action(mlx_key_data_t keydata, t_params *p, t_complex center)
{
	if (keydata.key == KEY_Z || keydata.key == KEY_X || keydata.key == KEY_C
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
	else if (keydata.key == KEY_C)
	{
		p->max_iter += 100;
		draw_julia(p);
	}
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
	{
		handle_key_action(keydata, p, center);
	}
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_params	*p;
	t_complex	center;

	p = (t_params *)param;
	int32_t mouse_x, mouse_y;
	(void)xdelta;
	mlx_get_mouse_pos(p->mlx, &mouse_x, &mouse_y);
	center.r = p->min_r + (p->max_r - p->min_r) * 0.7;
	center.i = p->min_i + (p->max_i - p->min_i) * 0.7;
	if (ydelta > 0)
		zoom_in(p, center.r, center.i);
	else if (ydelta < 0)
		zoom_out(p, center.r, center.i);
	choose_fractol(p);
}

int	zoom(int key, int x, int y, t_params *p)
{
	t_complex	center;

	printf("key = %d\n", key); // 5adem ft_purenl_fd
	center.r = p->min_r + (p->max_r - p->min_r) * x / (W_WIDTH - 1.0);
	center.i = p->min_i + (p->max_i - p->min_i) * y / (W_HEIGHT - 1.0);
	if (key == MOUSE_DOWN)
		zoom_out(p, center.r, center.i);
	if (key == MOUSE_UP)
		zoom_in(p, center.r, center.i);
	choose_fractol(p);
	return (0);
}
