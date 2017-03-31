/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:46:22 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/31 10:40:06 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../srcs/libft/libft.h"

# include <math.h>
# include <fcntl.h>

# define WIN_WIDTH	1024
# define WIN_HEIGTH	1024
# define N			(WIN_WIDTH * WIN_HEIGTH)
# define HSL(r,g,b)(256 * 256 * (r) + 256 * (g) + (b))
# define RGB(r,g,b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# define FDF		3
# define CUDA		5
# define FRACT		8

# define KEY_ITERU	69
# define KEY_ITERD	78
# define ITER_MAX	20
# define ITER_MIN	1
# define ITER_PP	1

# define KEY_EXIT	53
# define KEY_INIT	48
# define KEY_ENTER	36

# define KEY_POW2	19
# define KEY_POW3	20
# define KEY_POW4	21

# define KEY_FIXED	49

# define KEYF1		122
# define KEYF2		120
# define KEYF3		99
# define KEYF4		118
# define KEYF5		96
# define KEYF6		97
# define KEYF7		98

# define COLOR1		83
# define COLOR2		84
# define COLOR3		85
# define COLOR4		86
# define COLOR5		87
# define COLOR6		88

typedef struct s_env	t_env;

/*
** Structure View Position Fractal
*/

typedef struct			s_view
{
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;
	int					fract;
}						t_view;

/*
** Structure Complex Calcul Fractal
*/

typedef struct			s_plan
{
	double				zr;
	double				zi;
	float				cr;
	float				ci;
	double				tmpr;
	double				tmpi;
	float				offx;
	float				offy;
	double				zoom;
	int					power;
	int					ctrl;
	float				i_max;
	int					radius;
}						t_plan;

/*
** Structure Mlx Image
*/

typedef	struct			s_image
{
	void				*img;
	char				*img_s;
	int					bpp;
	int					s_l;
	int					endian;
}						t_image;

/*
** Structure Mlx Color
*/

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
	float				light;
	float				sat;
	int					psyche;
}						t_color;

/*
** Structure Mouse Position
*/

typedef struct			s_mouse
{
	char				id;
	int					x;
	int					y;
	int					lastx;
	int					lasty;
}						t_mouse;

/*
** Structure Environnement Mlx
*/

struct					s_env
{
	void				*mlx;
	void				*win;
	struct s_mouse		mouse;
	struct s_plan		plan;
	struct s_view		view;
	struct s_color		color;
	struct s_image		*image;
	struct s_fractal	*fractal;
	int					infos;
	int					opt;
};

/*
** Structure Pointer Fractal name
*/

typedef struct			s_fractal
{
	char				*str;
	int					(*f_p)(int x, int y, t_view *v, t_plan *p);
	void				(*f_c)(unsigned int* a_h,
			unsigned int size, t_env *e, int end);
}						t_fractal;

/*
** Fractol
*/

int						print_mandelbrot(int x, int y, t_view *v, t_plan *p);
int						print_julia(int x, int y, t_view *v, t_plan *p);
int						print_burningship(int x, int y, t_view *v, t_plan *p);
int						print_sponge(int x, int y, t_view *v, t_plan *p);
int						print_sword(int x, int y, t_view *v, t_plan *p);
int						print_rabbit(int x, int y, t_view *v, t_plan *p);
int						print_sinus(int x, int y, t_view *v, t_plan *p);

/*
** Draw Type
*/

void					fdf_print_fractal(t_env *e, t_fractal *f, int x, int y);
void					print_fractal_cuda(t_env *e);
void					print_fractal(t_env *e, t_fractal *f);
void					draw_p(t_env *e, int x, int y, int color);

/*
** Init env
*/

void					init_env(t_env *e, t_fractal *f);
void					init_env_next(t_env *e);
void					init_image(t_env *e);
t_image					*new_image(t_env *e);
t_fractal				*search_fractal(char *argv);

/*
** Del
*/

void					fdf_del(t_env *e);
void					fdf_del_point(t_env *e);
t_image					*del_image(t_env *e, t_image *img);
void					fdf_mlx_del(t_env *e);

/*
** Error
*/

void					ft_put_and_free_error(void *e, char *str, int fd);
void					ft_put_error_usage(int fd);

/*
** Hook
*/

void					hook_set(t_env *e);
int						mouse_hook(int	button, int	x, int y, t_env *e);
int						mouse_out(int button, int x, int y, t_env *e);
int						mouse_mouve(int x, int y, t_env *e);
int						key_hook(int	button, t_env *e);
int						expose_hook(t_env *e);
void					window_put_infos(t_env *e);

/*
** Colors
*/

int						get_c(int i, t_env *e, double m, double h);
void					init_color(int r, int g, int b, t_env *e);

#endif
