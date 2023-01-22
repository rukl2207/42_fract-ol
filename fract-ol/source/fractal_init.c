/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:46:48 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/17 23:45:47 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

t_fractal	*init_fractal(int argc, char **argv)
{
	t_fractal	*fr;

	fr = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fr)
		return (NULL);
	fr->color_scheme = malloc(sizeof(int) * (LIM_I + 1));
	if (!fr->color_scheme)
		free_fractal(fr);
	fr->mlx = NULL;
	fr->color_shift = 0;
	set_defaults(fr);
	set_input(argc, argv, fr);
	return (fr);
}

void	set_defaults(t_fractal *fr)
{
	fr->max_iter = 50;
	fr->is_fixed = 1;
	fr->c_min.re = -2;
	fr->c_min.im = -2;
	fr->c_max.re = 2;
	fr->c_max.im = 2;
	fr->c_julia.re = 0.36;
	fr->c_julia.im = 0.36;
	set_color_array(fr);
}

void	set_input(int argc, char **argv, t_fractal *fr)
{
	fr->fractal_func = NULL;
	if ((argc == 2 || argc == 4) && !ft_strncmp(argv[1], "julia", 6))
	{
		fr->fractal_func = julia;
		if (argc == 4)
		{
				fr->c_julia.re = ft_atod(argv[2]);
				fr->c_julia.im = ft_atod(argv[3]);
		}
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		fr->fractal_func = mandelbrot;
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 13))
		fr->fractal_func = burning_ship;
	else if (argc == 2 && !ft_strncmp(argv[1], "celtic_mandelbrot", 18))
		fr->fractal_func = celtic_mandelbrot;
	else
		put_help_message();
	if (fr->fractal_func == NULL)
		free_fractal(fr);
}

void	setup_mlx(t_fractal *fr)
{
	t_mlx	*mlx;

	fr->mlx = malloc(sizeof(t_mlx));
	if (fr->mlx == NULL)
		free_fractal(fr);
	mlx = fr->mlx;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		free_fractal(fr);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH_X, HEIGHT_Y, "fractol");
	if (mlx->win == NULL)
		free_fractal(fr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH_X, HEIGHT_Y);
	if (mlx->img.img_ptr == NULL)
		free_fractal(fr);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, \
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	if (mlx->img.addr == NULL)
		free_fractal(fr);
	mlx_hook(mlx->win, 2, 0, key_hook, fr);
	mlx_hook(mlx->win, 4, 0, mouse_hook_zoom, fr);
	mlx_hook(mlx->win, 17, 0, free_fractal, fr);
	mlx_hook(mlx->win, 6, 0, mouse_hook_motion, fr);
}

int	free_fractal(t_fractal *fr)
{
	if (fr->mlx != NULL)
	{
		mlx_destroy_window(fr->mlx->mlx_ptr, fr->mlx->win);
		mlx_destroy_image(fr->mlx->mlx_ptr, fr->mlx->img.img_ptr);
		free(fr->mlx);
	}
	free(fr->color_scheme);
	free(fr);
	exit(EXIT_SUCCESS);
}
