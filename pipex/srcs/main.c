/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:38:39 by pineau            #+#    #+#             */
/*   Updated: 2023/05/11 17:17:29 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *pipe_fd, char **argv, char **env, int i)
{
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		error(4, NULL, NULL);
	pid = fork();
	if (pid == -1)
		error(1, NULL, NULL);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
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
		error(5, NULL, argv[i]);
		free_all(cmd);
		exit(0);
		return ;
	}
	if (execve(str, cmd, env) == -1)
		error(2, cmd, NULL);
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
			error(5, NULL, argv[argc -2]);
			free_all(cmd);
			exit(0);
			return ;
		}
		if (execve(str, cmd, env) == -1)
			error(2, cmd, NULL);
	}
	else if (pid == -1)
		error(1, NULL, NULL);
	else
		waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
		return (0);
	if (check_argv(argv, argc, 1))
		return (0);
	process(argc, argv, env);
	return (0);
}

void	process(int argc, char **argv, char **env)
{
	int		fd1;
	int		fd2;
	int		i;
	int		pipe_fd[2];

	fd1 = open(argv[1], O_RDONLY, 0777);
	if (fd1 == -1)
		error(3, NULL, NULL);
	i = 1;
	while (++i < argc -2)
		child(pipe_fd, argv, env, i);
	fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
		error(3, NULL, NULL);
	dup2(fd2, 1);
	last_exec(env, argv, argc);
	dup2(fd1, 0);
	dup2(fd2, 1);
	close(fd1);
	close(fd2);
	end_process(i, pipe_fd);
}

/*
-----TESTES-----
./pipex_bonus /dev/stdin "joebfubf" "ls" "wc -l" file2
./pipex_bonus file "cat" "ls" file2
./pipex_bonus /dev/stdin "cat" "ls" /dev/stdout
./pipex_bonus file cat file2
./pipex_bonus /dev/stdin "cat" "rev" "ls" file2
./pipex_bonus /dev/stdin "cat" "rev" "ls" "wc -l" /dev/stdout
./pipex_bonus /dev/stdin "mfring" "ls" "wc -l"  /dev/stdout 
./pipex_bonus /dev/stdin "rjurjurj" "cat" "rev" "ls" "wc -l" /dev/stdout
./pipex_bonus /dev/stdin roiugfrh "wc -l" /dev/stdout
*/