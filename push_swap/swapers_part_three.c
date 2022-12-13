/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_part_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:19:10 by pineau            #+#    #+#             */
/*   Updated: 2022/12/13 12:26:21 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_reverse_rotate(t_list **head_a, t_list **head_b)
{
	reverse_rotate_a(head_a);
	reverse_rotate_b(head_b);
}
