/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:43:57 by pineau            #+#    #+#             */
/*   Updated: 2023/05/11 16:38:21 by pineau           ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] == s2[a]) && s1[a] != '\0' && s2[a] != '\0')
		a++;
	return (s1[a] - s2[a]);
}

void	error(int i, char **cmd, char *argv)
{
	if (i == 1)
	{
		free_all(cmd);
		free(cmd);
		perror("fork");
		exit(0);
	}
	else if (i == 2)
	{
		free_all(cmd);
		free(cmd);
		perror("execve");
	}
	else if (i == 3)
		perror("open");
	else if (i == 4)
		perror("pipe");
	else if (i == 5)
	{
		write(2, "zsh: command not found: ", 24);
		write(2, argv, ft_strlen(argv));
		write(2, "\n", 1);
	}
}

void	end_process(int i, int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (i > 2)
	{
		wait(NULL);
		i--;
	}
}
