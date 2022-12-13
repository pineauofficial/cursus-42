/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_part_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:07:22 by pineau            #+#    #+#             */
/*   Updated: 2022/12/13 14:26:37 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Intervertit les 2 premiers éléments au sommet de la pile a
void	swap_a(t_list *head, int n)
{
	int	swap;

	if (n < 2)
		return ;
	swap = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = swap;
}

//Intervertit les 2 premiers éléments au sommet de la pile b
void	swap_b(t_list *head, int n)
{
	int	swap;

	if (n < 2)
		return ;
	swap = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = swap;
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
	t_list	*new;

	current = *head_b;
	if (current == NULL)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(current);
		return ;
	}
	new->nbr = current->nbr;
	new->next = *head_a;
	*head_a = new;
	if (current->next != NULL)
	{
		*head_b = current->next;
		free (current);
	}
	else
		(*head_b)->next = NULL;
}

//Prend le premier élément au sommet de a et le met sur b
void	push_b(t_list **head_a, t_list **head_b)
{
	t_list	*current;
	t_list	*new;

	current = *head_a;
	if (current == NULL)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(current);
		return ;
	}
	new->nbr = current->nbr;
	new->next = *head_b;
	*head_b = new;
	if (current->next != NULL)
	{
		*head_a = current->next;
		free (current);
	}
	else
		(*head_a)->next = NULL;
}
