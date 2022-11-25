/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:24:11 by pineau            #+#    #+#             */
/*   Updated: 2022/11/16 17:59:29 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[a] != '\0')
		str[b++] = s1[a++];
	a = 0;
	while (s2[a] != '\0')
		str[b++] = s2[a++];
	str[b] = '\0';
	return (str);
}
/*int main ()
{
	printf("%s", ft_strjoin("Bonjour", " Titouin"));
}*/