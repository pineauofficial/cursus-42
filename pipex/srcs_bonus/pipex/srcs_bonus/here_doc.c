/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:07:15 by pineau            #+#    #+#             */
/*   Updated: 2023/05/09 15:47:32 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char **argv, char **env, int argc)
{
	char	*buf;

	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		get_next_line(0, &buf);
		if (ft_strcmp(buf, argv[2]) == 0)
		{
			free(buf);
			break ;
		}
		free(buf);
	}
	get_next_line(-1, NULL);
	process_here_doc(argc, argv, env);
}

void	process_here_doc(int argc, char **argv, char **env)
{
	int		fd;
	int		pipe_fd[2];

	fd = open(argv[5], O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
		error(3, NULL);
	dup2(fd, 0);
	close(fd);
	child(pipe_fd, argv, env, 3);
	fd = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		error(3, NULL);
	dup2(fd, 1);
	close(fd);
	last_exec(env, argv, argc);
	end_process(2, pipe_fd);
}
