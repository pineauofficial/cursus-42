/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:07 by pineau            #+#    #+#             */
/*   Updated: 2022/11/21 18:38:30 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Itère sur la liste ’lst’ et applique la fonction
’f’ au contenu chaque élément.*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
