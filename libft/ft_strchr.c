/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:55 by pineau            #+#    #+#             */
/*   Updated: 2022/11/16 19:26:30 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	a;

	a = 0;
	if (c >= 256)
		c = c -256;
	if (str == NULL)
		return (NULL);
	while (str[a] != '\0' && str[a] != c)
		a++;
	if (str[a] == c)
		return ((char *)(str + a));
	return (NULL);
}
/*
int main( void )
  {
     printf ( "1. %s\n", ft_strchr ( "This is a test" , 'a' ));
     printf ( "2. %s", ft_strchr ( "Can a digit be found?" , 0 ));
     return ( 0 );
  }*/
