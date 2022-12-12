/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_maker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:36 by pineau            #+#    #+#             */
/*   Updated: 2022/12/12 14:35:29 by pineau           ###   ########.fr       */
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
void	*make_nod(int nbr)
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

//Décale d’une position vers le haut tous les élements de la pile a
void	rotate_a(t_list **head_a)
{
	t_list	*current;
	int		tmp;

	current = *head_a;
	tmp = current->nbr;
	if (current == NULL)
		return ;
	*head_a = current->next;
	while (current->next)
		current = current->next;
	add_nod(*head_a, make_nod(tmp));

}

//Décale d’une position vers le haut tous les élements de la pile b
void	rotate_b(t_list **head_b)
{
	t_list	*current;
	int		tmp;

	current = *head_b;
	tmp = current->nbr;
	if (current == NULL)
		return ;
	*head_b = current->next;
	while (current->next)
		current = current->next;
	add_nod(*head_b, make_nod(tmp));
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
	int		tmp;
	int		a;

	a = 0;
	second_last = *head_a;
	current = *head_a;
	while (current->next)
	{
		current = current->next;
		a++;
	}
	tmp = current->nbr;
	new = malloc(sizeof(t_list));
	new->nbr = current->nbr;
	new->next = *head_a;
	*head_a = new;
	while (a-- > 1)
		second_last = second_last->next;
	second_last->next = NULL;
	free(current);
}

//Décale d’une position vers le bas tous les élements de la pile b
void	reverse_rotate_b(t_list **head_b)
{
	t_list	*current;
	t_list	*new;
	t_list	*second_last;
	int		tmp;
	int		a;

	a = 0;
	second_last = *head_b;
	current = *head_b;
	while (current->next)
	{
		current = current->next;
		a++;
	}
	tmp = current->nbr;
	new = malloc(sizeof(t_list));
	new->nbr = current->nbr;
	new->next = *head_b;
	*head_b = new;
	while (a-- > 1)
		second_last = second_last->next;
	second_last->next = NULL;
	free(current);
}

void	reverse_rotate_reverse_rotate(t_list **head_a, t_list **head_b)
{
	reverse_rotate_a(head_a);
	reverse_rotate_b(head_b);
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
