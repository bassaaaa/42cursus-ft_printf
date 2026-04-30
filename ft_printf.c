/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:59:12 by tsito             #+#    #+#             */
/*   Updated: 2026/04/30 21:17:45 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (format[i + 1] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i + 1] == 'u')
				ft_putnbr_fd(va_arg(args, int), 1);
            else if (format[i + 1] == '%')
                ft_putchar_fd('%', 1);
			i += 2;
		}
		else
			ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("test1\n");
	ft_printf("%c\n", "test");
	ft_printf("test: %s\n", "test2");
	ft_printf("%s %s\n", "testtest3", "test4");
	ft_printf("%d\n", -123);
	printf("%c\n", 'a');
}
