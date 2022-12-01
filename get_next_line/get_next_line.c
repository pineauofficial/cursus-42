/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:18:53 by pineau            #+#    #+#             */
/*   Updated: 2022/12/01 12:14:07 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;
	ssize_t		ftread;
	int			stop;
	int			BUFFER_SIZE;	

	stop = 0;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	while (strchr(line, '\n') != 0 && stop == 0)
	{
		ft_bzero(buf, BUFFER_SIZE);
		ftread = read(int fd, void *buf, size_t BUFFER_SIZE);
		if (strchr(line, '\n') == 0)
		{
			line = ft_strjoin(line, buf, '\n');
			stop == 1;
		}
		else
			line = ft_strjoin(line, buf, '\0');
	}
	return (line);
}

int main()
{
	// compiler avec -D BUFFER_SIZE=n
	int fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("%d", fd);
	printf("%s" ,get_next_line(int fd));
}
