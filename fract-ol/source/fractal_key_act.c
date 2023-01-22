/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_key_act.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:35:38 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/17 00:05:46 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	key_hook(int key, t_fractal *fr)
{
	if (key == KEY_ESC)
		free_fractal(fr);
	else if (key == KEY_R)
		set_defaults(fr);
	else if (key == KEY_LEFT || key == KEY_RIGHT \
			|| key == KEY_UP || key == KEY_DOWN)
		move(key, fr);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		change_maxiter(key, fr);
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
		change_fractal(key, fr);
	else if (key == KEY_SPACE)
	{
		if (fr->is_fixed)
			fr->is_fixed = 0;
		else
			fr->is_fixed = 1;
	}
	else if (key == KEY_C)
		color_shift(fr);
	fractal_loop(fr);
	return (0);
}

void	move(int key, t_fractal *fr)
{
	t_complex	c_size;

	c_size.re = fr->c_max.re - fr->c_min.re;
	c_size.im = fr->c_max.im - fr->c_min.im;
	if (key == KEY_UP)
	{
		fr->c_min.im += c_size.im * 0.05;
		fr->c_max.im += c_size.im * 0.05;
	}
	else if (key == KEY_DOWN)
	{
		fr->c_min.im -= c_size.im * 0.05;
		fr->c_max.im -= c_size.im * 0.05;
	}
	else if (key == KEY_LEFT)
	{
		fr->c_min.re -= c_size.re * 0.05;
		fr->c_max.re -= c_size.re * 0.05;
	}
	else if (key == KEY_RIGHT)
	{
		fr->c_min.re += c_size.re * 0.05;
		fr->c_max.re += c_size.re * 0.05;
	}
}

void	change_maxiter(int key, t_fractal *fr)
{
	if (key == KEY_PLUS || key == MOUSE_DOWN)
	{
		if (fr->max_iter < 50)
			fr->max_iter += 1;
		else if (fr->max_iter < LIM_I)
		{
			fr->max_iter = (int)(fr->max_iter * 1.02);
			if (fr->max_iter >= LIM_I)
				fr->max_iter = LIM_I;
		}
		else if (fr->max_iter >= LIM_I)
			fr->max_iter = LIM_I;
	}
	else if (key == KEY_MINUS || key == MOUSE_UP)
	{
		if (fr->max_iter > 50)
			fr->max_iter = (int)(fr->max_iter * 0.98);
		else if (fr->max_iter > 1)
			fr->max_iter -= 1;
	}
	set_color_array(fr);
}

void	change_fractal(int key, t_fractal *fr)
{
	if (key == KEY_1)
		fr->fractal_func = mandelbrot;
	else if (key == KEY_2)
		fr->fractal_func = julia;
	else if (key == KEY_3)
		fr->fractal_func = burning_ship;
	else if (key == KEY_4)
		fr->fractal_func = celtic_mandelbrot;
	set_defaults(fr);
}

void	color_shift(t_fractal *fr)
{
	fr->color_shift = (fr->color_shift + 1) % 6;
	set_color_array(fr);
}
