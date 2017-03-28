/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:46:22 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/28 17:06:34 by aanzieu          ###   ########.fr       */
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
# define HEXA		"abcdef0123456789"
# define DEC		"0123456789"
# define HSL(r,g,b)(256 * 256 * (r) + 256 * (g) + (b))
# define RGB(r,g,b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# define FDF		3
# define CUDA		8
# define FRACT		5

# define AXE_X		2
# define AXE_Y		1
# define AXE_Z		0
# define ISO		0
# define PARA		1
# define ORTHO		2
# define SPHERE		3

# define KEY_ITERU	69
# define KEY_ITERD	78
# define ITER_MAX	500
# define ITER_MIN	1
# define ITER_PP	1

# define KEY_EXIT	53
# define KEY_INIT	48

# define KEY_POW2	19
# define KEY_POW3	20
# define KEY_POW4	21

# define KEY_FIXED	49

# define COLOR1		83
# define COLOR2		84
# define COLOR3		85
# define COLOR4		86
# define COLOR5		87
# define COLOR6		88

typedef struct s_env t_env;

/*
** Structure point
*/

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				dx;
	int				dy;
	int				color;
	int				col;
}					t_point;

/*
** Structure Rotation
*/

typedef struct		s_rotation
{
	double			rx;
	double			ry;
	double			rz;
	double			px;
	double			py;
	double			pz;
}					t_rot;

/*
** Structure Bresenham
*/

typedef struct		s_bresenham
{
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	double			d_err;
}					t_br;

/*
** Structure View Position Fractal
*/

typedef struct		s_view
{
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
}					t_view;

/*
** Structure Complex Calcul Fractal
*/

typedef struct		s_plan
{
	double			zr;
	double			zi;
	float			cr;
	float			ci;
	double			tmpr;
	double			tmpi;
	float			offx;
	float			offy;
	double			zoom;
	int				power;
	int				ctrl;
	float			i_max;
	int				radius;
}					t_plan;

/*
** Structure Fdf Option
*/

/*
** Structure Mlx Image
*/
typedef	struct		s_image
{
	void			*img;
	char			*img_s;
	int				bpp;
	int				s_l;
	int				endian;
}					t_image;

/*
** Structure Mlx Color
*/

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	float			light;
	float			sat;
	int				psyche;
}					t_color;

/*
** Structure Mouse Position
*/

typedef struct		s_mouse
{
	char		id;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

/*
** Structure Environnement Mlx
*/

struct s_env
{
	void				*mlx;
	void				*win;
	char				*namefract;
	
	struct s_mouse		mouse;
	struct s_plan		plan;
	struct s_view		view;
	struct s_color		*color;
	struct s_image		*image;
	struct s_fractal	*fractal;
	int				min_z;
	int				max_z;
	int				max_w;
	int				max_h;
	int				colorinit;
	float			fovy;
	int				near;
	int				far;
	int				ud;
	int				lr;
	int				rotation;
	int				method;
	struct s_color	*color_min;
	struct s_color	*color_max;
	struct s_point	**map;
	
	int					opt;
};

/*
** Structure Pointer Fractal name
*/

typedef struct		s_fractal
{
	char			*str;
	int				(*f_p)(int x, int y, t_view *v, t_plan *p);
	void			(*f_c)(unsigned int* a_h, unsigned int size, t_env *e, int end);
}					t_fractal;

/*
** Mandelbrot.FDF
*/

int		print_mandelbrot(int x, int y, t_view *v, t_plan *p);
int		print_julia(int x, int y, t_view *v, t_plan *p);
int		print_sponge(int x, int y, t_view *v, t_plan *p);
int		print_cube(int x, int y, t_view *v, t_plan *p);
void	fdf_print_fractal(t_env *e, t_fractal *f, int x, int y);
void	print_fractal_cuda(t_env *e);

/*
** Init.FDF
*/

t_env				*init_env(t_fractal *f);
t_image				*new_image(t_env *e);
void		init_env_next(t_env *e);
int		mouse_out(int button, int x, int y, t_env *e);

/*
** Draw.FDF
*/

void				draw_p(t_env *e, int x, int y, int color);
void				print_fractal(t_env *e, t_fractal *f);

/*
** Del.FDF
*/

void				fdf_del(t_env *e);
void				fdf_del_point(t_env *e);
t_image				*del_image(t_env *e, t_image *img);
t_env				*fdf_mlx_del(t_env *e);
void				cleanup(char **str);
int					expose_hook(t_env *e);

/*
** Error.FDF
*/

void	ft_put_and_free_error(void *e, char *str,  int fd);
void	ft_put_error_usage(int fd);

/*
** Hook.FDF
*/
void				init_image(t_env *e);
int					mouse_hook(int	button, int	x, int y, t_env *e);
int					key_hook(int	button, t_env *e);
int					mouse_mouve(int x, int y, t_env *e);

/*
** Colors.FDF
*/

t_color				*init_color(int r, int g, int b);
int					get_c(int i, t_env *e);

#endif
