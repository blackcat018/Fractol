/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:02:51 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/30 01:01:39 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	instructions(void)
{
	write(1, "Use following commands.\n", 24);
	write(1, "Mandelbrot\n", 11);
	write(1, "Julia\n", 6);
	write(1, "Julia can take 2 parametrs between -2.0 and 2.0\n", 48);
	write(1, "Burningship\n", 12);
	exit(0);
}


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | g << 16 | r << 8 | b);
}
