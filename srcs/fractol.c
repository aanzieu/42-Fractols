/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:46:37 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/28 11:15:10 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../cudainclude/cuda_call.h"

static void	fdf_test(t_env *e)
{
	char *tmp;

	tmp = ft_strjoin("~/Documents/Fdf42ok/fdf ", e->fractal->str);
	if (system(tmp) == 0)
		e->opt = CUDA;
	free(tmp);
}

int			expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->opt == FDF)
	{
		fdf_print_fractal(e, e->fractal, 0, 0);
		fdf_test(e);
	}
	if (e->opt == CUDA)
		print_fractal_cuda(e);
	if (e->opt == FRACT)
		print_fractal(e, e->fractal);
	return (0);
}

t_fractal	*search_fractal(char *argv)
{
	int					res;
	int					i;
	static t_fractal	fractol[3] = {
		{"mandelbrot", print_mandelbrot, cuda_call_mandelbrot},
		{"julia", print_julia, cuda_call_julia},
	};

	i = 0;
	while (fractol[i].str != NULL)
	{
		if ((res = ft_strcmp(fractol[i].str, argv)) == 0)
			return (&fractol[i]);
		i++;
	}
	return (NULL);
}

int			main(int argc, char **argv)
{
	t_env		*e;
	t_fractal	*f;

	e = NULL;
	if (argc < 2 || argc >= 3)
	{
		ft_putstr_fd("No <filename>\n", 2);
		return (0);
	}
	if (argc == 2)
	{
		if (!(f = search_fractal(argv[1])))
			ft_put_error_usage(2);
		e = init_env(f);
		e->namefract = argv[1];
	}
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_hook(e->win, 4, (1L << 2), mouse_hook, e);
	mlx_hook(e->win, 5, (1L << 3), mouse_out, e);
	mlx_hook(e->win, 6, (1L << 6), mouse_mouve, e);
	mlx_loop(e->mlx);
	return (0);
}
