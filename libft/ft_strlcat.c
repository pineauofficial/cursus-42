/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:16:50 by pineau            #+#    #+#             */
/*   Updated: 2022/11/16 15:27:29 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	len;

	a = 0;
	b = 0;
	len = 0;
	while (dst[a] && a < size)
		a++;
	while (src[b])
		b++;
	while (src[len] && (a + len + 1) < size)
	{
		dst[a + len] = src[len];
		len++;
	}
	if (a != size)
		dst[a + len] = '\0';
	return (a + b);
}
/*int main ()
{
	char dst[]="0123456789abcdef";
	char dst2[]="0123456789abcdef";
	char src[]="0123456789abcdef";
	printf("%ld\n", ft_strlcat(dst, src, 10));
	printf("%ld - %s\n", strlcat(dst2, src, 10), dst2);
	-lbsd;
}*/
