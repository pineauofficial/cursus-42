/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:57:57 by pineau            #+#    #+#             */
/*   Updated: 2023/02/12 14:52:06 by pineau           ###   ########.fr       */
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
int		count2_nod(t_list *head);
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
int		find_middle(t_list **head_a);
int		main(int argc, char **argv);
void	algo_part1(t_list **head_a, t_list **head_b, int *t, int l);
int		quartile(int *tab, int mode);
int		ft_strlen(int *tab);
int		*tableau(int argc, char **argv);
int		ft_strlen(int *tab);
int		q(int *tab, int mode, int len);
int		get_min(t_list *head);
int		get_max(t_list *head);
int		get_index(t_list *head, int elem);
int		get_last_int(t_list *head);
int		get_gbf(t_list *head, int elem);
int		count_move(t_list *head_a, t_list *head_b, int elem);
int		get_best_move(t_list *head_a, t_list *head_b);
t_list	*rr_rra(t_list *head_a, int pos_a, int i);
void	insertion_sort(t_list **head_a, t_list **head_b, int b_move);
void	sort_three(t_list **head_a);
void	algo_part3(t_list **head_a, t_list **head_b);
int		inner(t_list *head, int q1, int q2);
void	final_rotate(t_list **head_a);
void	algo_part2(t_list **head_a, t_list **head_b, int *t, int l);
void	all(int argc, char **argv);
int		*malloc_tab(int argc);
int		sizestr(int n);
char	*ft_itoa(int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_ato2(const char *nptr);
int		check_all(int argc, char **argv);
int		check_numbers(int argc, char **argv);
int		check(int check);
int		check_sort(int argc, char **argv);
int		check_double(int *tab, int size);
int		*tableau_suite(int argc, int *tab);

#endif