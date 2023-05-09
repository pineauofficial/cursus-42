/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:22:13 by pineau            #+#    #+#             */
/*   Updated: 2023/05/08 14:05:48 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen2(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a] != '\n' && str[a] != '\0')
		a++;
	return (a);
}

int	ft_strlen3(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr(const char *str, char c)
{
	int	a;

	a = 0;
	if (str == NULL)
		return (NULL);
	while (str[a] != '\0' && str[a] != c)
		a++;
	if (str[a] == c)
		return ((char *)(str + a));
	return (NULL);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen3(s1) + ft_strlen3(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[a] != '\0')
		str[b++] = s1[a++];
	a = 0;
	while (s2[a] != '\0')
	{
		str[b++] = s2[a++];
	}
	str[b] = '\0';
	free(s1);
	return (str);
}
