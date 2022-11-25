/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:53:57 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 16:40:48 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*a;
	int		b;

	b = 0;
	a = malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[b] != '\0')
	{
		a[b] = s[b];
		b++;
	}
	a[b] = '\0';
	return (a);
}

// int main()
// {
// 	printf("%s\n", ft_strdup("testtest"));
// 	printf("%s", strdup("testtest"));
// 	return 0;
// }
