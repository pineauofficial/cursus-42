/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:45:57 by pineau            #+#    #+#             */
/*   Updated: 2023/02/23 00:20:47 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "key_code.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_img		img;
	t_mlx		mlx;
	t_fractal	fractal;
	int			keycode;

	keycode = KEY_ESCAPE;
	initi_window(&mlx);
	img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	keycode = mlx_hook(mlx.win, 2, 1L << 0, handle_keypress, &mlx);
	keycode = mlx_hook(mlx.win, 2, 1L << 0, exit_fractol, &mlx);
	keycode = mlx_hook(mlx.win, 33, 1L << 5, cross_press, &mlx);
	if (keycode != KEY_ESCAPE)
	{
		mlx_clear_window(mlx.mlx, mlx.win);
		draw_fractal(&fractal, &mlx, &img);
	}
	mlx_loop(mlx.mlx);
	return (0);
}
//permet de recuperer les donnes d'une image
//img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);