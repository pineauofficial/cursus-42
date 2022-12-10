/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_maker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:36 by pineau            #+#    #+#             */
/*   Updated: 2022/12/10 16:30:04 by pineau           ###   ########.fr       */
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
	t_list	*head;
	int		a;

	if (argc < 2)
		return (0);
	a = 1;
	head = make_nod(ft_atoi(argv[a]));
	while (++a < argc)
		add_nod(head, make_nod(ft_atoi(argv[a])));
	display_list(head);
	free_list(head);
	return (0);
}
