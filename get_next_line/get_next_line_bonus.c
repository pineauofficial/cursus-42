/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:26 by pineau            #+#    #+#             */
/*   Updated: 2022/12/08 14:19:58 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		keep = ft_strjoin(keep, buf);
	}
	free(buf);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep[1024];
	char		*buf;
	char		*line;

	if (keep[fd] != NULL)
		ft_re_fill_keep(keep[fd]);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	keep[fd] = ft_fill_keep(keep[fd], buf, fd);
	if (keep[fd] == NULL)
		return (NULL);
	line = malloc(sizeof(char) * ft_strlen2(keep[fd]) + 2);
	if (!line)
		return (NULL);
	line = ft_fill_line(line, keep[fd]);
	if (line[0] == '\0')
	{
		free(keep[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}
