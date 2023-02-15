/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:18:08 by pineau            #+#    #+#             */
/*   Updated: 2023/02/15 14:24:15 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

/*

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	handle_key_press(int keycode, void *mlx_ptr, void *win_ptr)
{
	if (keycode == 27)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		exit(0);
	}
	return (0);
}

typedef struct s_fractal
{
    int width;
    int height;
    double x_min;
    double x_max;
    double y_min;
    double y_max;
    int max_iterations;
    int (*algorithm)(double, double, int);
    void *mlx_ptr;
    void *win_ptr;
    int *colors;
} t_fractal;

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;
	int		tmp_i;
	int		tmp_j;

	i = 1;
	j = 1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	tmp_i = 1900;
	tmp_j = 1060;
	while (tmp_i > 0 && tmp_j > 0)
	{
		while (j > 0)
		{
			while (i > 0)
			{
				while (j < tmp_j)
				{
					while (i < tmp_i)
					{
						my_mlx_pixel_put(&img, i, j, create_trgb(100, 100, 100, 100));
						i++;
					}
					my_mlx_pixel_put(&img, i, j, create_trgb(50, 50, 50, 50));
					j++;
				}
				my_mlx_pixel_put(&img, i, j, create_trgb(10, 200, 8, 70));
				i--;
			}
			my_mlx_pixel_put(&img, i, j, create_trgb(250, 30, 250, 150));
			j--;
		}
		tmp_i = tmp_i - 20;
		tmp_j = tmp_j - 20;
		i = 1900 - tmp_i;
		j = 1060 - tmp_j;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	handle_key_press(14, mlx, mlx_win);
}

*/