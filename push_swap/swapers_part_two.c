/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_part_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:08:35 by pineau            #+#    #+#             */
/*   Updated: 2023/02/08 14:08:58 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Décale d’une position vers le haut tous les élements de la pile a
void	rotate_a(t_list **head_a)
{
	t_list	*current;
	t_list	*tmp;

	current = *head_a;
	tmp = *head_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = current;
	*head_a = current->next;
	current->next = NULL;
	write(1, "ra\n", 3);
}

//Décale d’une position vers le haut tous les élements de la pile b
void	rotate_b(t_list **head_b)
{
	t_list	*current;
	t_list	*tmp;

	current = *head_b;
	tmp = *head_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = current;
	*head_b = current->next;
	current->next = NULL;
	write(1, "rb\n", 3);
}

//ra et rb en même temps
void	rotate_rotate(t_list **head_a, t_list **head_b)
{
	rotate_a(head_a);
	rotate_b(head_b);
}

//Décale d’une position vers le bas tous les élements de la pile a
void	reverse_rotate_a(t_list **head_a)
{	
	t_list	*current;
	t_list	*second_last;

	second_last = NULL;
	current = *head_a;
	while (current && current->next)
	{
		second_last = current;
		current = current->next;
	}
	if (!second_last)
		return ;
	second_last->next = NULL;
	current->next = *head_a;
	*head_a = current;
	write(1, "rra\n", 4);
}

//Décale d’une position vers le bas tous les élements de la pile a
void	reverse_rotate_b(t_list **head_b)
{
	t_list	*current;
	t_list	*second_last;

	second_last = NULL;
	current = *head_b;
	while (current && current->next)
	{
		second_last = current;
		current = current->next;
	}
	if (!second_last)
		return ;
	second_last->next = NULL;
	current->next = *head_b;
	*head_b = current;
	write(1, "rrb\n", 4);
}
