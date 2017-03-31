/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:47:02 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 10:22:04 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_image		*new_image(t_env *e)
{
	t_image *img;

	if (!(img = (t_image *)ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGTH)))
		return (del_image(e, img));
	img->img_s = mlx_get_data_addr(img->img, &img->bpp, &img->s_l,
			&img->endian);
	img->bpp /= 8;
	return (img);
}

void		init_env_next(t_env *e)
{
	e->plan.offx = 0;
	e->plan.offy = 0;
	if (ft_strcmp(e->fractal->str, "sponge") == 0)
		e->plan.zoom = 2000;
	else
		e->plan.zoom = 1.1f;
	e->plan.i_max = 500;
	e->plan.radius = 4;
	e->plan.power = 2;
	e->plan.cr = 0;
	e->plan.ci = 0;
	e->plan.ctrl = 1;
	e->opt = FRACT;
	e->infos = 0;
	e->view.fract = 0;
}

void		init_env(t_env *e, t_fractal *f)
{
	char	*title;

	title = ft_strjoin("Aanzieu - Fract'ol-- ", f->str);
	if ((e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGTH, title)) == NULL)
		ft_put_and_free_error(e, "Init mlx Error\n", 2);
	free(title);
	e->fractal = f;
	e->image = new_image(e);
	init_color(1, 0, 0, e);
	init_env_next(e);
}
