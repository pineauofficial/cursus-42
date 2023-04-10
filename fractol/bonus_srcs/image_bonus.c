/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:41:07 by pineau            #+#    #+#             */
/*   Updated: 2023/04/09 16:41:39 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	*new_image(t_fractal *fractol)
{
	fractol->img->img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img->img_ptr)
	{
		free(fractol->img);
		return (NULL);
	}
	fractol->img->addr = mlx_get_data_addr(fractol->img->img_ptr,
			&fractol->img->bits_per_pixel, &fractol->img->line_length,
			&fractol->img->endian);
	return (fractol->img);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_fractal *fractol)
{
	int	color_pix;

	fractol->y = 0;
	while (fractol->y < HEIGHT)
	{
		fractol->x = 0;
		while (fractol->x < WIDTH)
		{
			if (fractals(fractol) == 1)
				put_pixel(fractol->img, fractol->x, fractol->y, 0x000000);
			else
			{
				color_pix = get_color(fractol->i, fractol->color);
				put_pixel(fractol->img, fractol->x, fractol->y, color_pix);
			}
			fractol->x = fractol->x + 1;
		}
		fractol->y = fractol->y + 1;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img->img_ptr, 0, 0);
}
