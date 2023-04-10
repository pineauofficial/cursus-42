/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:24:19 by pineau            #+#    #+#             */
/*   Updated: 2023/04/06 14:44:14 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keysym, t_fractal *fractol)
{
	if (keysym == KEY_ESCAPE)
		mlx_loop_end(fractol->mlx);
	if (keysym == KEY_SPACE)
	{
		def_colors(fractol->color);
		draw_fractal(fractol);
	}
	if (keysym == KEY_LEFT)
		key_left(fractol);
	if (keysym == KEY_RIGHT)
		key_right(fractol);
	if (keysym == KEY_DOWN)
		key_down(fractol);
	if (keysym == KEY_UP)
		key_up(fractol);
	if (keysym == JULIA_UP)
		julia_up(fractol);
	if (keysym == JULIA_DOWN)
		julia_down(fractol);
	return (0);
}

int	cross_p(t_fractal *fractol)
{
	mlx_loop_end(fractol->mlx);
	return (0);
}

//nasamadi checker son fractol svp ca lui fait plaiz'
void	julia_down(t_fractal *fractol)
{
	fractol->c_r = fractol->c_r * 0.995;
	fractol->c_i = fractol->c_i * 0.995;
	draw_fractal(fractol);
}

//nasamadi checker son fractol svp ca lui fait plaiz'
void	julia_up(t_fractal *fractol)
{
	fractol->c_r = fractol->c_r * 1.005;
	fractol->c_i = fractol->c_i * 1.005;
	draw_fractal(fractol);
}

void	init_hook(t_fractal *fractol)
{
	mlx_hook(fractol->win, KeyPress, KeyPressMask, key_press, fractol);
	mlx_hook(fractol->win, ClientMessage, LeaveWindowMask, cross_p, fractol);
	mlx_hook(fractol->win, ButtonPress, ButtonPressMask, zoom, fractol);
	mlx_loop(fractol->mlx);
}
