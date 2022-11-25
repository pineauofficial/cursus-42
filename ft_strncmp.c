/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:56:22 by pineau            #+#    #+#             */
/*   Updated: 2022/11/18 11:05:50 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	a;

	a = 0;
	while ((s1[a] == s2[a]) && s1[a] != '\0' && s2[a] != '\0' && a < size)
		a++;
	if (a == size)
		return (0);
	else
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
