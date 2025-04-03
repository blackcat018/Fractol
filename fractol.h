/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:03:25 by moel-idr          #+#    #+#             */
/*   Updated: 2025/04/03 00:11:29 by moel-idr         ###   ########.fr       */
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

# define KEY_ESCAPE MLX_KEY_ESCAPE
# define KEY_RIGHT MLX_KEY_RIGHT
# define KEY_LEFT MLX_KEY_LEFT
# define KEY_DOWN MLX_KEY_DOWN
# define KEY_UP MLX_KEY_UP
# define KEY_R MLX_KEY_R
# define KEY_G MLX_KEY_G
# define KEY_B MLX_KEY_B
# define KEY_W MLX_KEY_W
# define KEY_X MLX_KEY_X
# define KEY_C MLX_KEY_C
# define KEY_V MLX_KEY_V
# define KEY_PLUS MLX_KEY_EQUAL
# define KEY_MINUS MLX_KEY_MINUS

# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_params
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;

	t_complex	julia_c;

	int			r;
	int			g;
	int			b;

	int			color_mode;

	int			fractol_type;
	char		*name;

	int			max_iter;

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
void			zoom_in(t_params *p);
void			zoom_out(t_params *p);
void			key_arrows(int key, t_params *p);
int				get_key(int key, t_params *p);
void			scroll_handler(double xdelta, double ydelta, void *param);
void			key_handler(mlx_key_data_t keydata, void *param);

#endif