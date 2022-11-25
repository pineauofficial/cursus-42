/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:15:39 by pineau            #+#    #+#             */
/*   Updated: 2022/11/18 10:39:10 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	is_positif(const char *str)
// {
	// int	a;
	// int	b;
// 
	// a = 0;
	// b = 0;
	// while (str[a] < '0' || str[a] > '9')
	// {
		// if (str[a] == '-')
			// b++;
		// a++;
	// }
	// b = b % 2;
	// if (b == 0)
		// return (0);
	// else
		// return (1);
// }
// 
// int	ft_atoi(const char *str)
// {
	// int	a;
	// int	b;
// 
	// a = 0;
	// b = 0;
	// while ((str[a] >= 9 && str[a] <= 13) || (str[a] == 32))
		// a++;
	// if (str[a] == 45 || str[a] == 43)
		// a++;
	// while (str[a] >= '0' && str[a] <= '9')
	// {
		// b = b * 10 + (str[a] - '0');
		// a++;
	// }	
	// if (is_positif(str) == 1)
		// b = b * (-1);
	// if (b > 0 || b < 0)
		// return (b);
	// else
		// return (0);
// }

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		nbr;
	int		i;
	int		signe;

	i = 0;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signe = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe = -signe;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr * signe);
}

// int main()
// {
//     char str[]={" -+++-123456"};
//     printf("%d", ft_atoi(str));
// }
