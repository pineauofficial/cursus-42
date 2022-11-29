/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:35:52 by pineau            #+#    #+#             */
/*   Updated: 2022/11/17 15:03:11 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count2(char const *s, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s[a])
	{
		while (s[a] == c && s[a])
			a++;
		if (s[a] != c && s[a])
			b++;
		while (s[a] != c && s[a])
			a++;
	}
	return (b);
}

static char	*remplissage(char const *s, char c, int index)
{
	char	*tmp;
	int		lenght;

	lenght = 0;
	while (s[index + lenght] != c && s[index + lenght])
		lenght++;
	tmp = (char *) malloc(sizeof(char) * (lenght + 1));
	if (!tmp)
		return (NULL);
	lenght = 0;
	while (s[index] != c && s[index])
	{
		tmp[lenght] = s[index];
		index++;
		lenght++;
	}
	tmp[lenght] = '\0';
	return (tmp);
}

static char	**mallocation(const char *s, char c, char **tab)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (s[a] && i < count2(s, c))
	{
		while (s[a] == c)
			a++;
		if (s[a] != c)
			tab[i] = remplissage(s, c, a);
		i++;
		while (s[a] != c && s[a])
			a++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	words = count2(s, c);
	tab = (char **) malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = mallocation(s, c, tab);
	return (tab);
}
/*int main()
{
	char *str = "  tripouille  42  ";
	char charset = ' ';
	char **tab = ft_split(str, charset);
	
	
	int i = -1;
	while (++i < 3)
		printf("~%s~\n", tab[i]);
	free(tab);
	return 0;
}*/
