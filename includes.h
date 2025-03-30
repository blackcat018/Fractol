/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:03:25 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/30 01:36:23 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "includes/MLX42/include/MLX42/MLX42.h"
# include "includes/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define W_WIDTH 1000
# define W_HEIGHT 1000

// KEYS
# define KEY_ESCAPE 256
# define KEY_RIGHT 262
# define KEY_LEFT 263
# define KEY_DOWN 264
# define KEY_UP 265
# define KEY_R 114
# define KEY_G 103
# define KEY_B 98
# define KEY_Z 122
# define KEY_X 120
# define KEY_C 99
# define KEY_V 118
# define KEY_PLUS 61
# define KEY_MINUS 45

// Mouse buttons
# define MOUSE_UP 4 // Scroll up
# define MOUSE_DOWN 5

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_params
{
	// MLX42 specific
	mlx_t		*mlx;
	mlx_image_t	*img;

	// Fractal parameters
	double min_r; // Replaced t_complex min
	double		max_r;
	double min_i; // Replaced t_complex max
	double		max_i;

	// Julia specific
	t_complex julia_c; // Changed from 'julia' to 'julia_c' for clarity

	// Color parameters
	int			r;
	int			g;
	int			b;

	int			color_mode;

	// Fractal type and other info
	int			fractol_type;
	char		*name;

	int			max_iter;

	// Additional parameters you might need
	int			cur_iter;
	int			scale;
}				t_params;

void			choose_fractol(t_params *p);
void			draw_mandelbrot(t_params *params);
void			draw_burningship(t_params *p);
void			param_init_m(t_params *params);
void			param_init_b(t_params *params);
int				mandelbrot_set(t_complex c, int max_iter);
void			param_init_j(t_params *params, char *av2, char *av3);
int				julia_set(t_complex z, t_complex c, int max_iter);
void			draw_julia(t_params *p);
void			julia_args_ch(int key, t_params *p);
void			handle_rgb(int key, t_params *p);
void			param_init_b(t_params *params);

double			parse_sign(const char *str, int *pos);
double			parse_integer(const char *str, int *pos);
double			parse_decimal(const char *str, int *pos, double *val);
double			ft_parce_it(const char *str);

void			instructions(void);
int				create_trgb(int t, int r, int g, int b);
int				zoom(int key, int x, int y, t_params *p);
void			zoom_in(t_params *p, double r, double i);
void			zoom_out(t_params *p, double r, double i);
void			key_arrows(int key, t_params *p);
int				get_key(int key, t_params *p);
void			scroll_handler(double xdelta, double ydelta, void *param);
void			key_handler(mlx_key_data_t keydata, void *param);
// void				open_win(t_params *params, char *av);

#endif