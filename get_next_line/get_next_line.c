/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:18:53 by pineau            #+#    #+#             */
/*   Updated: 2022/11/30 19:18:45 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(void *buf)
{
	int	a;

	a = 0;
	while (buf)
	{
		if(buf[a] = '$')
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	void *buf;
	
	buf = malloc(sizeof(char) * nbytes)
	if(!buf)
		return (NULL)
	while (ft_check(buf) != 0)
	{
		read(int fd, void *buf, size_t nbytes)
	}
}
test
