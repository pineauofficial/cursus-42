/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:25:43 by pineau            #+#    #+#             */
/*   Updated: 2023/02/11 14:50:40 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sizestr(int n)
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

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] == s2[a]) && s1[a] != '\0' && s2[a] != '\0')
		a++;
	return (s1[a] - s2[a]);
}

int	ft_ato2(const char *nptr)
{
	char				*str;
	long long int		nbr;
	int					i;
	int					signe;

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

int	check_numbers(int argc, char **argv)
{
	char	*tmp;
	int		i;

	i = 1;
	argc = argc - 1;
	while (argc)
	{
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!tmp)
			return (0);
		if (ft_ato2(argv[i]) > 2147483647 || ft_ato2(argv[i]) < -2147483647 - 1)
		{
			free(tmp);
			return (1);
		}
		if (ft_strcmp(tmp, argv[i]) != 0)
		{
			free(tmp);
			return (1);
		}
		i++;
		argc--;
		free(tmp);
	}
	return (0);
}
