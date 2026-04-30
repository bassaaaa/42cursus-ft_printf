/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:58:13 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 00:58:31 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putptr_pf(unsigned long p)
{
	char	buf[16];
    char *pos;

    pos = &buf[16];
	while (p)
	{
		*(--pos) = "0123456789ABCDEF"[p % 16];
		p /= 16;
	}
    write(1, "0x", 2);
	write(1, pos, &buf[16] - pos);
	return (&buf[16] - pos + 2);
}
