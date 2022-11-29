/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:37:06 by pineau            #+#    #+#             */
/*   Updated: 2022/11/29 15:41:22 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_x(int nbr, char *base, int *size)
{
	unsigned int	a;
	unsigned int	b;

	b = ft_strlen(base);
	a = nbr;
	if (a >= b)
		ft_putnbr_x(a / b, base, size);
	ft_putchar(base[a % b]);
	*size += 1;
}
