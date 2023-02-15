/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:08:11 by pineau            #+#    #+#             */
/*   Updated: 2023/02/15 15:30:52 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_fractal
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	void	*mlx;
	void	*win;
	int		*colors;
}	t_fractal;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

#endif