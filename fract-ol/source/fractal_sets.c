/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:12:45 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/17 21:28:57 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	mandelbrot(t_fractal *fr)
{	
	t_complex	z;
	t_complex	pow_z;

	z.re = fr->c.re;
	z.im = fr->c.im;
	pow_z.re = z.re * z.re;
	pow_z.im = z.im * z.im;
	fr->iter = 0;
	while ((pow_z.re + pow_z.im <= 4) && fr->iter < fr->max_iter)
	{
		z.im = 2 * z.re * z.im + fr->c.im;
		z.re = pow_z.re - pow_z.im + fr->c.re;
		pow_z.re = z.re * z.re;
		pow_z.im = z.im * z.im;
		fr->iter++;
	}
}

void	julia(t_fractal *fr)
{
	t_complex	z;
	t_complex	pow_z;

	z.re = fr->c.re;
	z.im = fr->c.im;
	pow_z.re = z.re * z.re;
	pow_z.im = z.im * z.im;
	fr->iter = 0;
	while ((pow_z.re + pow_z.im <= 4) && fr->iter < fr->max_iter)
	{
		z.im = 2 * z.re * z.im + fr->c_julia.im;
		z.re = pow_z.re - pow_z.im + fr->c_julia.re;
		pow_z.re = z.re * z.re;
		pow_z.im = z.im * z.im;
		fr->iter++;
	}
}

void	burning_ship(t_fractal *fr)
{
	t_complex	z;
	t_complex	pow_z;

	z.re = fr->c.re;
	z.im = fr->c.im;
	pow_z.re = z.re * z.re;
	pow_z.im = z.im * z.im;
	fr->iter = 0;
	while ((pow_z.re + pow_z.im <= 4) && fr->iter < fr->max_iter)
	{
		z.im = -2 * fabs(z.re * z.im) + fr->c.im;
		z.re = pow_z.re - pow_z.im + fr->c.re;
		pow_z.re = z.re * z.re;
		pow_z.im = z.im * z.im;
		fr->iter++;
	}
}

void	celtic_mandelbrot(t_fractal *fr)
{
	t_complex	z;
	t_complex	pow_z;

	z.re = fr->c.re;
	z.im = fr->c.im;
	pow_z.re = z.re * z.re;
	pow_z.im = z.im * z.im;
	fr->iter = 0;
	while ((pow_z.re + pow_z.im <= 4) && fr->iter < fr->max_iter)
	{
		z.im = 2 * z.re * z.im + fr->c.im;
		z.re = fabs(pow_z.re - pow_z.im) + fr->c.re;
		pow_z.re = z.re * z.re;
		pow_z.im = z.im * z.im;
		fr->iter++;
	}
}
