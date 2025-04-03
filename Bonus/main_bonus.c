/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:02:53 by moel-idr          #+#    #+#             */
/*   Updated: 2025/04/03 00:43:58 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	open_win(t_params *params)
{
	params->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Fract'ol", false);
	if (!params->mlx)
		exit(EXIT_FAILURE);
	params->img = mlx_new_image(params->mlx, W_WIDTH, W_HEIGHT);
	if (!params->img)
	{
		mlx_terminate(params->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(params->mlx, params->img, 0, 0) < 0)
	{
		mlx_delete_image(params->mlx, params->img);
		mlx_terminate(params->mlx);
		exit(EXIT_FAILURE);
	}
}

void	choose_fractol(t_params *p)
{
	if (p->fractol_type == 1)
		draw_mandelbrot(p);
	else if (p->fractol_type == 2)
		draw_julia(p);
	else if (p->fractol_type == 3)
		draw_burningship(p);
	mlx_image_to_window(p->mlx, p->img, 0, 0);
}

void	close_win(void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (params->img)
		mlx_delete_image(params->mlx, params->img);
	if (params->mlx)
		mlx_terminate(params->mlx);
	exit(EXIT_SUCCESS);
}

void	validation(char **av)
{
	t_params	params;

	if (ft_strncmp("Mandelbrot", av[1], 10) == 0 && !av[2])
		param_init_m(&params);
	else if (ft_strncmp("julia", av[1], 5) == 0 && av[2] && av[3])
		param_init_j(&params, av[2], av[3]);
	else if (ft_strncmp("Burningship", av[1], 11) == 0 && !av[2])
		param_init_b(&params);
	else
	{
		instructions();
		return ;
	}
	open_win(&params);
	choose_fractol(&params);
	mlx_key_hook(params.mlx, &key_handler, &params);
	mlx_scroll_hook(params.mlx, &scroll_handler, &params);
	mlx_close_hook(params.mlx, &close_win, &params);
	mlx_loop(params.mlx);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 4)
		instructions();
	else
		validation(argv);
	return (0);
}
