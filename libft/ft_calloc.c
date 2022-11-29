/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:12:31 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:43:22 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Cette fonction alloue un bloc de mémoire en initialisant tous ces octets à 0

count: spécifie le nombre d'éléments à réserver dans le bloc de mémoire.
size : permet de fixer la taille (en nombre d'octets) d'un élément. */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && size && (2147483647 / nmemb) < size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
