/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:25:08 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/28 10:26:28 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_put_and_free_error(void *e, char *str, int fd)
{
	ft_putstr_fd(str, fd);
	e = fdf_mlx_del(e);
	ft_memdel((void**)&e);
	exit(0);
}

void	ft_put_error_usage(int fd)
{
	ft_putstr_fd("Wrong name file\n", fd);
	ft_putstr_fd("Usage mandelbrot, julia\n", fd);
	exit(0);
}
