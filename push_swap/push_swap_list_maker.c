/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_maker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:36 by pineau            #+#    #+#             */
/*   Updated: 2022/12/10 14:55:14 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Définition du type "list"
typedef struct t_list {
	int				nbr;
	struct t_list	*next;
}	t_list;

// Fonction pour créer un nouveau noeud dans la liste chaînée
t_list	*make_nod(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

// Fonction pour ajouter un noeud en fin de liste chaînée
void	add_nod(t_list *head, t_list *new)
{
	t_list	*current;

	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

// Fonction pour afficher les valeurs dans la liste chaînée
void	display_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->nbr);
		current = current->next;
	}
}

// Fonction pour libérer la mémoire occupée par la liste chaînée
void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	main(void)
{
	t_list	*head;

	head = make_nod(0);
	add_nod(head, make_nod(1));
	add_nod(head, make_nod(2));
	add_nod(head, make_nod(3));
	add_nod(head, make_nod(4));
	display_list(head);
	free_list(head);
	return (0);
}
