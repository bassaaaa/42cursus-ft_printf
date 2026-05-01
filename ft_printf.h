/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:47:04 by tsito             #+#    #+#             */
/*   Updated: 2026/05/01 12:58:59 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_ptr(unsigned long p);
int	ft_print_uint(unsigned int n);
int	ft_print_nbr(int n);
int	ft_print_hex(unsigned int n, const char *base);
int	ft_printf(const char *format, ...);

#endif
