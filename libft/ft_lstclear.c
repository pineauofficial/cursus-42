/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:25:11 by pineau            #+#    #+#             */
/*   Updated: 2022/11/21 20:07:54 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Supprime et libère la mémoire de l’élément passé en
paramètre, et de tous les éléments qui suivent, à
l’aide de ’del’ et de free(3)
Enfin, le pointeur initial doit être mis à NULL.*/

#include "libft.h"

/*void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	while (lst && del)
	{
		del((*lst)->content);
		free(*lst);
		*lst = (*lst)->next;
	}
	*lst = NULL;
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free (*lst);
		*lst = tmp;
	}
}
