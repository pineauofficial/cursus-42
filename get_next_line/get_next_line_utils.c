/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:18:42 by pineau            #+#    #+#             */
/*   Updated: 2022/12/01 10:24:15 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str, char c)
{
	int	a;

	a = 0;
	while (str[a] != '\0' || str[a] != c)
		a++;
	return (a);
}

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

char	*ft_strjoin(char const *s1, char const *s2, char c)
{
	char	*str;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1, c) + ft_strlen(s2, c) + 1));
	if (!str)
		return (NULL);
	while (s1[a] != '\0' && s1[a] != c)
		str[b++] = s1[a++];
	a = 0;
	while (s2[a] != '\0' && s1[a] != c)
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
