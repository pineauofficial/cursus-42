/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:53:58 by pineau            #+#    #+#             */
/*   Updated: 2023/02/22 20:55:02 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "key_code.h"

void	move_fractal_left(t_fractal *fractal)
{
	fractal->min_re -= MOVE_FACTOR / fractal->zoom;
	fractal->max_re -= MOVE_FACTOR / fractal->zoom;
}

void	move_fractal_right(t_fractal *fractal)
{
	fractal->min_re += MOVE_FACTOR / fractal->zoom;
	fractal->max_re += MOVE_FACTOR / fractal->zoom;
}

void	move_fractal_up(t_fractal *fractal)
{
	fractal->min_im += MOVE_FACTOR / fractal->zoom;
	fractal->max_im += MOVE_FACTOR / fractal->zoom;
}

void	move_fractal_down(t_fractal *fractal)
{
	fractal->min_im -= MOVE_FACTOR / fractal->zoom;
	fractal->max_im -= MOVE_FACTOR / fractal->zoom;
}
