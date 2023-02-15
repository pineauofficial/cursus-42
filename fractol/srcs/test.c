/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:25:42 by pineau            #+#    #+#             */
/*   Updated: 2023/02/15 17:46:53 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fractol.h"
#include "key_code.h"

void	initi_window(t_fractal *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, 1920, 1080, "Hello world!");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw(t_fractal *fractol, t_data *img)
{
	int			i;

	i = 0;
	img->img = mlx_new_image(fractol->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	while (i < 100)
	{
		my_mlx_pixel_put(img, i, i, create_trgb(250, 250, 50, 250));
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, img->img, 0, 0);
}

int	handle_key_press(int keycode, t_fractal *fractol)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	return (0);
}

int cross_press(t_fractal *fractol)
{
	mlx_loop_end(fractol->mlx);
	return (0);
}

int	main(void)
{
	t_fractal	fractol;
	t_data		img;

	initi_window(&fractol);
	draw(&fractol, &img);
	mlx_hook(fractol.win, 2, 1L << 0, handle_key_press, &fractol);
	mlx_hook(fractol.win, 33, 1L << 5, cross_press, &fractol);
	mlx_loop(fractol.mlx);
}
