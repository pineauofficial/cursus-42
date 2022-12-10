/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_maker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:36 by pineau            #+#    #+#             */
/*   Updated: 2022/12/10 18:18:37 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Définition du type "list"
typedef struct t_list {
	int				nbr;
	struct t_list	*next;
}	t_list;

//Fonction pour créer un nouveau noeud dans la liste chaînée
t_list	*make_nod(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
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
	{
		current = current->next;
	}
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

int	main(int argc, char **argv)
{
	t_list	*head;
	int		a;
	int		n;

	if (argc < 2)
		return (0);
	a = 1;
	head = make_nod(ft_atoi(argv[a]));
	while (++a < argc)
		add_nod(head, make_nod(ft_atoi(argv[a])));
	display_list(head);
	n = count_nod(head);
	swap_a(head, n);
	display_list(head);
	free_list(head);
	return (0);
}
