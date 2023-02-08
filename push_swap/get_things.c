/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:40:32 by pineau            #+#    #+#             */
/*   Updated: 2023/02/01 15:41:53 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *head)
{
	int		min;
	t_list	*current;

	min = head->nbr;
	current = head->next;
	while (current)
	{
		if (min > current->nbr)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

int	get_max(t_list *head)
{
	int		max;
	t_list	*current;

	max = head->nbr;
	current = head->next;
	while (current)
	{
		if (max < current->nbr)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

int	get_index(t_list *head, int elem)
{
	int		a;
	t_list	*current;

	a = 0;
	current = head;
	while (current)
	{
		if (current->nbr == elem)
			break ;
		current = current->next;
		a++;
	}
	return (a);
}

int	get_last_int(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp->nbr);
}

int	get_gbf(t_list *head, int elem)
{
	int		min;
	int		i;
	int		l;
	t_list	*tmp;

	min = get_min(head);
	if (elem > get_max(head) || elem < min)
		return (get_index(head, min));
	l = count2_nod(head);
	i = -1;
	tmp = head;
	if (get_last_int(head) < elem && elem < head->nbr)
		return (0);
	while (++i < l)
	{
		if (tmp->nbr < elem && elem < tmp->next->nbr)
			return (i + 1);
		tmp = tmp->next;
	}
	return (0);
}
