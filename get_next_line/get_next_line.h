/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:16:42 by pineau            #+#    #+#             */
/*   Updated: 2022/12/01 12:27:31 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <bsd/string.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, char c);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(char *str, char c);
void	ft_bzero(void *s, size_t n);

#endif