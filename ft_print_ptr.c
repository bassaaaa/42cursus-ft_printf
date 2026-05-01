/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:58:13 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 15:17:57 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_print_ptr(void *p)
{
	char			buf[16];
	char			*pos;
	unsigned long	addr;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)p;
	pos = &buf[16];
	while (addr)
	{
		*(--pos) = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	write(1, "0x", 2);
	write(1, pos, &buf[16] - pos);
	return (&buf[16] - pos + 2);
}
