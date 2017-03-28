/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:58:39 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/28 10:25:20 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_image	*del_image(t_env *e, t_image *img)
{
	if (img != NULL)
	{
		if (img->img != NULL)
			mlx_destroy_image(e->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_env	*fdf_mlx_del(t_env *e)
{
	if (e->win != NULL)
		mlx_destroy_window(e->mlx, e->win);
	if (e->image != NULL)
		del_image(e, e->image);
	return (NULL);
}

void	fdf_del(t_env *e)
{
	ft_bzero(e->image->img_s, WIN_HEIGTH * WIN_WIDTH * e->image->bpp);
	expose_hook(e);
}
