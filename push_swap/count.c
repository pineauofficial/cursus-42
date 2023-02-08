/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:12:20 by pineau            #+#    #+#             */
/*   Updated: 2023/02/01 15:42:28 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_move(t_list *head_a, t_list *head_b, int elem)
{
	int	count;
	int	index;

	index = get_index(head_b, elem);
	count = 1;
	if (index > 1 && index > (count2_nod(head_b) / 2))
		count += count2_nod(head_b) - index - 1;
	else if (index > 1 && index <= (count2_nod(head_b) / 2))
		count += index - 1;
	index = get_gbf(head_a, elem);
	if (index > 1 && index > (count2_nod(head_a) / 2))
		count += count2_nod(head_a) - index - 1;
	else if (index > 1 && index <= (count2_nod(head_a) / 2))
		count += index - 1;
	return (count);
}

int	get_best_move(t_list *head_a, t_list *head_b)
{
	int		best_move_count;
	int		best_move_elem;
	int		move_count;
	t_list	*tmp;

	best_move_elem = head_b->nbr;
	best_move_count = count_move(head_a, head_b, head_b->nbr);
	tmp = head_b->next;
	while (tmp)
	{
		move_count = count_move(head_a, head_b, tmp->nbr);
		if (move_count < best_move_count)
		{
			best_move_count = move_count;
			best_move_elem = tmp->nbr;
		}
		tmp = tmp->next;
	}
	return (best_move_elem);
}

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
