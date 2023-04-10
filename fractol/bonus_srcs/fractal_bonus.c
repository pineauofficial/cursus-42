/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:40:56 by pineau            #+#    #+#             */
/*   Updated: 2023/04/10 16:19:51 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractals(t_fractal *fractol)
{
	if (fractol->num == 1)
		return (mandelbrot(fractol));
	if (fractol->num == 2)
		return (julia(fractol));
	if (fractol->num == 3)
		return (burning_ship(fractol));
	return (0);
}

int	mandelbrot(t_fractal *fractol)
{
	t_complex	z;
	t_complex	c;
	t_complex	z_new;

	z.r = 0;
	z.i = 0;
	c.r = fractol->min_r + (fractol->x / WIDTH)
		* (fractol->max_r - fractol->min_r);
	c.i = fractol->min_i + (fractol->y / HEIGHT)
		* (fractol->max_i - fractol->min_i);
	fractol->i = 0;
	while (fractol->i < MAX_ITER && z.r * z.r + z.i * z.i < 4.0)
	{
		z_new.r = z.r * z.r - z.i * z.i + c.r;
		z_new.i = 2 * z.r * z.i + c.i;
		z = z_new;
		fractol->i++;
	}
	if (z.r * z.r + z.i * z.i >= 4.0)
		return (0);
	else
		return (1);
}

int	julia(t_fractal *fractol)
{
	t_complex	z;
	t_complex	z_new;

	z.r = fractol->min_r + (fractol->x / WIDTH)
		* (fractol->max_r - fractol->min_r);
	z.i = fractol->min_i + (fractol->y / HEIGHT)
		* (fractol->max_i - fractol->min_i);
	fractol->i = 0;
	while (fractol->i < MAX_ITER && z.r * z.r + z.i * z.i < 4.0)
	{
		z_new.r = z.r * z.r - z.i * z.i + fractol->c_r;
		z_new.i = 2 * z.r * z.i + fractol->c_i;
		z = z_new;
		fractol->i++;
	}
	if (z.r * z.r + z.i * z.i >= 4.0)
		return (0);
	else
		return (1);
}

int	burning_ship(t_fractal *fractol)
{
	t_complex	z;
	t_complex	c;
	t_complex	z_new;

	z.r = 0;
	z.i = 0;
	c.r = fractol->min_r + (fractol->x / WIDTH)
		* (fractol->max_r - fractol->min_r);
	c.i = fractol->min_i + (fractol->y / HEIGHT)
		* (fractol->max_i - fractol->min_i);
	fractol->i = 0;
	while (fractol->i < MAX_ITER && z.r * z.r + z.i * z.i < 4.0)
	{
		z_new.r = abs_value(z.r);
		z_new.i = abs_value(z.i);
		z = z_new;
		z_new.r = z.r * z.r - z.i * z.i + c.r;
		z_new.i = 2 * z.r * z.i + c.i;
		z = z_new;
		fractol->i++;
	}
	if (z.r * z.r + z.i * z.i >= 4.0)
		return (0);
	else
		return (1);
}
