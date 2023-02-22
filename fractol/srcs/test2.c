/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:45:57 by pineau            #+#    #+#             */
/*   Updated: 2023/02/22 23:55:53 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "key_code.h"

int	main(void)
{
	t_mlx		mlx;
	t_fractal	fractal;
	t_img		img;
	int			keycode;

	img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	keycode = KEY_ESCAPE;
	initi_window(&mlx);
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
