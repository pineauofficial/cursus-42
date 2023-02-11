/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:49:17 by pineau            #+#    #+#             */
/*   Updated: 2023/02/08 15:17:56 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rr_rra(t_list *head_a, int pos_a, int i)
{
	if (pos_a <= (count2_nod(head_a) / 2))
	{
		while (i <= pos_a - 1)
		{
			rotate_a(&head_a);
			i++;
		}
	}
	else
	{
		while (i < (count2_nod(head_a) - pos_a))
		{
			reverse_rotate_a(&head_a);
			i++;
		}
	}
	return (head_a);
}

//trouve ou est et ou doit aller le nombre puis rotate b jusqu'a lui
//puis appelle rr_rra pour rotate la pile a et le push dessus
void	insertion_sort(t_list **head_a, t_list **head_b, int b_move)
{
	int	pos_a;
	int	pos_b;

	pos_a = get_gbf(*head_a, b_move);
	pos_b = get_index(*head_b, b_move);
	while ((*head_b)->nbr != b_move)
	{
		if (pos_b <= (count2_nod(*head_b) / 2))
			rotate_b(head_b);
		else
			reverse_rotate_b(head_b);
	}
	*head_a = rr_rra((*head_a), pos_a, 0);
	push_a(head_b, head_a);
}

int	inner(t_list *head, int q1, int q2)
{
	t_list	*tmp;
	int		length;
	int		i;

	length = count2_nod(head);
	i = 0;
	tmp = head;
	while (i < length)
	{
		if (q1 <= tmp->nbr && tmp->nbr <= q2)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
