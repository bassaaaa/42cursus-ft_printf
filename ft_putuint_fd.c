/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:25:48 by tsito             #+#    #+#             */
/*   Updated: 2026/04/30 21:31:13 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_putuint_fd(unsigned int n, int fd)
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
	write(fd, pos, &buf[10] - pos);
}
