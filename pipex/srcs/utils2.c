/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:43:57 by pineau            #+#    #+#             */
/*   Updated: 2023/04/26 15:36:05 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

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

void	ft_putstr(char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		write(2, &s[a], 1);
		a++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] == s2[a]) && s1[a] != '\0' && s2[a] != '\0')
		a++;
	return (s1[a] - s2[a]);
}

void	error(int i, char **cmd)
{
	if (i == 1)
		perror("fork");
	else if (i == 2)
	{
		free_all(cmd);
		perror("execve");
	}
	else if (i == 3)
		perror("open");
	else if (i == 4)
		perror("pipe");
}
