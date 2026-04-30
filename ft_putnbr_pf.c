/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:57:32 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 00:57:45 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putnbr_pf(int n)
{
	unsigned int	num;
	char			buf[11];
	char			*pos;

	if (n < 0)
		num = -(unsigned int)n;
	else
		num = (unsigned int)n;
	pos = &buf[11];
	if (num == 0)
		*(--pos) = '0';
	while (num)
	{
		*(--pos) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(--pos) = '-';
	write(1, pos, &buf[11] - pos);
	return (&buf[11] - pos);
}
