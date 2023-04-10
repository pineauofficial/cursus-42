/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:08:11 by pineau            #+#    #+#             */
/*   Updated: 2023/04/05 17:23:01 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <key_code.h>
# include <math.h>

# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_colors
{
	int	start_red;
	int	start_green;
	int	start_blue;
	int	end_red;
	int	end_green;
	int	end_blue;
	int	red;
	int	green;
	int	blue;
}	t_colors;

typedef struct s_fractal
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_colors		*color;
	double			max_r;
	double			min_r;
	double			max_i;
	double			min_i;
	double			x;
	double			y;
	int				i;
	double			new_range_r;
	double			new_range_i;
	double			range_r;
	double			range_i;
	double			tmp_x;
	double			tmp_y;
	int				num;
	double			c_r;
	double			c_i;
}	t_fractal;

/*main.c*/
int		main(int argc, char **argv);
void	init_data(t_fractal *fractol, t_colors *color, char **argv, int nums);
void	init(int num, char **argv);
void	end(t_fractal *fractol);

/*fractal.c*/
int		fractals(t_fractal *fractol);
int		mandelbrot(t_fractal *fractol);
int		julia(t_fractal *fractol);
int		burning_ship(t_fractal *fractol);

/*event.c*/
int		key_press(int keysym, t_fractal *fractol);
int		cross_p(t_fractal *fractol);
void	init_hook(t_fractal *fractol);
void	julia_down(t_fractal *fractol);
void	julia_up(t_fractal *fractol);

/*colors.c*/
int		get_color(int i, t_colors *color);
void	def_colors(t_colors *color);

/*check.c*/
int		ft_strcmp(char *s1, char *s2);
int		which_fract(char **argv);
char	*name(int num);

/*image.c*/
t_img	*new_image(t_fractal *fractol);
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_fractal(t_fractal *fractol);

/*zoom.c*/
int		zoom(int button, int x, int y, t_fractal *fractol);
void	in(t_fractal *fractol, double x_center, double y_center);
void	out(t_fractal *fractol, double x_center, double y_center);

/*arrows.c*/
void	key_down(t_fractal *fractol);
void	key_up(t_fractal *fractol);
void	key_left(t_fractal *fractol);
void	key_right(t_fractal *fractol);

/*utils.c*/
double	abs_value(double x);

/*check_numbers.c*/
int		check_julia(char **argv);
int		ft_atoi(const char *nptr);
int		sizestr(int n);
char	*ft_itoa(int n);
int		check_numbers(char **argv);

#endif