/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:27:16 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/17 23:41:05 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 11) \
		|| !ft_strncmp(argv[1], "julia", 6) \
		|| !ft_strncmp(argv[1], "burning_ship", 13) \
		|| !ft_strncmp(argv[1], "celtic_mandelbrot", 18)))
		fractal_start(argc, argv);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6) \
		&& check_add_parametr(argv[2]) && check_add_parametr(argv[3]))
		fractal_start(argc, argv);
	else
	{
		put_help_message();
		put_perror("\033[31mError: incorrect arguments", ERR_NULL);
	}
	return (0);
}

int	fractal_start(int argc, char **argv)
{
	t_fractal	*fr;

	fr = init_fractal(argc, argv);
	if (!fr)
		put_perror("Error: malloc in init_fractal", ERR);
	setup_mlx(fr);
	put_use_message();
	fractal_loop(fr);
	mlx_loop(fr->mlx->mlx_ptr);
	return (0);
}

int	fractal_loop(t_fractal *fr)
{
	size_t	x;
	size_t	y;

	fr->scale.re = (fr->c_max.re - fr->c_min.re) / WIDTH_X;
	fr->scale.im = (fr->c_max.im - fr->c_min.im) / HEIGHT_Y;
	y = 0;
	while (y < HEIGHT_Y)
	{
		fr->c.im = fr->c_max.im - y * fr->scale.im;
		x = 0;
		while (x < WIDTH_X)
		{
			fr->c.re = fr->c_min.re + x * fr->scale.re;
			fr->fractal_func(fr);
			put_pixel(&fr->mlx->img, x, y, get_color(fr));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx->mlx_ptr, fr->mlx->win, \
							fr->mlx->img.img_ptr, 0, 0);
	return (0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	check_add_parametr(const char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		flag = 1;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		flag = 1;
		i++;
	}
	if (!str[i] && flag != 0)
		return (1);
	else
		return (0);
}
