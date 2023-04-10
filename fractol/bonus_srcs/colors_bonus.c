/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:40:39 by pineau            #+#    #+#             */
/*   Updated: 2023/04/09 16:40:42 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	def_colors(t_colors *color)
{
	color->start_red = color->start_red + 10;
	if (color->start_red > 255)
		color->start_red = 0;
	color->start_green = color->start_green + 20;
	if (color->start_green > 255)
		color->start_green = 0;
	color->start_blue = color->start_blue + 30;
	if (color->start_blue > 255)
		color->start_blue = 0;
	color->end_red = color->end_red + 40;
	if (color->end_red > 255)
		color->end_red = 0;
	color->end_green = color->end_green + 50;
	if (color->end_green > 255)
		color->end_green = 0;
	color->end_blue = color->end_blue + 60;
	if (color->end_blue > 255)
		color->end_blue = 0;
}

int	get_color(int i, t_colors *color)
{
	double	t;

	t = (double)i / 15;
	color->red = (int)((1 - t) * color->start_red + t * color->end_red);
	color->green = (int)((1 - t) * color->start_green + t * color->end_green);
	color->blue = (int)((1 - t) * color->start_blue + t * color->end_blue);
	return (color->red << 16 | color->green << 8 | color->blue);
}
