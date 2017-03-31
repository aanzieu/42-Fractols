/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:57:49 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 10:21:20 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../cudainclude/cuda_call.h"

static int		key_hook_opt(int button, t_env *e)
{
	if (button == KEY_POW3)
		e->plan.power = 3;
	else if (button == KEY_POW4)
		e->plan.power = 4;
	else if (button == KEY_POW2)
		e->plan.power = 2;
	else if (button == KEY_ITERU)
		e->plan.i_max += ITER_PP;
	else if (button == KEY_ITERD && e->plan.i_max >= ITER_MIN + ITER_PP)
		e->plan.i_max -= ITER_PP;
	else if (button == KEY_INIT)
		init_env_next(e);
	else if (button == KEY_ENTER)
		e->infos = 1;
	if (button == KEY_POW3 || button == KEY_POW4 || button == KEY_POW2 ||
			button == KEY_ITERU || button == KEY_ITERD ||
			button == KEY_INIT || button == KEY_ENTER)
		return (1);
	return (0);
}

static int		colors_hook(int button, t_env *e)
{
	if (button == COLOR1)
		e->color.light = 0.5;
	else if (button == COLOR2)
		e->color.light = 0.61255;
	else if (button == COLOR3)
		e->color.light = 0.7540;
	else if (button == COLOR4)
		e->color.light = 0.25488;
	else if (button == COLOR5)
		e->color.light = 0.398551;
	else if (button == COLOR6)
		e->color.psyche = e->color.psyche == 0 ? 1 : 0;
	if (button == COLOR1 || button == COLOR2 || button == COLOR3 ||
			button == COLOR4 || button == COLOR5 || button == COLOR6)
		return (1);
	return (0);
}

static int		fractal_hook(int button, t_env *e)
{
	t_fractal *f;

	f = NULL;
	if (button == KEYF1 || button == KEYF2 || button == KEYF3 || button ==
			KEYF4 || button == KEYF5 || button == KEYF6 || button == KEYF7)
	{
		fdf_mlx_del(e);
		if (button == KEYF1)
			f = search_fractal("mandelbrot");
		else if (button == KEYF2)
			f = search_fractal("julia");
		else if (button == KEYF3)
			f = search_fractal("burning");
		else if (button == KEYF4)
			f = search_fractal("sword");
		else if (button == KEYF5)
			f = search_fractal("sponge");
		else if (button == KEYF6)
			f = search_fractal("rabbit");
		else if (button == KEYF7)
			f = search_fractal("sinus");
		init_env(e, f);
		return (1);
	}
	return (0);
}

int				key_hook(int button, t_env *e)
{
	if (button == KEY_EXIT)
	{
		fdf_mlx_del(e);
		exit(0);
	}
	else if (button == CUDA)
		e->opt = CUDA;
	else if (button == FDF)
		e->opt = FDF;
	else if (button == FRACT)
		e->opt = FRACT;
	else if (button == KEY_FIXED)
		e->plan.ctrl = e->plan.ctrl == 0 ? 1 : 0;
	if (button == CUDA || button == FDF || button == FRACT ||
			button == KEY_FIXED || key_hook_opt(button, e) ||
			colors_hook(button, e) || fractal_hook(button, e))
		fdf_del(e);
	return (0);
}
