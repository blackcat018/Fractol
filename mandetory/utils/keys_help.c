/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:03:00 by moel-idr          #+#    #+#             */
/*   Updated: 2025/04/03 00:29:52 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	zoom_out(t_params *p)
{
	double		width;
	double		height;
	t_complex	center;

	center.r = p->min_r + (p->max_r - p->min_r) * 0.5;
	center.i = p->min_i + (p->max_i - p->min_i) * 0.5;
	width = p->max_r - p->min_r;
	height = p->max_i - p->min_i;
	width *= 1.5;
	height *= 1.5;
	p->min_r = center.r - width / 2;
	p->max_r = center.r + width / 2;
	p->min_i = center.i - height / 2;
	p->max_i = center.i + height / 2;
}

void	zoom_in(t_params *p)
{
	double		width;
	double		height;
	t_complex	center;

	center.r = p->min_r + (p->max_r - p->min_r) * 0.5;
	center.i = p->min_i + (p->max_i - p->min_i) * 0.5;
	width = p->max_r - p->min_r;
	height = p->max_i - p->min_i;
	width /= 1.5;
	height /= 1.5;
	p->min_r = center.r - width / 2;
	p->max_r = center.r + width / 2;
	p->min_i = center.i - height / 2;
	p->max_i = center.i + height / 2;
}
