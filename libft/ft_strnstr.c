/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:19:07 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:17:04 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (s2[0] == '\0')
		return ((char *) s1);
	while (s1[a] != '\0' && len > a)
	{
		while (s1[a + b] == s2[b] && a + b < len)
		{	
			b++;
			if (s2[b] == '\0')
				return ((char *) &s1[a]);
		}
		b = 0;
		a++;
	}
	return (NULL);
}
