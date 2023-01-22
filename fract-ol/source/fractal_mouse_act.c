/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mouse_act.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:12:53 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/17 00:51:22 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	mouse_hook_zoom(int button, int x, int y, t_fractal *fr)
{
	t_complex	pos;
	double		zoom;

	if (button == MOUSE_UP || button == MOUSE_DOWN)
	{
		if (button == MOUSE_UP)
			zoom = 1.1;
		else
			zoom = 0.9;
		change_maxiter(button, fr);
		pos.re = fr->c_min.re + x * fr->scale.re;
		pos.im = fr->c_max.im - y * fr->scale.im;
		fr->c_min.re = pos.re + (fr->c_min.re - pos.re) * zoom;
		fr->c_max.re = pos.re + (fr->c_max.re - pos.re) * zoom;
		fr->c_min.im = pos.im + (fr->c_min.im - pos.im) * zoom;
		fr->c_max.im = pos.im + (fr->c_max.im - pos.im) * zoom;
		fractal_loop(fr);
	}
	return (0);
}

int	mouse_hook_motion(int x, int y, t_fractal *fr)
{
	if (!fr->is_fixed && fr->fractal_func == julia)
	{
		fr->c_julia.re = 4 * ((double)x / WIDTH_X - 0.5);
		fr->c_julia.im = 4 * ((double)(HEIGHT_Y - y) / HEIGHT_Y - 0.5);
		fractal_loop(fr);
	}
	return (0);
}
