/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:02:51 by moel-idr          #+#    #+#             */
/*   Updated: 2025/04/03 00:24:08 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	instructions(void)
{
	ft_putendl_fd("Your input is incorrect! try the following", 1);
	ft_putendl_fd("Mandelbrot", 1);
	ft_putendl_fd("Julia with 2 numbers ranging from -2 to 2, for exampl:", 1);
	ft_putendl_fd("./fractol julia 0 0.8", 1);
	exit(0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | g << 16 | r << 8 | b);
}
