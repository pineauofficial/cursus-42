/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_part_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:08:35 by pineau            #+#    #+#             */
/*   Updated: 2022/12/12 13:16:11 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

//Décale d’une position vers le bas tous les élements de la pile b
void	reverse_rotate_a(t_list **head_a)
{
}
