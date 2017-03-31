/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:25:08 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 09:04:53 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_put_and_free_error(void *e, char *str, int fd)
{
	ft_putstr_fd(str, fd);
	fdf_mlx_del(e);
	ft_memdel((void**)&e);
	exit(0);
}

void	ft_put_error_usage(int fd)
{
	ft_putstr_fd("Usage:\n", fd);
	ft_putstr_fd("./fractol mandelbrot\n", fd);
	ft_putstr_fd("./fractol julia\n", fd);
	ft_putstr_fd("./fractol burning\n", fd);
	ft_putstr_fd("./fractol sword\n", fd);
	ft_putstr_fd("./fractol sponge\n", fd);
	ft_putstr_fd("./fractol rabbit\n", fd);
	ft_putstr_fd("./fractol sinus\n", fd);
	exit(1);
}
