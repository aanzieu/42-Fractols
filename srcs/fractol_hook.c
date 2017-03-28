/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:57:49 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/28 17:11:45 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../cudainclude/cuda_call.h"

int		key_hook_opt(int button, t_env *e)
{
	if (button == KEY_EXIT)
	{
		cuda_call_mandelbrot(NULL, 0, e, 1);
		fdf_mlx_del(e);
		exit(1);
	}
	if (button == KEY_POW3)
		e->plan.power = 3;
	if (button == KEY_POW4)
		e->plan.power = 4;
	if (button == KEY_POW2)
		e->plan.power = 2;
	if (button == KEY_ITERU)
		e->plan.i_max += ITER_PP;
	if (button == KEY_ITERD && e->plan.i_max >= ITER_MIN + ITER_PP)
		e->plan.i_max -= ITER_PP;
	if (button == KEY_INIT)
		init_env_next(e);
	fdf_del(e);
	return (0);
}

int		key_hook(int button, t_env *e)
{
	if (button == CUDA)
		e->opt = CUDA;
	if (button == FDF)
		e->opt = FDF;
	if (button == FRACT)
		e->opt = FRACT;
	if (button == KEY_FIXED)
		e->plan.ctrl = e->plan.ctrl == 0 ? 1 : 0;
	if (button == COLOR1)
		e->color->light = 0.5;
	if (button == COLOR2)
		e->color->light = 0.61255;
	if (button == COLOR3)
		e->color->light = 0.7540;
	if (button == COLOR4)
		e->color->light = 0.25488;
	if (button == COLOR5)
		e->color->light = 0.398551;
	if (button == COLOR6)
		e->color->psyche = e->color->psyche == 0 ? 1 : 0;
	key_hook_opt(button, e);
	return (0);
}
