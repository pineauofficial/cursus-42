/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:18:53 by pineau            #+#    #+#             */
/*   Updated: 2022/12/01 10:28:22 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*line;
	char	*buf;
	ssize_t	ftread;
	int		stop;

	stop = 0;
	if (nbytes < 1 || fd < 0 ) // pas sûr
		return (NULL);
	while (strchr(line, '\n') != 0 && stop == 0)
	{

		buf = ft_bzero(buf, nbytes);
		ftread = read(int fd, void *buf, size_t nbytes);
		if (strchr(line, '\n') == 0)
		{
			line = ft_strjoin(line, buf, '\n');
			stop == 1;
		}
		else
			line = ft_strjoin(line, buf, '\0');
	}
}
