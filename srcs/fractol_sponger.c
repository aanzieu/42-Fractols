/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sponger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:48:29 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/14 15:33:54 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		print_sponge(int x, int y, t_view *v, t_plan *p)
{
	int		i;
	(void)v;
	i = 0;
	p->zoom = (p->zoom >= 5) ? 1.6 : p->zoom;
	p->zoom = (p->zoom <= 0.6) ? 1.6 : p->zoom;
	x = (x) / p->zoom;
	y = (y) / p->zoom;
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

