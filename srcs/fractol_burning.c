/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_newton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:52:41 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 09:29:57 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void		m_power_two(t_plan *p)
{
	p->tmpr = p->zr * p->zr - p->zi * p->zi + p->cr;
	p->tmpi = fabs(p->zr * p->zi) * 2 + p->ci;
}

static void		m_power_three(t_plan *p)
{
	p->tmpr = ft_pow(p->zr, 3) - 3 * p->zr * p->zi * p->zi + p->cr;
	p->tmpi = 3 * fabs(p->zr * p->zr * p->zi - ft_pow(p->zi, 3)) + p->ci;
}

static void		init_burningship(int x, int y, t_view *v, t_plan *p)
{
	v->xmin = -2;
	v->xmax = 0.5;
	v->ymin = -1.25;
	v->ymax = 1.25;
	p->cr = (((float)x / WIN_WIDTH) * (v->xmax - v->xmin)) * p->zoom
		+ v->xmin + p->offx;
	p->ci = (((float)y / WIN_HEIGTH) * (v->ymax - v->ymin)) * p->zoom
		+ v->ymin + p->offy;
	p->zr = 0;
	p->zi = 0;
	p->tmpr = 0;
	p->tmpi = 0;
}

int				print_burningship(int x, int y, t_view *v, t_plan *p)
{
	int	i;

	init_burningship(x, y, v, p);
	i = 0;
	while (ft_sq(p->zr) + ft_sq(p->zi) < 4 && i < p->i_max)
	{
		if (p->power == 3)
			m_power_three(p);
		if (p->power == 2)
			m_power_two(p);
		if (p->zr == p->tmpr && p->zi == p->tmpi)
		{
			i = p->i_max;
			break ;
		}
		p->zr = p->tmpr;
		p->zi = p->tmpi;
		i++;
	}
	return (i);
}
