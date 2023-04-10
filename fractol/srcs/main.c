/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:22:37 by pineau            #+#    #+#             */
/*   Updated: 2023/04/10 14:14:09 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	int	nums;

	if (argc < 2)
	{
		write(2, "Utilisez Mandelbrot, Julia\n", 27);
		return (0);
	}
	nums = which_fract(argv);
	if (nums == 1 && argc == 2)
		init(nums, argv);
	else if (nums == 2 && argc == 4 && check_julia(argv))
		init(nums, argv);
	else if (nums == 2 && (argc != 4 || check_julia(argv) == 0))
		write(2, "Pour Julia utilisez deux nombres entre -10 et 10\n", 49);
	else if (nums == 1 && argc != 2)
		write(2, "Utilisez Mandelbrot uniquement\n", 31);
	else
		write(1, "Utilisez Mandelbrot, Julia\n", 27);
	return (0);
}

void	init_data(t_fractal *fractol, t_colors *color, char **argv, int nums)
{
	fractol->num = nums;
	fractol->min_i = -2.0;
	fractol->min_r = -2.0;
	fractol->max_i = 2.0;
	fractol->max_r = 2.0;
	color->start_red = 50;
	color->start_green = 200;
	color->start_blue = 100;
	color->end_red = 200;
	color->end_green = 50;
	color->end_blue = 150;
	fractol->c_r = -0.7;
	fractol->c_i = 0.27;
	if (nums == 2)
	{
		fractol->c_r = 0.1 * (double)ft_atoi(argv[2]);
		fractol->c_i = 0.1 * (double)ft_atoi(argv[3]);
	}
}

void	init(int nums, char **argv)
{
	t_fractal	*fractol;

	fractol = malloc(sizeof(t_fractal));
	if (!fractol)
		return ;
	fractol->img = malloc(sizeof(t_img));
	if (!fractol->img)
	{
		free(fractol);
		return ;
	}
	fractol->color = malloc(sizeof(t_colors));
	if (!fractol->color)
	{
		free(fractol->img);
		free(fractol);
		return ;
	}
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, NAME);
	fractol->img = new_image(fractol);
	init_data(fractol, fractol->color, argv, nums);
	draw_fractal(fractol);
	init_hook(fractol);
	end(fractol);
}

void	end(t_fractal *fractol)
{
	mlx_loop_end(fractol->mlx);
	mlx_destroy_image(fractol->mlx, fractol->img->img_ptr);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->img);
	free(fractol->color);
	free(fractol->mlx);
	free(fractol);
}
