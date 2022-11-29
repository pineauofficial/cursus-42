/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:59:44 by pineau            #+#    #+#             */
/*   Updated: 2022/11/18 10:13:24 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	a;

	a = nb;
	if (nb < 0)
	{
		a = -nb;
		ft_putchar_fd('-', fd);
	}
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		a %= 10;
	}
	ft_putchar_fd('0' + a, fd);
}
