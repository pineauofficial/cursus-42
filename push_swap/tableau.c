/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:23:50 by pineau            #+#    #+#             */
/*   Updated: 2023/02/07 18:15:58 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*malloc_tab(int argc)
{
	int	*tab;

	tab = malloc(sizeof(int) * argc - 1);
	if (!tab)
		return (NULL);
	return (tab);
}

int	*tableau(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	j;
	int	swap;

	i = -1;
	tab = malloc_tab(argc);
	while (++i < argc - 1)
		tab[i] = ft_atoi(argv[i + 1]);
	i = -1;
	while (++i != argc - 1)
	{
		j = i + 1;
		while (j != argc - 1)
		{
			if (tab[i] > tab[j])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
	}
	return (tab);
}

int	q(int *tab, int mode, int len)
{
	int	q;

	if (mode == 1)
		q = len / 4;
	if (mode == 2)
		q = len / 2;
	if (mode == 3)
		q = len / 4 * 3;
	q = tab[q];
	return (q);
}
