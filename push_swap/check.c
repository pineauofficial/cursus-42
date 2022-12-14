/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:53:25 by pineau            #+#    #+#             */
/*   Updated: 2022/12/14 21:24:29 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rajouter une ou des fonction qui check si c'est plus court de rotate vers le bas ou vers le haut

int	find_middle(t_list *head_a)
{
	int		current;
	int		smaller;
	int		bigger;
	t_list	*tmp;

	while (head_a)
	{
		current = head_a->nbr;
		smaller = 0;
		bigger = 0;
		tmp = head_a->next;
		while (tmp)
		{
			if (tmp->nbr < current)
				smaller++;
			else if (tmp->nbr > current)
				bigger++;
			tmp = tmp->next;
		}
		if (smaller == bigger || smaller - 1 == bigger || smaller + 1 == bigger)
			return (current);
		head_a = head_a->next;
	}
	return (0);
}

void	separate(t_list **head_a, t_list **head_b)
{
	int		middle;
	t_list	*curent;
	int		size;

	size = count_nod(head_a);
	current = *head_a;
	middle = find_middle(head_a);
	while (size)
	{
		if (current->nbr > middle)
		{
			push_b(head_a, head_b);
		}
		else
			rotate_a(head);
		size--;
	}
}

//Fonction pour trouver le plus grand nombre dans la liste a
int	find_bigger(t_list **head_a)
{
	int		result;
	t_list	*current;

	current = *head_a;
	result = current->nbr;
	while (current->next)
	{
		if (current->nbr > result)
			result = current->nbr;
		current = current->next;
	}
	return (result);
}

//Fonction pour passer sur b le plus grand nombre de la liste a
void	swap_bigger(t_list **head_a, t_list **head_b)
{
	int	size;
	int	bigger;

	bigger = find_bigger(head_a);
	size = count_nod(head_a);
	while ((*head_a)->nbr != bigger)
		rotate_a(head_a);
	push_b(head_a, head_b);
}

int	up_or_down(t_list **head, int nb)
{
	int		size;
	t_list	*current;
	int		a;

	a = 0;
	current = *head_a;
	size = count_nod(head);
	while (current->nbr != nb)
	{
		current = current->next;
		a++;
	}
	if (size - a >= size / 2)
		return (0); //rotate 
	else 
		return (1); //reverse rotate
}
