/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:26:53 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:06:14 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*permet de copier un bloc de mémoire spécifié par le paramètre source, 
et dont la taille est spécifiée via le paramètre size, 
dans un nouvel emplacement désigné par le paramètre destination. 

to : spécifie l'adresse du bloc mémoire devant recevoir les données à copier.
from : permet de définir l'adresse du bloc de mémoire à dupliquer.
size : indique le nombre d'octets à dupliquer. */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr1;
	const char	*ptr2;

	ptr1 = (char *)dest;
	ptr2 = (const char *)src;
	while (n > 0)
	{
		*ptr1 = *ptr2;
		n--;
		ptr1++;
		ptr2++;
	}
	return (dest);
}
