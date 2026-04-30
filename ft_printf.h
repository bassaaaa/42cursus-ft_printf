/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:47:04 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 00:20:09 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int ft_putchar_pf(char c);
int	ft_putstr_pf(char *s);
int	ft_putptr_pf(unsigned long p);
int	ft_putuint_pf(unsigned int n);
int	ft_putnbr_pf(int n);
int	ft_puthex_pf(unsigned int n, const char *base);
int	ft_printf(const char *format, ...);

#endif
