/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:20:44 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:03:58 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Cette fonction permet de comparer le contenu de deux blocs de mémoire 
spécifiés par les deux premiers paramètres de la fonction. 
Le troisième paramètre, size, permet de spécifier le nombre d'octets 
sur lequel comparer les deux blocs. 

a1 : spécifie l'adresse du premier bloc mémoire à comparer.
a2 : spécifie l'adresse du second bloc mémoire à comparer.
size : indique le nombre d'octets maximal à comparer. */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		n--;
		ptr1++;
		ptr2++;
	}
	return (0);
}
