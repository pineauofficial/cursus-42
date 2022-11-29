/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:11:19 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:42:50 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Alloue (avec malloc(3)) et retourne une chaîne de
caractères issue de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’len’.*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		a;

	a = 0;
	if ((size_t)start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * (1));
		*str = '\0';
		return (str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[a] = s[start];
		a++;
		start++;
		len--;
	}
	str[a] = '\0';
	return (str);
}
