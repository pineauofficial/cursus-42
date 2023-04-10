/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:40:20 by pineau            #+#    #+#             */
/*   Updated: 2023/04/09 16:40:22 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] == s2[a]) && s1[a] != '\0' && s2[a] != '\0')
		a++;
	return (s1[a] - s2[a]);
}

int	which_fract(char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		return (1);
	if (ft_strcmp(argv[1], "Julia") == 0)
		return (2);
	if (ft_strcmp(argv[1], "BurningShip") == 0)
		return (3);
	return (0);
}
