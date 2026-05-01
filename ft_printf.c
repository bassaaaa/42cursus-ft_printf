/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:59:12 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 13:03:39 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += print_format(args, format[i + 1]);
			i += 2;
		}
		else
			len += ft_print_char(format[i++]);
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	int	len;
//
// 	len = ft_printf("char: %c  ", 'A');
// 	printf("len: %d\n", len);
// 	len = ft_printf("str: %s  ", "hello");
// 	printf("len: %d\n", len);
// 	len = printf("ptr: %p  ", "hello");
// 	printf("len: %d\n", len);
// 	len = ft_printf("ptr: %p  ", "hello");
// 	printf("len: %d\n", len);
// 	len = ft_printf("int: %d %i  ", -42, 42);
// 	printf("len: %d\n", len);
// 	len = ft_printf("uint: %u  ", 4294967295U);
// 	printf("len: %d\n", len);
// 	len = ft_printf("hex: %x %X  ", 3735928559U, 3735928559U);
// 	printf("len: %d\n", len);
// 	len = ft_printf("percent: %%  ");
// 	printf("len: %d\n", len);
// 	return (0);
// }
