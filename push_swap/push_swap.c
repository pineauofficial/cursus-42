/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:21:28 by pineau            #+#    #+#             */
/*   Updated: 2023/02/08 14:36:06 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Fonction pour créer un nouveau noeud dans la liste chaînée
void	*make_nod(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

//Fonction pour ajouter un noeud a la fin de liste chaînée
void	add_nod(t_list *head, t_list *new)
{
	t_list	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

//Fonction pour afficher les valeurs dans la liste chaînée
// void	display_list(t_list *head)
// {
// 	t_list	*current;

// 	current = head;
// 	if (head == NULL)
// 		write(1, "mescouilles\n", 12);
// 	while (current != NULL)
// 	{
// 		printf("%d ", current->nbr);
// 		current = current->next;
// 	}
// 	printf("\n");
// }

//Fonction pour libérer la mémoire occupée par la liste chaînée
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

void	all(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		a;
	int		*tab;

	a = 1;
	head_a = make_nod(ft_atoi(argv[a]));
	while (++a < argc)
		add_nod(head_a, make_nod(ft_atoi(argv[a])));
	head_b = NULL;
	tab = tableau(argc, argv);
	algo_part1(&head_a, &head_b, tab, argc - 1);
	algo_part2(&head_a, &head_b, tab, argc - 1);
	algo_part3(&head_a, &head_b);
	final_rotate(&head_a);
	free_list(head_b);
	free_list(head_a);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (check_all(argc, argv) != 1)
		all(argc, argv);
}
