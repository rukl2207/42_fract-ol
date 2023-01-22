/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:28:37 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/17 21:25:25 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static int	calc_color(t_fractal *fr, size_t i)
{
	unsigned int	cs;
	unsigned int	rgb[3];
	double			t;

	cs = fr->color_shift;
	t = (double)i / fr->max_iter;
	if (fr->color_shift < 3)
	{
		rgb[cs % 3] = 9 * (1 - t) * pow(t, 3) * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * pow((1 - t), 3) * t * 255;
	}
	else
	{
		cs -= 3;
		rgb[cs % 3] = 9 * pow((1 - t), 3) * t * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * (1 - t) * pow(t, 3) * 255;
	}
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	set_color_array(t_fractal *fr)
{
	size_t	i;

	i = 0;
	while (i <= fr->max_iter)
	{
		fr->color_scheme[i] = calc_color(fr, i);
		i++;
	}
}

int	get_color(t_fractal *fr)
{
	return (fr->color_scheme[fr->iter]);
}
