/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:09:29 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/28 10:13:15 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_julia(int x, int y, t_view *v, t_plan *p)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
	p->zr = ((4 * (float)x / WIN_WIDTH - 2) / p->zoom)
		+ ((p->offx / WIN_WIDTH));
	p->zi = ((-4 * (float)y / WIN_HEIGTH + 2) / p->zoom)
		+ ((p->offy / WIN_HEIGTH));
}

int			print_julia(int x, int y, t_view *v, t_plan *p)
{
	int		i;
	double	tmpr;
	double	tmpi;

	init_julia(x, y, v, p);
	i = 0;
	while (ft_sq(p->zr) + ft_sq(p->zi) < 4 && i < p->i_max)
	{
		tmpr = p->zr * p->zr - p->zi * p->zi + p->cr;
		tmpi = p->zr * p->zi * p->power + p->ci;
		if (p->zr == tmpr && p->zi == tmpi)
		{
			i = p->i_max;
			break ;
		}
		p->zr = tmpr;
		p->zi = tmpi;
		i++;
	}
	return (i);
}
