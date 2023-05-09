/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:38:39 by pineau            #+#    #+#             */
/*   Updated: 2023/05/09 19:12:40 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *pipe_fd, char **argv, char **env, int i)
{
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		error(4, NULL);
	pid = fork();
	if (pid == -1)
		error(1, NULL);
	if (pid == 0)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execute(argv, env, i);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
	}
}

void	execute(char **argv, char **env, int i)
{
	char	**cmd;
	char	*str;

	cmd = ft_split(argv[i], ' ');
	str = make_path(env, argv, i);
	if (str == NULL)
	{
		free_all(cmd);
		return ;
	}
	if (execve(str, cmd, env) == -1)
		error(2, cmd);
}

void	last_exec(char **env, char **argv, int argc)
{
	pid_t	pid;
	char	**cmd;
	char	*str;

	pid = fork();
	if (pid == 0)
	{
		cmd = ft_split(argv[argc -2], ' ');
		str = make_path(env, argv, argc -2);
		if (str == NULL)
		{
			free_all(cmd);
			return ;
		}
		if (execve(str, cmd, env) == -1)
			error(2, cmd);
	}
	else if (pid == -1)
	{
		exit(0);
		error(1, NULL);
	}
	else
		waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 6)
		return (0);
	if (argc == 6 && ft_strcmp(argv[1], "here_doc") == 0)
	{
		here_doc(argv, env, argc);
		return (0);
	}
	process(argc, argv, env);
}

void	process(int argc, char **argv, char **env)
{
	int		fd;
	int		i;
	int		pipe_fd[2];

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		error(3, NULL);
	dup2(fd, 0);
	close(fd);
	i = 1;
	while (++i < argc -2)
		child(pipe_fd, argv, env, i);
	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error(3, NULL);
	dup2(fd, 1);
	if (ft_strcmp(argv[1], "/dev/stdin") == 0)
		dup2(pipe_fd[0], 0);
	close(fd);
	last_exec(env, argv, argc);
	end_process(i, pipe_fd);
}

/*
-----TESTES-----
./pipex_bonus /dev/stdin "joebfubf" "ls" "wc -l" file2
./pipex_bonus file "cat" "ls" file2
./pipex_bonus /dev/stdin "cat" "ls" /dev/stdout
./pipex_bonus file cat file2
*/