/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:48:45 by pineau            #+#    #+#             */
/*   Updated: 2023/02/22 23:53:37 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "key_code.h"

void	initi_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
}

void	draw_fractal(t_fractal *fractal, t_mlx *mlx, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (fractal->type == MANDELBROT)
				draw_mandelbrot(fractal, x, y);
			else if (fractal->type == JULIA)
				draw_julia(fractal, x, y);
			else if (fractal->type == NOVA)
				draw_nova(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}
