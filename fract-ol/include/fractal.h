/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:21:47 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/18 22:43:11 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# include "../libft/libft.h"

# define WIDTH_X		600
# define HEIGHT_Y		600
# define LIM_I			50000
# define ERR			1
# define ERR_NULL		0

# define MOUSE_LEFT		1
# define MOUSE_RIGHT	2
# define MOUSE_MIDDLE	3
# define MOUSE_UP		4
# define MOUSE_DOWN		5

# define KEY_ESC		53
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_SPACE		49
# define KEY_MINUS		27
# define KEY_PLUS		24
# define KEY_R			15
# define KEY_C			8
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21

typedef struct s_complex	t_complex;
typedef struct s_img		t_img;
typedef struct s_mlx		t_mlx;
typedef struct s_fractal	t_fractal;
typedef void				(*t_func_ptr)(t_fractal *fr);

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_fractal
{
	t_mlx			*mlx;
	t_complex		c;
	t_complex		c_julia;
	t_complex		c_max;
	t_complex		c_min;
	t_complex		scale;
	size_t			iter;
	size_t			max_iter;
	t_func_ptr		fractal_func;
	uint8_t			color_shift;
	int				*color_scheme;
	int				is_fixed;
}	t_fractal;

// fractal_main.c
int			fractal_start(int argc, char **argv);
int			fractal_loop(t_fractal *fr);
void		put_pixel(t_img *img, int x, int y, int color);
int			check_add_parametr(const char *str);

// fractal_messages.c
void		put_perror(const char *message, int err_code);
void		put_help_message(void);
void		put_use_message(void);

// fractal_init.c
t_fractal	*init_fractal(int argc, char **argv);
void		set_defaults(t_fractal *fr);
void		set_input(int argc, char **argv, t_fractal *fr);
void		setup_mlx(t_fractal *fr);
int			free_fractal(t_fractal *fr);

// fractal_sets.c
void		mandelbrot(t_fractal *fr);
void		julia(t_fractal *fr);
void		burning_ship(t_fractal *fr);
void		celtic_mandelbrot(t_fractal *fr);

// fractal_key_act.c
int			key_hook(int key, t_fractal *fr);
void		move(int key, t_fractal *fr);
void		change_maxiter(int key, t_fractal *fr);
void		change_fractal(int key, t_fractal *fr);
void		color_shift(t_fractal *fr);

//fractal_mouse_act.c
int			mouse_hook_zoom(int button, int x, int y, t_fractal *fr);
int			mouse_hook_motion(int x, int y, t_fractal *fr);

//fractal_color.c
void		set_color_array(t_fractal *fr);
int			get_color(t_fractal *fr);

#endif
