/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_part_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:07:22 by pineau            #+#    #+#             */
/*   Updated: 2022/12/19 16:13:55 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Intervertit les 2 premiers éléments au sommet de la pile a
void	swap_a(t_list *head, int n)
{
	int	swap;

	if (head == NULL)
		return ;
	if (n < 2)
		return ;
	swap = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = swap;
	write(1, "sa\n", 4);
}

//Intervertit les 2 premiers éléments au sommet de la pile b
void	swap_b(t_list *head, int n)
{
	int	swap;

	if (head == NULL)
		return ;
	if (n < 2)
		return ;
	swap = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = swap;
	write(1, "sb\n", 4);
}

//sa et sb en même temps
void	swap_swap(t_list *head_a, t_list *head_b, int a, int b)
{
	swap_a(head_a, a);
	swap_b(head_b, b);
}

//Prend le premier élément au sommet de b et le met sur a
void	push_a(t_list **head_b, t_list **head_a)
{
	t_list	*current;

	if (*head_b == NULL)
		return ;
	current = *head_b;
	*head_b = current->next;
	current->next = *head_a;
	*head_a = current;
	write(1, "pa\n", 4);
}

//Prend le premier élément au sommet de a et le met sur b
void	push_b(t_list **head_a, t_list **head_b)
{
	t_list	*current;

	if (*head_a == NULL)
		return ;
	current = *head_a;
	*head_a = current->next;
	current->next = *head_b;
	*head_b = current;
	write(1, "pb\n", 4);
}
