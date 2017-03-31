/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_put_infos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:32:05 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 10:25:17 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void		window_put_infos_next(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 190, 0x00FFFFFF,
			"Colors         : press pad num 1, 2, 3, 4 or 5");
	mlx_string_put(e->mlx, e->win, 10, 210, 0x00FFFFFF,
			"Choose Fractal : press F1, F2, F3, F4, F5, F6 or F7");
	mlx_string_put(e->mlx, e->win, 10, 230, 0x00FFFFFF,
			"Up Down Iter   : press pad num + or -");
	mlx_string_put(e->mlx, e->win, 10, 250, 0x00FFFFFF,
			"Choose Cpu/Gpu : press C to use Cpu or G to use Gpu");
	mlx_string_put(e->mlx, e->win, 10, 270, 0x00FFFFFF,
			"Choose Fdf Draw: press F and ENJOY\n");
	mlx_string_put(e->mlx, e->win, 10, 290, 0x00FFFFFF,
			"==          MOUSE         ==");
	mlx_string_put(e->mlx, e->win, 10, 310, 0x00FFFFFF,
			"Classical move and click\n");
	mlx_string_put(e->mlx, e->win, 10, 330, 0x00FFFFFF,
			"== PRESS ENTER TO CONTINUE ==");
}

void			window_put_infos(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF,
			"____________  ___  _____ _____ _____ _		");
	mlx_string_put(e->mlx, e->win, 10, 30, 0x00FFFFFF,
			"|  ___| ___  / _  /  __  _   _|  _  | |	");
	mlx_string_put(e->mlx, e->win, 10, 50, 0x00FFFFFF,
			"| |_  | |_/ / /_    /   / | | | | | | |	");
	mlx_string_put(e->mlx, e->win, 10, 70, 0x00FFFFFF,
			"|  _| |    /|  _  | |     | | | | | | |	");
	mlx_string_put(e->mlx, e->win, 10, 90, 0x00FFFFFF,
			"| |   | |   | | | |  __/  | | | _/ / |____");
	mlx_string_put(e->mlx, e->win, 10, 110, 0x00FFFFFF,
			"|_|   |_| |_ _| |_/ ____/ |_/   ___/|_____/");
	mlx_string_put(e->mlx, e->win, 10, 170, 0x00FFFFFF,
			"==         COMMAND         ==");
	window_put_infos_next(e);
}
