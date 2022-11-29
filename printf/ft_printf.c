/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:35 by pineau            #+#    #+#             */
/*   Updated: 2022/11/29 15:45:39 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(char c, va_list arg, int size)
{
	if (c == 'c')
		size += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		size += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		ft_putnbr_p(va_arg(arg, void *), "0123456789abcdef", &size);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(arg, int), "0123456789", &size);
	else if (c == 'u')
		ft_putnbr_u(va_arg(arg, unsigned int), "0123456789", &size);
	else if (c == 'x')
		ft_putnbr_x(va_arg(arg, int), "0123456789abcdef", &size);
	else if (c == 'X')
		ft_putnbr_x(va_arg(arg, int), "0123456789ABCDEF", &size);
	else if (c == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		size;
	int		i;
	va_list	arg;

	size = 0;
	i = 0;
	va_start (arg, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size = ft_parsing(str[i + 1], arg, size);
			i += 2;
		}
		else
		{
			ft_putchar(str[i]);
			size++;
			i++;
		}
	}
	return (size);
}

// int main(void)
// {
// 	int	a = -555;
// 	char c = '0';
// 	char str[] = "bonjour";
// 	char d = '%';

// 	printf("[%d]\n", ft_printf(" %x ", a));
//  	printf("[%d]\n", printf(" %x ", a));

// // 	printf("[%d]\n", ft_printf("%d", a));
// // 	printf("[%d]\n", ft_printf("%c", c));
// }