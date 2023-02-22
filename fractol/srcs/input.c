/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:49:45 by pineau            #+#    #+#             */
/*   Updated: 2023/02/22 21:50:22 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "key_code.h"

int	exit_fractol(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESCAPE)
	{
		if (mlx->img.img)
			mlx_destroy_image(mlx->mlx, mlx->img.img);
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		if (mlx->mlx)
			free(mlx->mlx);
		exit(0);
	}
	return (keycode);
}

int	cross_press(t_mlx *mlx)
{
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
	exit(0);
}

int	handle_keypress(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_LEFT)
		move_fractal_left(fractal);
	else if (keycode == KEY_RIGHT)
		move_fractal_right(fractal);
	else if (keycode == KEY_UP)
		move_fractal_up(fractal);
	else if (keycode == KEY_DOWN)
		move_fractal_down(fractal);
	// else if (keycode == KEY_SPACE)
	// 	change_color(fractal);
	else
		return (0);
	return (keycode);
}


