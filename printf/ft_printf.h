/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:14:29 by sqian             #+#    #+#             */
/*   Updated: 2025/12/07 05:00:30 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(void *ptr);
int		ft_putnb(int n);
int		ft_putunb(unsigned int n);
int		ft_puthex(unsigned int n, char c);
int		ft_printf(const char *s, ...);
int		dostuff(va_list args, const char c);
// char	*ft_strchr(const char *s, int c);

#endif
