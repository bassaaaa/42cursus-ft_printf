/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:58:13 by tsito             #+#    #+#             */
/*   Updated: 2026/05/02 14:37:38 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *p)
{
	char			buf[16];
	char			*pos;
	unsigned long	addr;
	int				ret;

	if (p == 0)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)p;
	pos = &buf[16];
	while (addr)
	{
		*(--pos) = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	ret = write(1, "0x", 2);
	ret += write(1, pos, &buf[16] - pos);
	return (ret);
}
