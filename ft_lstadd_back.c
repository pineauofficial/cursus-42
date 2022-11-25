/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:31:11 by pineau            #+#    #+#             */
/*   Updated: 2022/11/21 18:37:07 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Ajoute l’élément ’new’ à la fin de la liste.

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (lst && *lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (lst)
		*lst = new;
}
