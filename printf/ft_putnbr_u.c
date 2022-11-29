/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:38:24 by pineau            #+#    #+#             */
/*   Updated: 2022/11/29 15:33:16 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nbr, char *base, int *size)
{
	unsigned int	a;
	unsigned int	b;

	b = ft_strlen(base);
	a = nbr;
	if (a >= b)
		ft_putnbr_u(a / b, base, size);
	ft_putchar(base[a % b]);
	*size += 1;
}
