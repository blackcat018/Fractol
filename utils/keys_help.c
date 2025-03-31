/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:03:00 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/30 00:03:01 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void key_arrows(int key, t_params *p)
{
    double x;
    double y;

    x = p->max_r - p->min_r;
    y = p->max_i - p->min_i;
    if (key == KEY_RIGHT)
    {
        p->min_r += x * 0.1;
        p->max_r += x * 0.1;
    }
    else if (key == KEY_LEFT)
    {
        p->min_r -= x * 0.1;
        p->max_r -= x * 0.1;
    }
    else if (key == KEY_DOWN)
    {
        p->min_i -= y * 0.1;  // Changed from += to -=
        p->max_i -= y * 0.1;  // Because screen Y increases downwards
    }
    else if (key == KEY_UP)
    {
        p->min_i += y * 0.1;  // Changed from -= to +=
        p->max_i += y * 0.1;  // Because screen Y increases downwards
    }
}

void	zoom_out(t_params *p, double r, double i)
{
	double	width;
	double	height;

	width = p->max_r - p->min_r;
	height = p->max_i - p->min_i;
	width *= 1.5;
	height *= 1.5;
	p->min_r = r - width / 2.0;
	p->min_i = i - height / 2.0;
	p->max_r = r + width / 2.0;
	p->max_i = i + height / 2.0;
}

void	zoom_in(t_params *p, double r, double i)
{
	double	width;
	double	height;

	width = p->max_r - p->min_r;
	height = p->max_i - p->min_i;
	width /= 1.5;
	height /= 1.5;
	p->min_r = r - width / 2.0;
	p->min_i = i - height / 2.0;
	p->max_r = r + width / 2.0;
	p->max_i = i + height / 2.0;
}

void	julia_args_ch(int key, t_params *p)
{
	if (key == KEY_Z)
		p->julia_c.r += 0.01;
	if (key == KEY_X)
		p->julia_c.r -= 0.01;
	if (key == KEY_C)
		p->julia_c.i += 0.01;
	if (key == KEY_V)
		p->julia_c.i -= 0.01;
}

void	handle_rgb(int key, t_params *p)
{
    if (key == KEY_R)
        p->r = (p->r + 10) % 256;
    else if (key == KEY_G)
        p->g = (p->g + 10) % 256;
    else if (key == KEY_B)
        p->b = (p->b + 10) % 256;
}
