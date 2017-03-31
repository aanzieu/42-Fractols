/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:03:59 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 08:35:45 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		zoom(int x, int y, t_env *e, double z)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (e->view.xmax - e->view.xmin) * (e->plan.zoom);
	h = (e->view.ymax - e->view.ymin) * (e->plan.zoom);
	nw = (e->view.xmax - e->view.xmin) * (e->plan.zoom * z);
	nh = (e->view.ymax - e->view.ymin) * (e->plan.zoom * z);
	e->plan.zoom *= z;
	e->plan.offx -= ((float)x / WIN_WIDTH) * (nw - w);
	e->plan.offy -= ((float)y / WIN_HEIGTH) * (nh - h);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		zoom(x, y, e, 1 / 1.1f);
		fdf_del(e);
	}
	else if (button == 5)
	{
		zoom(x, y, e, 1.1f);
		fdf_del(e);
	}
	if (y < 0)
		return (0);
	e->mouse.id |= 1 << button;
	return (0);
}

int			mouse_out(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	e->mouse.id &= ~(1 << button);
	return (0);
}

static void	julia_fixed_image(t_env *e, int x, int y)
{
	x -= WIN_WIDTH / 2;
	y -= WIN_HEIGTH / 2;
	e->plan.cr = ((float)x / WIN_WIDTH) * 1;
	e->plan.ci = ((float)y / WIN_HEIGTH) * 1;
	fdf_del(e);
}

int			mouse_mouve(int x, int y, t_env *e)
{
	double w;
	double h;

	e->mouse.lastx = e->mouse.x;
	e->mouse.lasty = e->mouse.y;
	e->mouse.x = x;
	e->mouse.y = y;
	if (e->mouse.id & (1 << 1))
	{
		w = (e->view.xmax - e->view.xmin) * e->plan.zoom;
		h = (e->view.ymax - e->view.ymin) * e->plan.zoom;
		e->plan.offx += (double)(e->mouse.lastx - e->mouse.x)
			/ WIN_WIDTH * w;
		e->plan.offy += (double)(e->mouse.lasty - e->mouse.y)
			/ WIN_HEIGTH * h;
	}
	if (e->plan.ctrl && e->view.fract == 1)
	{
		julia_fixed_image(e, x, y);
		return (0);
	}
	if (e->mouse.id)
		fdf_del(e);
	return (0);
}
