/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:34:52 by pineau            #+#    #+#             */
/*   Updated: 2022/12/21 18:54:04 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count2_nod(t_list *head)
{
	t_list	*current;
	int		a;

	a = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		a++;
	}
	return (a);
}

void	algo(t_list **head_a, t_list **head_b)
{
	int		middle;
	int		size;
	int		bigger;
	int		test;
	t_list	*current;

	current = *head_a;
	middle = find_middle(head_a);
	size = count2_nod(*head_a);
	//on fou la moite sur b
	while (size)
	{
		if ((*head_a)->nbr > middle)
			push_b(head_a, head_b);
		else
			rotate_a(head_a);
		size--;
	}
	size = count2_nod(*head_a);
	//on trie b et on met sur a
	while (size)
	{
		bigger = find_bigger(head_a);
		test = up_or_down(head_a, bigger);
		while ((*head_a)->nbr != bigger)
		{
			if (test == 1)
				rotate_a(head_a);
			else if(test == 0)
				reverse_rotate_a(head_a);
		}
		push_b(head_a, head_b);
		size--;
	}
	while (middle)
	{
		push_a(head_b, head_a);
		middle--;
	}
	size = count2_nod(*head_b);
	while (size)
	{
		bigger = find_smaller(head_b);
		while ((*head_b)->nbr != bigger)
			rotate_b(head_b);
		push_a(head_b, head_a);
		size--;
	}
}










