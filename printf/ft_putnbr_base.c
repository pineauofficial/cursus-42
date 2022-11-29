/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:56:21 by pineau            #+#    #+#             */
/*   Updated: 2022/11/29 15:30:52 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

void	ft_putnbr_base(int nbr, char *base, int *size)
{
	unsigned int	a;
	unsigned int	b;

	b = ft_strlen(base);
	if (nbr < 0)
	{
		a = -nbr;
		ft_putchar('-');
		*size += 1;
	}
	else
		a = nbr;
	if (a >= b)
		ft_putnbr_base(a / b, base, size);
	ft_putchar(base[a % b]);
	*size += 1;
}
