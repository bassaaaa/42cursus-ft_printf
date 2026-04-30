/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:25:48 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 00:15:27 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putuint_pf(unsigned int n)
{
	char	buf[10];
	char	*pos;

	pos = &buf[10];
	if (n == 0)
		*(--pos) = '0';
	while (n)
	{
		*(--pos) = n % 10 + '0';
		n /= 10;
	}
	write(1, pos, &buf[10] - pos);
    return &buf[10] - pos;
}
