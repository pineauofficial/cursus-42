/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:07:15 by pineau            #+#    #+#             */
/*   Updated: 2023/05/08 14:14:02 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char **argv, char **env, int argc)
{
	char	*buf;
	int		fd;

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
	fd = open(argv[1], O_WRONLY | O_CREAT, 0777);
	dup2(fd, 0);
	close(fd);
	child(argv, env, 3);
	fd = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0777);
	dup2(fd, 1);
	close(fd);
	last_exec(env, argv, argc);
	unlink(argv[1]);// ne delete pas le fichier si il etait deja present
}
