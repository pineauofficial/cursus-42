/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:40:12 by pineau            #+#    #+#             */
/*   Updated: 2023/04/09 16:40:15 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_down(t_fractal *fractol)
{
	fractol->min_i = fractol->min_i + 0.1;
	fractol->max_i = fractol->max_i + 0.1;
	draw_fractal(fractol);
}

void	key_up(t_fractal *fractol)
{
	fractol->min_i = fractol->min_i - 0.1;
	fractol->max_i = fractol->max_i - 0.1;
	draw_fractal(fractol);
}

void	key_right(t_fractal *fractol)
{
	fractol->min_r = fractol->min_r + 0.1;
	fractol->max_r = fractol->max_r + 0.1;
	draw_fractal(fractol);
}

void	key_left(t_fractal *fractol)
{
	fractol->min_r = fractol->min_r - 0.1;
	fractol->max_r = fractol->max_r - 0.1;
	draw_fractal(fractol);
}
