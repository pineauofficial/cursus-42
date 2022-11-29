/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:08:09 by pineau            #+#    #+#             */
/*   Updated: 2022/11/21 15:23:18 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Alloue (avec malloc(3)) et renvoie un nouvel
élément. La variable membre ’content’ est
initialisée à l’aide de la valeur du paramètre
’content’. La variable ’next’ est initialisée à
NULL.*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof (t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
