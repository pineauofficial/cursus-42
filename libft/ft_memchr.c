/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:14:46 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:02:27 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Recherche la première occurence d'une valeur typée int, mais 
interprétée en tant que char, dans un bloc de mémoire. 
nous devons aussi spécifier à la fonction la taille du bloc de mémoire

block : pointeur indiquant l'adresse du bloc mémoire à utiliser
c : le code numérique de l'octet à rechercher dans le bloc.
size : indique la taille du bloc de mémoire dans lequel opérer la recherche. */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (c >= 256)
		c = c - 256;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
