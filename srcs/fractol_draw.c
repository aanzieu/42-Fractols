/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 07:35:25 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/28 16:17:00 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../cudainclude/cuda_call.h"

void	draw_p(t_env *e, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGTH)
		return ;
	((unsigned int*)e->image->img_s)[y * WIN_HEIGTH + x] = color;
}

void	print_fractal_cuda(t_env *e)
{
	int				y;
	int				x;
	unsigned int	*a_h;
	size_t			size;

	size = WIN_HEIGTH * WIN_WIDTH;
	if (!(a_h = (unsigned int *)malloc(sizeof(unsigned int) * size)))
		ft_put_and_free_error(e, "ERROR MALLOC", 2);
	e->fractal->f_c(a_h, size, e, 0);
	y = 0;
	while (y <= WIN_HEIGTH)
	{
		x = 0;
		while (x <= WIN_WIDTH)
		{
			draw_p(e, x, y, get_c(a_h[y * WIN_HEIGTH + x], e));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image->img, 0, 0);
	ft_memdel((void**)&a_h);
}

void	print_fractal(t_env *e, t_fractal *f)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < WIN_HEIGTH)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			i = f->f_p(x, y, &e->view, &e->plan);
			if (i != e->plan.i_max)
				draw_p(e, x, y, get_c(i, e));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image->img, 0, 0);
}

void	fdf_print_file(int i, int fd)
{
	char	*nbr;

	nbr = ft_itoa(i);
	ft_putstr_fd(nbr, fd);
	ft_putchar_fd(' ', fd);
	free(nbr);
}

void	fdf_print_fractal(t_env *e, t_fractal *f, int x, int y)
{
	int		i;
	int		fd;
	int		dd;

	dd = 5;
	y = 0;
	if ((fd = open(f->str, O_WRONLY | O_CREAT, S_IRWXU | O_TRUNC)) == -1)
		return ;
	while (y < WIN_HEIGTH)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			i = f->f_p(x, y, &e->view, &e->plan);
			if ((y % dd) == 0 && (x % dd) == 0)
				fdf_print_file(i, fd);
			x++;
		}
		if ((y % dd) == 0)
			ft_putchar_fd('\n', fd);
		y++;
	}
	close(fd);
}
