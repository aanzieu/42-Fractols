/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sponger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:48:29 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 10:26:22 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		print_sponge(int x, int y, t_view *v, t_plan *p)
{
	int		i;

	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
	i = 0;
	x = (((double)x / WIN_WIDTH) *
			(v->xmax - v->xmin)) * p->zoom + v->xmin + p->offx;
	y = (((double)y / WIN_HEIGTH) *
			(v->ymax - v->ymin)) * p->zoom + v->ymin + p->offy;
	x = ft_abs(x);
	y = ft_abs(y);
	while ((x > 0 || y > 0) && i < p->i_max)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (i);
}
