/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:46:37 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 09:28:54 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../cudainclude/cuda_call.h"

static void	fdf_test(t_env *e)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin("~/Documents/Fdf42ok/fdf ", e->fractal->str);
	tmp2 = ft_strjoin(tmp, " 123005123122015015");
	if (system(tmp2) == 0)
		e->opt = CUDA;
	free(tmp);
	free(tmp2);
}

void		hook_set(t_env *e)
{
	mlx_hook(e->win, 2, 2, key_hook, e);
	mlx_hook(e->win, 4, (1L << 2), mouse_hook, e);
	mlx_hook(e->win, 5, (1L << 3), mouse_out, e);
	mlx_hook(e->win, 6, (1L << 6), mouse_mouve, e);
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
	int					i;
	static t_fractal	fractol[8] = {
		{"mandelbrot", print_mandelbrot, cuda_call_mandelbrot},
		{"julia", print_julia, cuda_call_julia},
		{"burning", print_burningship, cuda_call_burning},
		{"sword", print_sword, cuda_call_sword},
		{"sponge", print_sponge, cuda_call_rdone},
		{"rabbit", print_rabbit, cuda_call_rabbit},
		{"sinus", print_sinus, cuda_call_sinus},
		{NULL, NULL, NULL}
	};

	i = 0;
	while (fractol[i].str != NULL)
	{
		if ((ft_strcmp(fractol[i].str, argv)) == 0)
			return (&fractol[i]);
		i++;
	}
	return (NULL);
}

int			main(int argc, char **argv)
{
	t_env		*e;
	t_fractal	*f;

	if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
		ft_put_and_free_error(e, "Malloc Error\n", 2);
	if (argc < 2 || argc >= 3)
		ft_put_error_usage(2);
	if ((f = search_fractal(argv[1])) == NULL)
		ft_put_error_usage(2);
	if ((e->mlx = mlx_init()) == NULL)
		ft_put_and_free_error(e, "Init MLX Error\n", 2);
	init_env(e, f);
	if (e->infos == 0)
		window_put_infos(e);
	else
		mlx_expose_hook(e->win, expose_hook, e);
	hook_set(e);
	mlx_loop(e->mlx);
	return (0);
}
