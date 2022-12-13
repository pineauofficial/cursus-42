/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:21:28 by pineau            #+#    #+#             */
/*   Updated: 2022/12/13 15:22:30 by pineau           ###   ########.fr       */
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
void	display_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\n");
}

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

//Fonction pour compter le nombre de noeud de la liste chaînée
int	count_nod(t_list *head)
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

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		nbr;
	int		i;
	int		signe;

	i = 0;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signe = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe = -signe;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr * signe);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		a;
	int		n_a;
	int		n_b;

	if (argc < 2)
		return (0);
	//----liste a----
	a = 1;
	head_a = make_nod(ft_atoi(argv[a]));
	while (++a < argc)
		add_nod(head_a, make_nod(ft_atoi(argv[a])));
	n_a = count_nod(head_a);
	display_list(head_a);
	//----liste b----
	a = 1;
	head_b = make_nod(ft_atoi(argv[a]));
	while (++a < argc)
		add_nod(head_b, make_nod(ft_atoi(argv[a])));
	n_b = count_nod(head_b);
	display_list(head_b);

	//----testes----
	swap_a(head_a, n_a);
	swap_b(head_b, n_b);
	swap_swap(head_a, head_b, n_a, n_b);
	push_a(&head_b, &head_a);
	push_b(&head_a, &head_b);
	rotate_a(&head_a);
	rotate_b(&head_b);
	rotate_rotate(&head_a, &head_b);
	reverse_rotate_a(&head_a);
	reverse_rotate_b(&head_b);
	reverse_rotate_reverse_rotate(&head_a, &head_b);
	printf("liste a : ");
	display_list(head_a);
	printf("liste b : ");
	display_list(head_b);
	//----fin testes----

	free_list(head_b);
	free_list(head_a);
}
