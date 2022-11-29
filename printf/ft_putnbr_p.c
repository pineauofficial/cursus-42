/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:06:40 by pineau            #+#    #+#             */
/*   Updated: 2022/11/29 15:46:01 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put(void *nbrb, char *base, int *size)
{
	unsigned long long int	a;
	unsigned long long int	b;
	unsigned long long int	nbr;

	nbr = (unsigned long long int)nbrb;
	b = ft_strlen(base);
	a = nbr;
	if (a >= b)
		ft_put((void *)(a / b), base, size);
	ft_putchar(base[a % b]);
	*size += 1;
}

void	ft_putnbr_p(void *nbrb, char *base, int *size)
{
	if (nbrb == 0)
	{
		ft_putstr("(nil)");
		*size += 5;
	}
	else
	{
		write(1, "0x", 2);
		*size += 2;
		ft_put(nbrb, base, size);
	}
}
