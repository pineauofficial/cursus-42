/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:53:22 by pineau            #+#    #+#             */
/*   Updated: 2022/11/16 17:59:46 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size > 0)
	{
		while (src[a] != '\0' && a < size - 1)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (ft_strlen(src));
}
/*int main()
{
	char dst[]="0123456789abcdef";
	char dst2[]="0123456789abcdef";
	char src[]="0123456789abcdef";
	printf("%ld\n", ft_strlcpy(dst, src, 10));
	printf("%ld - %s\n", strlcpy(dst2, src, 10), dst2);
	//-lbsd;
}*/