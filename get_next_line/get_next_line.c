/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:18:53 by pineau            #+#    #+#             */
/*   Updated: 2022/12/01 15:02:56 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;
	ssize_t		ftread;
	int			stop;

	stop = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	while (strchr(buf, '\n') == NULL && stop == 0)
	{
		ft_bzero(buf, BUFFER_SIZE);
		ftread = read(fd, buf, BUFFER_SIZE);
		//printf("buf : %s\n", buf);
		if (strchr(buf, '\n') != NULL)
		{
			line = ft_strjoin(line, buf, '\n');
			stop == 1;
			printf("line : [%s]\n", line);
		}
		else
			line = ft_strjoin(line, buf, '\0');
		printf("line : [%s]\n", line);
	}
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));

}

// compiler avec -D BUFFER_SIZE=n

// probleme strjoiin essaie de join 0 + bonjo 