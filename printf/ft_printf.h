/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:35:58 by pineau            #+#    #+#             */
/*   Updated: 2022/11/29 15:38:55 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <bsd/string.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr_base(int nbr, char *base, int *size);
void	ft_putnbr_p(void *nbrb, char *base, int *size);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr_u(unsigned int nbr, char *base, int *size);
int		ft_error(char *base);
int		ft_strlen(char *str);
void	ft_putnbr_x(int nbr, char *base, int *size);

#endif