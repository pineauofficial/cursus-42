/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:33:22 by pineau            #+#    #+#             */
/*   Updated: 2023/05/03 15:02:35 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		a;

	a = 0;
	if ((size_t)start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * (1));
		*str = '\0';
		return (str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[a] = s[start];
		a++;
		start++;
		len--;
	}
	str[a] = '\0';
	return (str);
}

char	*get_brut_path(char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=' && env[i][j])
			j++;
		tmp = ft_substr(env[i], 0, j);
		if (ft_strcmp(tmp, "PATH") == 0)
		{
			free(tmp);
			return (env[i] + j + 1);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char	**get_paths(char **env)
{
	char	*brut_path;
	char	**all_path;

	brut_path = get_brut_path(env);
	all_path = ft_split(brut_path, ':');
	return (all_path);
}

char	*make_path(char **env, char **argv, int i)
{
	char	**all_path;
	char	**cmd;
	char	*str;
	int		j;

	all_path = get_paths(env);
	cmd = ft_split(argv[i], ' ');
	if (cmd[0][0] == '/')
		return (cmd[0]);
	j = 0;
	while (all_path[j])
	{
		str = ft_strjoin(all_path[j], "/");
		str = ft_strjoin(str, cmd[0]);
		if (access(str, F_OK | X_OK) == 0)
			return (str);
		free(str);
		j++;
	}
	return (str);
}
