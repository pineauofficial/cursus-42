/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:34:52 by pineau            #+#    #+#             */
/*   Updated: 2023/02/08 14:08:32 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction qui trie 3 nombres sur a 
void	sort_three(t_list **head_a)
{
	if ((*head_a)->nbr > (*head_a)->next->nbr)
		swap_a((*head_a), count2_nod(*head_a));
	if ((*head_a)->next->nbr > (*head_a)->next->next->nbr)
		reverse_rotate_a(head_a);
	if ((*head_a)->nbr > (*head_a)->next->nbr)
		swap_a((*head_a), count2_nod(*head_a));
}

//pre tri sur b (entre q1 et q2)
void	algo_part1(t_list **head_a, t_list **head_b, int *t, int l)
{
	int		size;

	size = count2_nod(*head_a);
	while (inner(*head_a, q(t, 1, l), q(t, 3, l)) && size >= 8)
	{
		if ((*head_a)->nbr >= q(t, 2, l) && (*head_a)->nbr <= q(t, 3, l))
			push_b(head_a, head_b);
		else if ((*head_a)->nbr >= q(t, 1, l) && (*head_a)->nbr <= q(t, 2, l))
		{
			push_b(head_a, head_b);
			rotate_b(head_b);
		}
		else
			rotate_a(head_a);
	}
}

//pre tri sur b (le reste)
void	algo_part2(t_list **head_a, t_list **head_b, int *t, int l)
{
	int	size;

	size = count2_nod(*head_a);
	while (size > 3)
	{
		if ((*head_a)->nbr >= q(t, 2, l))
			push_b(head_a, head_b);
		else if ((*head_a)->nbr <= q(t, 2, l))
		{
			push_b(head_a, head_b);
			rotate_b(head_b);
		}
		size--;
	}
	sort_three(head_a);
	free(t);
}

//on repasse sur a en triant
void	algo_part3(t_list **head_a, t_list **head_b)
{
	int	b_move;
	int	size;

	size = count2_nod((*head_b));
	while (size)
	{
		b_move = get_best_move(*head_a, *head_b);
		insertion_sort(head_a, head_b, b_move);
		size--;
	}
}

//on rotate pour bien mettre le debut au debut
void	final_rotate(t_list **head_a)
{
	t_list	*current;
	int		i;

	i = 0;
	current = *head_a;
	while (current->nbr != get_min(*head_a))
	{
		current = current->next;
		i++;
	}
	while ((*head_a)->nbr != get_min(*head_a))
	{
		if (i < count2_nod(*head_a) / 2)
			rotate_a(head_a);
		else
			reverse_rotate_a(head_a);
	}
}
