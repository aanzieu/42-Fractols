/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:16:28 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/14 16:48:24 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
/*
void	init_cube(int x, int y, t_view *v, t_plan *p)
{
	v->xmin = -2;
	v->xmax = 2;
	v->ymin = -2;
	v->ymax = 2;
	p->cr = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * p->zoom + v->xmin + p->offx;
	p->ci = (((double)y / WIN_HEIGTH) * (v->ymax - v->ymin)) * p->zoom + v->ymin + p->offy;
	p->zr = p->cr;
	p->zi = p->ci;
//	p->zc = 0;
}
*/
int		print_cube(int x, int y, t_view *v, t_plan *p)
{
	int	i;
	v->xmin = -2;
	v->xmax = 2;
	v->ymin = -2;
	v->ymax = 2;
//	p->zoom = (p->zoom >= 5) ? 1.6 : p->zoom;
//	p->zoom = (p->zoom <= 0.6) ? 1.6 : p->zoom;
	x = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * p->zoom + v->xmin + p->offx;
	y = (((double)y / WIN_HEIGTH) * (v->ymax - v->ymin)) * p->zoom + v->ymin + p->offy;
	i = 0;
//	x = x / p->zoom + WIN_WIDTH *0.5;;
//	y = y / p->zoom + WIN_HEIGTH *0.5;;
//	x = ft_abs(x);
//	y = ft_abs(y);
	while ((x > 0 || y > 0) && i < p->i_max)
	{
		if (x % 4 == 1 && y % 4 == 1)
			return (0);
		x /= 4;
		y /= 4;
		i++;
	}
	return (i);
}
