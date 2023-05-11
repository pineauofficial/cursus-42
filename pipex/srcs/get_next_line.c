/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:22:00 by pineau            #+#    #+#             */
/*   Updated: 2023/05/09 18:30:49 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_fill_line(char *line, char *keep)
{
	int	a;

	a = 0;
	while (keep[a] != '\n' && keep[a] != '\0')
	{
		line[a] = keep[a];
		a++;
	}
	line[a] = keep[a];
	line[a + 1] = '\0';
	return (line);
}

char	*ft_re_fill_keep(char *keep)
{
	int	a;
	int	b;

	a = ft_strlen(keep) - ft_strlen2(keep) - 1;
	b = 0;
	while (a > 0)
	{
		keep[b] = keep[ft_strlen(keep) - a];
		a--;
		b++;
	}
	keep[b] = '\0';
	return (keep);
}

char	*ft_fill_keep(char *keep, char *buf, int fd)
{
	ssize_t		ftread;
	int			i;

	ftread = 1;
	while (ft_strchr(keep, '\n') == NULL && ftread != 0)
	{
		ftread = read(fd, buf, BUFFER_SIZE);
		if (ftread < 0)
		{
			free(buf);
			free(keep);
			return (NULL);
		}
		buf[ftread] = '\0';
		keep = ft_strjoin2(keep, buf);
	}
	i = ft_strlen(keep);
	if (i > 1)
		keep[i - 1] = '\0';
	free(buf);
	return (keep);
}

int	*get_next_line(int fd, char **buff)
{
	static char	*keep;
	char		*buf;
	char		*line;

	if (fd < 0)
	{
		free(keep);
		return (0);
	}
	if (keep != NULL)
		ft_re_fill_keep(keep);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	keep = ft_fill_keep(keep, buf, fd);
	if (keep == NULL)
		return (NULL);
	line = malloc(sizeof(char) * ft_strlen2(keep) + 2);
	if (!line)
		return (NULL);
	line = ft_fill_line(line, keep);
	*buff = line;
	if (line[0] == '\0')
		end_gnl(keep, line);
	return (0);
}

void	end_gnl(char *keep, char *line)
{
	free(keep);
	free(line);
	return ;
}
