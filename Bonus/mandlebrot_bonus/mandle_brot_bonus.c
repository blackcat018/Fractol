/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle_brot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:03:02 by moel-idr          #+#    #+#             */
/*   Updated: 2025/04/02 22:08:01 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	param_init_m(t_params *params)
{
	params->min_r = -2.0;
	params->max_r = 1.0;
	params->min_i = -1.5;
	params->max_i = 1.5;
	params->r = 0;
	params->g = 0;
	params->max_iter = 100;
	params->b = 0;
	params->fractol_type = 1;
	params->img = NULL;
}

int	mandelbrot_set(t_complex c, int max_iter)
{
	int			i;
	t_complex	z;
	double		zr;
	double		zi;

	z.r = 0;
	z.i = 0;
	i = 0;
	while (i < max_iter)
	{
		zr = z.r;
		zi = z.i;
		z.r = zr * zr - zi * zi + c.r;
		z.i = 2 * zr * zi + c.i;
		if (z.r * z.r + z.i * z.i > 4)
			break ;
		i++;
	}
	return (i);
}

uint32_t	get_mandelbrot_color(int iter, int max_iter, t_params *p)
{
	double	t;
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	red = (uint8_t)(9 * (1 - t) * t * t * t * 255) + p->r;
	green = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255) + p->g;
	blue = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255) + p->b;
	return (create_trgb(255, red, green, blue));
}

void	draw_mandelbrot(t_params *p)
{
	t_complex	c;
	uint32_t	color;

	int (x), (y), (iter);
	if (p->img)
		(mlx_delete_image(p->mlx, p->img), (p->img = NULL));
	if (!p->img)
		p->img = mlx_new_image(p->mlx, W_WIDTH, W_HEIGHT);
	if (!p->img)
		return ;
	mlx_image_to_window(p->mlx, p->img, 0, 0);
	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x++ < W_WIDTH)
		{
			c.r = p->min_r + (p->max_r - p->min_r) * x / (W_WIDTH - 1.0);
			c.i = p->max_i - (p->max_i - p->min_i) * y / (W_HEIGHT - 1.0);
			iter = mandelbrot_set(c, p->max_iter);
			color = get_mandelbrot_color(iter, p->max_iter, p);
			mlx_put_pixel(p->img, x, y, color);
		}
		y++;
	}
}
