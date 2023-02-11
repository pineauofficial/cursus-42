/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:00 by pineau            #+#    #+#             */
/*   Updated: 2023/02/11 14:37:26 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction qui check si il y a des doubles
int	check_double(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
			{
				return (1);
			}
			++j;
		}
		++i;
	}
	free(tab);
	return (0);
}

//fonction qui check si la liste est deja trier// 0 = bien
int	check_sort(int argc, char **argv)
{
	int	i;
	int	*tab;
	int	check;

	i = -1;
	check = 1;
	tab = malloc(sizeof(int) * argc - 1);
	if (!tab)
		return (0);
	while (++i < argc - 1)
		tab[i] = ft_atoi(argv[i + 1]);
	i = 0;
	while (argc - 2)
	{
		if (tab[i] > tab[i + 1])
			check = 0;
		argc--;
		i++;
	}
	free(tab);
	return (check);
}

//a finir
int	check(int check)
{
	if (check == 1)
		write(1, "Error\n", 6);
	if (check == 2)
		return (0);
	return (0);
}

int	check_all(int argc, char **argv)
{
	if (check_double(tableau(argc, argv), argc - 1) == 1)
	{
		check(1);
		return (1);
	}
	if (check_numbers(argc, argv) == 1)
	{
		check(1);
		return (1);
	}
	if (check_sort(argc, argv) == 1)
	{
		check(2);
		return (1);
	}
	return (0);
}
