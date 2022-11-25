/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:40:17 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:08:49 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Cette fonction permet de remplir une zone mémoire, identifiée par son 
adresse et sa taille, avec une valeur précise

block : spécifie l'adresse du bloc mémoire à ré-initialiser.
c : indique la valeur à utiliser pour remplir le bloc de mémoire.
size : indique le nombre d'octets à initialiser. */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}
