/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:36:56 by pineau            #+#    #+#             */
/*   Updated: 2022/11/21 20:09:28 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Libère la mémoire de l’élément passé en argument en
utilisant la fonction ’del’ puis avec free(3). La
mémoire de ’next’ ne doit pas être free.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
	else
		return ;
}
