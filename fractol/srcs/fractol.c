/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:18:08 by pineau            #+#    #+#             */
/*   Updated: 2023/02/22 01:21:42 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fractol.h"
#include "key_code.h"

/*
typedef struct s_fractal {
	int					width;
	int					height;
	int					max_iter;
	double				factor_r;
	double				factor_i;
	struct s_complex	*min;
	struct s_complex	*max;
}	t_fractal;

typedef struct s_complex {
	double	r;
	double	i;
}	t_complex;

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	z.i = 0;
	z.r = 0;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < max_iter)
	{
		tmp.r = z.r * z.r - z.i * z.i, 2 * z.r * z.i;
		tmp.i = z.r * z.r - z.i * z.i, 2 * z.r * z.i;
		z.r = tmp.r + c.r;
		z.i = tmp.i + c.i;
		i++;
	}
	return (i);
}

void draw_fractal(void *mlx, void *win, void *img, int *data, t_fractal *fractal)
{
	t_complex	c;
	int			color;
	int			x;
	int			y;

	c.r = 0;
	c.i = 0;
	y = 0;
	while (y < fractal->height)
	{
		c.i = fractal->max->i - y * fractal->factor_i;
		x = 0;
		while (x < fractal->width)
		{
			c.r = fractal->min->r + x * fractal->factor_r;
			color = mandelbrot(c, fractal->max_iter);
			if (color == fractal->max_iter)
				data[y * fractal->width + x] = create_trgb(0, 10, 20, 30);
			else
				data[y * fractal->width + x] = color * create_trgb(0, 10, 20, 30);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_fractal	fractal;
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int	endian;
	int	bits_per_pixel;
	int	size_line;

	t_complex	min;
	t_complex	max;
	bits_per_pixel = 32;
	size_line = fractal.width * sizeof(int);
	endian = 0;

	max.r = 0.5;
	max.i = 1.2;
	min.r = -2;
	min.i = -1.2;
	fractal.width = 1200;
	fractal.height = 500;
	fractal.max_iter = 256;
	fractal.factor_r = (max.r - min.r) / (double)(fractal.width - 1);
	fractal.factor_i = (max.i - min.i) / (double)(fractal.height - 1);
	fractal.min = &min;
	fractal.max = &max;
	mlx = mlx_init();
	win = mlx_new_window(mlx, fractal.width, fractal.height, "Mandelbrot Set");
	img = mlx_new_image(mlx, fractal.width, fractal.height);
	data = (int *)mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	draw_fractal(mlx, win, img, data, &fractal);
	mlx_loop(mlx);
	return (0);
}

*/