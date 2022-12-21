/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:57:57 by pineau            #+#    #+#             */
/*   Updated: 2022/12/19 15:52:16 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_list {
	int				nbr;
	struct t_list	*next;
}	t_list;

void	*make_nod(int nbr);
void	add_nod(t_list *head, t_list *new);
void	display_list(t_list *head);
void	free_list(t_list *head);
int		count_nod(t_list *head);
int		ft_atoi(const char *nptr);
void	swap_a(t_list *head, int n);
void	swap_b(t_list *head, int n);
void	swap_swap(t_list *head_a, t_list *head_b, int a, int b);
void	push_a(t_list **head_b, t_list **head_a);
void	push_b(t_list **head_a, t_list **head_b);
void	rotate_a(t_list **head_a);
void	rotate_b(t_list **head_b);
void	rotate_rotate(t_list **head_a, t_list **head_b);
void	reverse_rotate_a(t_list **head_a);
void	reverse_rotate_b(t_list **head_b);
void	reverse_rotate_reverse_rotate(t_list **head_a, t_list **head_b);
int		find_middle(t_list *head_a);
void	separate(t_list **head_a, t_list **head_b);
int		main(int argc, char **argv);
void	algo(t_list **head_a, t_list **head_b);
int		find_bigger(t_list **head_a);

#endif