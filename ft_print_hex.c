/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:56:25 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 12:59:24 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_print_hex(unsigned int n, const char *base)
{
	char	buf[8];
	char	*pos;

	pos = &buf[8];
	if (n == 0)
		*(--pos) = '0';
	while (n)
	{
		*(--pos) = base[n % 16];
		n /= 16;
	}
	write(1, pos, &buf[8] - pos);
	return (&buf[8] - pos);
}
