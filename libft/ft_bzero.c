/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:22:16 by pineau            #+#    #+#             */
/*   Updated: 2022/11/22 15:58:34 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*int    main(void)
{
    int    ptr[] = {1, 2, 5, 4, 45, 42};
    int    i = 0;
    int    lenght = sizeof(int) * 5;

    ft_bzero(ptr, lenght);
    i = 0;
    while (i < 6)
    {
        printf("%d ", ptr[i]);
        i++;
    }
    printf("\n");
    return (0);
}*/
