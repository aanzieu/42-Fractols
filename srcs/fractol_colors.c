/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:46:49 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 10:18:06 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		init_color(int r, int g, int b, t_env *e)
{
	e->color.r = r;
	e->color.g = g;
	e->color.b = b;
	e->color.light = 0.5;
	e->color.sat = 1.0;
	e->color.psyche = 0;
}

int			get_c(int i, t_env *e, double m, double h)
{
	double x;
	double c;

	if (e->color.psyche == 1)
	{
		return (RGB(127.5 * (cos((double)i) + 1), 127.5 * (sin((double)i) + 1),
					127.5 * (1 - cos((double)i))));
	}
	c = (1 - fabs((2 * e->color.light) - 1)) * e->color.sat;
	m = e->color.light - (c * 0.5);
	h = 360 * ((double)i) / e->plan.i_max;
	x = (1 - fabs(fmod(h / 60, 2)) - 1);
	if (h >= 0 && h < 60)
		return (HSL((c + m) * 255, (x + m) * 255, 0));
	if (h >= 60 && h < 120)
		return (HSL((x + m) * 255, (c + m) * 255, 0));
	if (h >= 120 && h < 180)
		return (HSL(0, (c + m) * 255, (x + m) * 255));
	if (h >= 180 && h < 240)
		return (HSL(0, 255 * (x + m), (c + m) * 255));
	if (h >= 240 && h < 300)
		return (HSL(255 * (x + m), 0, (c + m) * 255));
	if (h >= 300 && h < 360)
		return (HSL(255 * (c + m), 0, 255 * (x + m)));
	return (RGB(0, 0, 0));
}
