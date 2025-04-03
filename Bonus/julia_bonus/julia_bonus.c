/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:12:28 by moel-idr          #+#    #+#             */
/*   Updated: 2025/04/02 23:19:30 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	param_init_j(t_params *params, char *av2, char *av3)
{
	params->julia_c.r = ft_parce_it(av2);
	params->julia_c.i = ft_parce_it(av3);
	params->min_r = -2.0;
	params->max_r = 2.0;
	params->min_i = -2.0;
	params->max_i = 2.0;
	params->max_iter = 100;
	params->r = 0;
	params->g = 0;
	params->b = 0;
	params->color_mode = 0;
	params->fractol_type = 2;
	params->img = NULL;
	if (!(params->julia_c.r >= -2.0 && params->julia_c.r <= 2.0)
		|| !(params->julia_c.i >= -2.0 && params->julia_c.i <= 2.0))
	{
		instructions();
		exit(EXIT_FAILURE);
	}
}

uint32_t	get_julia_color(int iter, int max_iter, t_params *p)
{
	double	t;
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	red = (uint8_t)(5 * (t) * pow(1 - t, 1) * 255) + p->r;
	green = (uint8_t)(5 * pow(1 - t, 3) * pow(t, 2) * 255) + p->g;
	blue = (uint8_t)(10 * pow(1 - t, 2) * (t) * 255) + p->b;
	return (create_trgb(255, red, green, blue));
}

int	julia_set(t_complex z, t_complex c, int max_iter)
{
	int		i;
	double	zr;
	double	zi;

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

void	draw_julia(t_params *p)
{
	t_complex	z;
	uint32_t	color;

	int (y), (x), (iter);
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
			z.r = p->min_r + (p->max_r - p->min_r) * x / (W_WIDTH - 1.0);
			z.i = p->max_i - (p->max_i - p->min_i) * y / (W_HEIGHT - 1.0);
			iter = julia_set(z, p->julia_c, p->max_iter);
			color = get_julia_color(iter, p->max_iter, p);
			mlx_put_pixel(p->img, x, y, color);
		}
		y++;
	}
}
