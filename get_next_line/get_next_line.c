/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:18:53 by pineau            #+#    #+#             */
/*   Updated: 2022/12/01 10:05:59 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *str, int c)
{
	int	a;

	a = 0;
	if (c >= 256)
		c = c -256;
	if (str == NULL)
		return (NULL);
	while (str[a] != '\0' && str[a] != c)
		a++;
	if (str[a] == c)
		return ((char *)(str + a));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[a] != '\0')
		str[b++] = s1[a++];
	a = 0;
	while (s2[a] != '\0')
		str[b++] = s2[a++];
	str[b] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

char	*get_next_line(int fd)
{
	char	*tmp;
	char	*buf;
	ssize_t	ftread;
	int		stop;

	stop = 0;
	if (nbytes < 1 || fd < 0 ) // pas sûr
		return (NULL);
	while (strchr(tmp, '\n') != 0 && stop == 0)
	{

		buf = ft_bzero(buf, nbytes);
		ftread = read(int fd, void *buf, size_t nbytes);
		if (strchr(tmp, '\n') == 0)
		{
			tmp = ft_strjoin(strchr(tmp, '\n'), buf); // pas bon
			stop == 1;
		}
		else
			tmp = ft_strjoin(tmp, buf);
	}
}
