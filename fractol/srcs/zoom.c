/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:59:06 by pineau            #+#    #+#             */
/*   Updated: 2023/04/03 16:25:37 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int button, int x, int y, t_fractal *fractol)
{
	double	x_center;
	double	y_center;

	fractol->tmp_x = (double)x;
	fractol->tmp_y = (double)y;
	x_center = 0.0;
	y_center = 0.0;
	if (button == 4)
		in(fractol, x_center, y_center);
	if (button == 5)
		out(fractol, x_center, y_center);
	return (0);
}

void	in(t_fractal *fractol, double x_center, double y_center)
{
	fractol->range_r = fractol->max_r - fractol->min_r;
	fractol->range_i = fractol->max_i - fractol->min_i;
	fractol->new_range_r = fractol->range_r / ZOOM_FACTOR;
	fractol->new_range_i = fractol->range_i / ZOOM_FACTOR;
	x_center = fractol->min_r + fractol->range_r * (fractol->tmp_x / WIDTH);
	y_center = fractol->min_i + fractol->range_i * (fractol->tmp_y / HEIGHT);
	fractol->max_r = x_center + fractol->new_range_r / 2;
	fractol->min_r = x_center - fractol->new_range_r / 2;
	fractol->max_i = y_center + fractol->new_range_i / 2;
	fractol->min_i = y_center - fractol->new_range_i / 2;
	fractol->i = 0;
	draw_fractal(fractol);
}

void	out(t_fractal *fractol, double x_center, double y_center)
{
	fractol->range_r = fractol->max_r - fractol->min_r;
	fractol->range_i = fractol->max_i - fractol->min_i;
	fractol->new_range_r = fractol->range_r * ZOOM_FACTOR;
	fractol->new_range_i = fractol->range_i * ZOOM_FACTOR;
	x_center = fractol->min_r + fractol->range_r * (fractol->tmp_x / WIDTH);
	y_center = fractol->min_i + fractol->range_i * (fractol->tmp_y / HEIGHT);
	fractol->max_r = x_center + fractol->new_range_r / 2;
	fractol->min_r = x_center - fractol->new_range_r / 2;
	fractol->max_i = y_center + fractol->new_range_i / 2;
	fractol->min_i = y_center - fractol->new_range_i / 2;
	fractol->i = 0;
	draw_fractal(fractol);
}
