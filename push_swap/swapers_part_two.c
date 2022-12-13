/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_part_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:08:35 by pineau            #+#    #+#             */
/*   Updated: 2022/12/13 15:24:48 by pineau           ###   ########.fr       */
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
	t_list	*new;
	t_list	*second_last;
	int		a;

	a = 0;
	second_last = *head_a;
	current = *head_a;
	while (current->next)
	{
		current = current->next;
		a++;
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->nbr = current->nbr;
	new->next = *head_a;
	*head_a = new;
	while (a-- > 1)
		second_last = second_last->next;
	second_last->next = NULL;
	free(current);
}

void	reverse_rotate_b(t_list **head_b)
{
	t_list	*current;
	t_list	*new;
	t_list	*second_last;
	int		a;

	a = 0;
	second_last = *head_b;
	current = *head_b;
	while (current->next)
	{
		current = current->next;
		a++;
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->nbr = current->nbr;
	new->next = *head_b;
	*head_b = new;
	while (a-- > 1)
		second_last = second_last->next;
	second_last->next = NULL;
	free(current);
}
