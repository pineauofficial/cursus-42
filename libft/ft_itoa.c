/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:56:53 by pineau            #+#    #+#             */
/*   Updated: 2022/11/18 10:08:26 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//transformer un chiffre en chaine de caractere

#include "libft.h"

static int	sizestr(int n)
{
	unsigned int	nb;
	int				a;

	nb = n;
	a = 1;
	if (n < 0)
	{
		a++;
		nb = nb * (-1);
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		a++;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	unsigned int		size;
	char				*str;
	unsigned int		nb;

	nb = n;
	size = sizestr(nb);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
	}
	str[size] = '\0';
	size = size - 1;
	while (nb >= 10)
	{
		str[size] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	str[size] = nb + '0';
	return (str);
}
