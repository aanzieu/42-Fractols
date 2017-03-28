/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:46:49 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/28 17:06:58 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_color			*init_color(int r, int g, int b)

{
	t_color *color;
	
	if (!(color = (t_color *)ft_memalloc(sizeof(color))))
		return (NULL);
	color->r = r;
	color->g = g;
	color->b = b;
	color->light = 0.5;
	color->sat = 1.0;
	return (color);
}

int		get_c(int i, t_env *e)
{
	double h;
	double X;
	double m;
	double C;

	if(e->color->psyche == 1)
		return (RGB(127.5 * (cos((double)i) + 1), 127.5 * (sin((double)i) + 1), 127.5 * (1 - cos((double)i))));
	C = (1 - fabs((2 * e->color->light) - 1)) * e->color->sat;
	m = e->color->light - (C * 0.5);
	h = 360 * ((double)i) / e->plan.i_max;
	X = (1 - fabs(fmod(h / 60, 2)) - 1);
	if (h >= 0 && h < 60)
		return (HSL((C + m) * 255, (X + m) * 255, 0));
	if (h >= 60 && h < 120)
		return (HSL((X + m) * 255,(C + m) * 255, 0));
	if (h >= 120 && h < 180)
		return (HSL(0, (C + m) * 255, (X + m) * 255));
	if (h >= 180 && h < 240)
		return (HSL(0, 255 * (X + m), (C + m) * 255));
	if (h >= 240 && h < 300)
		return (HSL(255 * (X + m), 0,(C + m) * 255));
	if (h >= 300 && h < 360)
		return (HSL(255 * (C + m), 0, 255 * (X + m)));

	return (RGB(0, 0, 0));
}



//	(255 * 255 * rp) + (255 *  gp) +  bp );
//	ret = ((256 - i * (int)rp) << 16) + ((256 - i * (int)gp) << 8) + (256 - i * bp);
//	ret = (((rp + m) * 255) + ((gp + m) * 255) + ((bp + m * 255)));
//
//	if (i == e->plan.i_max)
//		return(0xFFFFFF);
//	return (RGB(127.5 * (cos((double)i) + 1), 127.5 * (sin((double)i) + 1), 127.5 * (1 - cos((double)i))));
//	return (RGB(rp, gp, bp));
//	
