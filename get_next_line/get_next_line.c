/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:19:14 by pineau            #+#    #+#             */
/*   Updated: 2022/12/02 17:33:17 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_keep(char *keep, char *buf, int fd)
{
	ssize_t		ftread;

	ftread = 1;
	while (ft_strchr(keep, '\n') == NULL && ftread != 0)
	{
		ftread = read(fd, buf, BUFFER_SIZE);
		keep = ft_strjoin(keep, buf);
	}
	return (keep);
}

char	*ft_fill_line(char *line, char *keep)
{
	int	a;

	a = 0;
	line = malloc(sizeof(char) * ft_strlen2(keep) + 1);
	if (!line)
		return (NULL);
	while (keep[a] != '\n')
	{
		line[a] = keep[a];
		a++;
	}
	line[a] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*buf;
	char		*line;

	if (BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	keep = ft_fill_keep(keep, buf, fd);
	if (keep == NULL)
		return (NULL);
	line = ft_fill_line(line, keep);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		if (!str)
			break ;
		printf("%s", str);
		printf("-----------------------------\n");
		free(str);
	}
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// }
