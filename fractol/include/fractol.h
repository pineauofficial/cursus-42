/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:08:11 by pineau            #+#    #+#             */
/*   Updated: 2023/02/23 00:17:30 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>

// typedef struct s_fractal
// {
// 	void	*mlx;
// 	void	*win;
// 	int		*colors;
// }	t_fractal;

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractal
{
	int			type;
	int			max_iter;
	int			max_re;
	int			min_re;
	int			max_im;
	int			min_im;
	double		zoom;
	t_complex	pos;
}	t_fractal;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

int		exit_fractol(int keycode, t_mlx *mlx);
int		cross_press(t_mlx *mlx);
void	initi_window(t_mlx *mlx);
void	display_image(t_img *img, t_mlx *mlx);
void	move_fractal_left(t_fractal *fractal);
void	move_fractal_right(t_fractal *fractal);
void	move_fractal_up(t_fractal *fractal);
void	move_fractal_down(t_fractal *fractal);
int		handle_keypress(int keycode, t_fractal *fractal);
void	draw_fractal(t_fractal *fractal, t_mlx *mlx, t_img *img);
void	draw_mandelbrot(t_fractal *fractal, int x, int y);
void	draw_julia(t_fractal *fractal, int x, int y);
void	draw_nova(t_fractal *fractal, int x, int y);
int		create_trgb(int t, int r, int g, int b);

#endif