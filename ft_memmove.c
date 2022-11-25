/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:46:43 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:07:15 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Cette fonction permet de copier un bloc de mémoire spécifié par le paramètre 
source dans un nouvel emplacement désigné par le paramètre destination. 
Memmove accepte que les deux zones de mémoire puissent se chevaucher.

to : spécifie l'adresse du bloc mémoire devant recevoir les données à copier.
from : permet de définir l'adresse du bloc de mémoire à dupliquer.
size : indique le nombre d'octets à dupliquer. */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	int		a;

	a = 0;
	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	if (ptr1 > ptr2)
	{
		while (n > 0)
		{
			n--;
			ptr1[n] = ptr2[n];
		}
	}
	while (n > 0)
	{
		ptr1[a] = ptr2[a];
		a++;
		n--;
	}
	return (dest);
}
