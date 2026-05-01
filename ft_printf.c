/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:59:12 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 16:03:46 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list *args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(*args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(*args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		len += ft_print_uint(va_arg(*args, unsigned int));
	else if (format == 'x')
		len += ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF");
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
			len += print_format(&args, format[i + 1]);
			i += 2;
		}
		else
			len += ft_print_char(format[i++]);
	}
	va_end(args);
	return (len);
}
