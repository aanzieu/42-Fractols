/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:09:29 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 10:23:02 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_julia(int x, int y, t_view *v, t_plan *p)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
	p->zr = (((float)x / WIN_WIDTH) *
			(v->xmax - v->xmin)) * p->zoom + v->xmin + p->offx;
	p->zi = (((float)y / WIN_HEIGTH) *
			(v->ymax - v->ymin)) * p->zoom + v->ymin + p->offy;
	v->fract = 1;
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

int			print_sword(int x, int y, t_view *v, t_plan *p)
{
	int		i;
	double	tmpr;
	double	tmpi;

	init_julia(x, y, v, p);
	i = 0;
	while (ft_sq(p->zr) + ft_sq(p->zi) < 4 && i < p->i_max)
	{
		tmpr = p->zr * p->zr - p->zi * p->zi + p->cr;
		tmpi = fabs(p->zr * p->zi) * p->power + p->ci;
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

int			print_rabbit(int x, int y, t_view *v, t_plan *p)
{
	int		i;
	double	tmpr;
	double	tmpi;

	init_julia(x, y, v, p);
	i = 0;
	while (ft_sq(p->zr) + ft_sq(p->zi) < 4 && i < p->i_max)
	{
		tmpr = p->zr * p->zr - p->zi * p->zi - 0.123;
		tmpi = p->zr * p->zi * p->power + 0.745;
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

int			print_sinus(int x, int y, t_view *v, t_plan *p)
{
	int		i;
	double	tmpr;
	double	tmpi;

	init_julia(x, y, v, p);
	i = 0;
	while (ft_sq(p->zr) + ft_sq(p->zi) < 4 && i < p->i_max)
	{
		tmpr = sin(p->zr) * ((0.9) * exp(p->zi) + (1.1) * exp(-p->zi));
		tmpi = sin(p->zr) * ((1.1) * exp(p->zi) - (0.9) * exp(-p->zi));
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
