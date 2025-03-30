/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:02:46 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/30 03:04:46 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	param_init_b(t_params *params)
{
	params->min_r = -2.0;
	params->max_r = 1.0;
	params->min_i = -1.5;
	params->max_i = 1.5;
	params->r = 2;
	params->g = 2;
	params->max_iter = 500;
	params->b = 2;
	params->fractol_type = 3;
	params->img = NULL;
}

int	burningship_set(t_complex c, int max_iter)
{
	int			i;
	t_complex	z;
	double		zr;
	double		zi;

	z.r = 0;
	z.i = 0;
	i = 0;
	c.r = c.r;
	c.i = c.i;
	while (i < max_iter)
	{
		zr = fabs(z.r);
		zi = fabs(z.i);
		z.r = zr * zr - zi * zi + c.r;
		z.i = 2 * zr * zi + c.i;
		if (z.r * z.r + z.i * z.i > 4)
			break ;
		i++;
	}
	return (i);
}

uint32_t	get_burningship_color(int iter, int max_iter)
{
	double	t;

	uint8_t red, green, blue;
	if (iter == max_iter)
		return (0x000000FF);
	else
	{
		t = (double)iter / max_iter;
		red = (uint8_t)(5 * pow(1 - t, 9) * (1 - t) * 15);
		green = (uint8_t)(5 * (t) * pow(1 - t, 2) * 255);
		blue = (uint8_t)(5 * pow(1 - t, 2) * (t) * 255);
		return (create_trgb(255, red, green, blue));
	}
}

void	draw_burningship(t_params *p)
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
		while (x < W_WIDTH)
		{
			c.r = p->min_r + (p->max_r - p->min_r) * x / (W_WIDTH - 1.0);
			c.i = p->min_i + (p->max_i - p->min_i) * y / (W_HEIGHT - 1.0);
			iter = burningship_set(c, p->max_iter);
			color = get_burningship_color(iter, p->max_iter);
			mlx_put_pixel(p->img, x, y, color);
			x++;
		}
		y++;
	}
}
