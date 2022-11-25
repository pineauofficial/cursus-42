/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:30:35 by pineau            #+#    #+#             */
/*   Updated: 2022/11/16 18:03:17 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	a;
	int				size;

	a = 0;
	size = ft_strlen(s);
	str = malloc(sizeof(char) * size + 1);
	if (!s || !f || !str)
		return (NULL);
	while (size > 0)
	{
		str[a] = f(a, s[a]);
		size--;
		a++;
	}
	str[a] = '\0';
	return (str);
}
