/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 02:12:25 by sqian             #+#    #+#             */
/*   Updated: 2025/12/07 14:52:11 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	dostuff(va_list args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnb(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunb(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	if (!s)
		return (-1);
	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && ft_strchr("cspdiuxX%", *(s + 1)) != NULL)
		{
			count += dostuff(args, *(s + 1));
			s += 2;
		}
		else
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}
/*
Line:18
default integer promotion（默认整型提升）:
在 C 的可变参数函数里，所有 char 和 short 都会自动变成 int
In C variadic functions (like printf), every char and
short is automatically promoted to int.

因为可变参数没有类型信息，为了安全，编译器必须把小类型都升级成 int。
Because variadic functions lack type information,
the compiler promotes small types to int for safety.

Line:68 try i++ instead of s++
*/

// void    test(const char *name)
// {
//     printf("\n============== %s ==============\n", name);
// }

// int main(void)
// {
// 	int r1, r2;
// 	char *null_str = NULL;

// 	// ----------- %c ------------
// 	test("%c");
// 	r1 = printf("printf  : [%c]\n", 'A');
// 	r2 = ft_printf("ft_printf: [%c]\n", 'A');

// 	r1 = printf("printf  : [%c]\n", 0);
// 	r2 = ft_printf("ft_printf: [%c]\n", 0);

// 	// ----------- %s ------------
// 	test("%s");
// 	r1 = printf("printf  : [%s]\n", "Hello World");
// 	r2 = ft_printf("ft_printf: [%s]\n", "Hello World");

// 	r1 = printf("printf  : [%s]\n", "");
// 	r2 = ft_printf("ft_printf: [%s]\n", "");

// 	r1 = printf("printf  : [%s]\n", null_str);
// 	r2 = ft_printf("ft_printf: [%s]\n", null_str);

// 	// ----------- %p ------------
// 	test("%p");
// 	int a = 42;
// 	r1 = printf("printf  : [%p]\n", &a);
// 	r2 = ft_printf("ft_printf: [%p]\n", &a);

// 	r1 = printf("printf  : [%p]\n", NULL);
// 	r2 = ft_printf("ft_printf: [%p]\n", NULL);

// 	// ----------- %d / %i -------
// 	test("%d / %i");
// 	r1 = printf("printf  : [%d]\n", 42);
// 	r2 = ft_printf("ft_printf: [%d]\n", 42);

// 	r1 = printf("printf  : [%d]\n", -42);
// 	r2 = ft_printf("ft_printf: [%d]\n", -42);

// 	r1 = printf("printf  : [%d]\n", 2147483647);
// 	r2 = ft_printf("ft_printf: [%d]\n", 2147483647);

// 	r1 = printf("printf  : [%ld]\n", -2147483648);
// 	r2 = ft_printf("ft_printf: [%d]\n", -2147483648);

// 	// ----------- %u ------------
// 	test("%u");
// 	r1 = printf("printf  : [%u]\n", 0);
// 	r2 = ft_printf("ft_printf: [%u]\n", 0);

// 	r1 = printf("printf  : [%u]\n", 4294967295u);
// 	r2 = ft_printf("ft_printf: [%u]\n", 4294967295u);

// 	// ----------- %x / %X -------
// 	test("%x / %X");
// 	r1 = printf("printf  : [%x]\n", 255);
// 	r2 = ft_printf("ft_printf: [%x]\n", 255);

// 	r1 = printf("printf  : [%X]\n", 255);
// 	r2 = ft_printf("ft_printf: [%X]\n", 255);

// 	r1 = printf("printf  : [%x]\n", 0);
// 	r2 = ft_printf("ft_printf: [%x]\n", 0);

// 	r1 = printf("printf  : [%x]\n", 4294967295u);
// 	r2 = ft_printf("ft_printf: [%x]\n", 4294967295u);

// 	// ----------- %% ------------
// 	test("%%");
// 	r1 = printf("printf  : [%%]\n");
// 	r2 = ft_printf("ft_printf: [%%]\n");

// 	// ----------- Mixed ---------
// 	test("Mixed cases");
// 	r1 = printf("printf  : [%d %s %x %p]\n", 123, "abc", 255, &a);
// 	r2 = ft_printf("ft_printf: [%d %s %x %p]\n", 123, "abc", 255, &a);

// 	r1 = printf("printf  : [%s %c %d %%]\n", "mix", 'X', -42);
// 	r2 = ft_printf("ft_printf: [%s %c %d %%]\n", "mix", 'X', -42);

// 	printf("\n===== DONE =====\n");
// 	return 0;
// }
