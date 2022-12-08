/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:01 by pineau            #+#    #+#             */
/*   Updated: 2022/12/08 14:18:21 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <bsd/string.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

char	*get_next_line_bonus(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, char c);
int		ft_strlen(char *str);
int		ft_strlen2(char *str);
char	*ft_fill_line(char *line, char *keep);
char	*ft_fill_keep(char *keep, char *buf, int fd);
char	*ft_re_fill_keep(char *keep);

#endif