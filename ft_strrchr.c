/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:16:03 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:14:27 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	if (c >= 256)
		c = c - 256;
	if (s == NULL)
		return (NULL);
	a = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[a]);
	while (--a >= 0)
		if (s[a] == c)
			return ((char *)(s + a));
	return (NULL);
}
/*
int main( void )
  {
     printf ( "1. %s\n", ft_strrchr ( "hello world" , 108 ));
     printf ( "2. %s", ft_strrchr ( "Can a digit be found?" , 50 ));
     return ( 0 );
  }
*/
