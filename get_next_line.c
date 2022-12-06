/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:19:14 by pineau            #+#    #+#             */
/*   Updated: 2022/12/06 16:06:57 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_line(char *line, char *keep)
{
	int	a;

	a = 0;
	line = malloc(sizeof(char) * ft_strlen2(keep) + 2);
	if (!line)
		return (NULL);
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
	static char	*keep;
	char		*buf;
	char		*line;

	if (keep != NULL)
		ft_re_fill_keep(keep);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	keep = ft_fill_keep(keep, buf, fd);
	if (keep == NULL)
		return (NULL);
	line = ft_fill_line(line, keep);
	if (line[0] == '\0')
	{
		free(keep);
		free(line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*str;

// 	fd = open("bible.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)))
// 	{
// 		if (!str)
// 			break ;
// 		printf("%s", str);
// 		printf("-----------------------------\n");
// 		free(str);
// 	}
// }
