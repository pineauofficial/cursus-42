/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:38:39 by pineau            #+#    #+#             */
/*   Updated: 2023/05/03 14:52:12 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char **argv, int *pipe_fd, char **env)
{
	int		fd;
	char	**cmd;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		fd = open(argv[1], O_RDONLY, 0777);
		if (fd == -1)
			error(3, NULL);
		dup2(fd, 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		close(fd);
		cmd = ft_split(argv[2], ' ');
		if (execve(make_path(env, argv, 2), cmd, env) == -1)
			error(2, cmd);
	}
	else if (pid == -1)
	{
		exit(0);
		error(1, NULL);
	}
	else
		close(pipe_fd[1]);
}

void	child2(char **argv, int *pipe_fd, char **env)
{
	int		fd;
	char	**cmd;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		fd = open(argv[4], O_WRONLY | O_TRUNC |O_CREAT, 0777);
		if (fd == -1)
			error(3, NULL);
		dup2(fd, 1);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		close(fd);
		cmd = ft_split(argv[3], ' ');
		if (execve(make_path(env, argv, 3), cmd, env) == -1)
			error(2, cmd);
	}
	else if (pid == -1)
	{
		exit(0);
		error(1, NULL);
	}
	else
		close(pipe_fd[0]);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];

	if (argc != 5)
		return (0);
	if (pipe(pipe_fd) == -1)
	{
		error(4, NULL);
		return (0);
	}
	child1(argv, pipe_fd, env);
	child2(argv, pipe_fd, env);
	return (0);
}
