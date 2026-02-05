/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:37:46 by raqroca-          #+#    #+#             */
/*   Updated: 2026/02/02 15:34:24 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //borrar
#include <limits.h> //borrar

int	ft_printf(const char *format, ...)
{
	va_list	vargs;
	int		len;
	int		i;

	va_start(vargs, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				len += ft_print_char('%');
			else if (format[i] == 'c')
				len += ft_print_char(va_arg(vargs, int));
			else if (format[i] == 's')
				len += ft_print_str(va_arg(vargs, char *));
			else if (format[i] == 'p')
				len += ft_print_ptr(va_arg(vargs, void *));
			else if (format[i] == 'd' || format[i] == 'i')
				len += ft_print_nbr(va_arg(vargs, int));
			else if (format[i] == 'u')
				len += ft_print_unsigned(va_arg(vargs, unsigned int));
			else if (format[i] == 'x')
				len += ft_print_hex(va_arg(vargs, unsigned int), 'x');
			else if (format[i] == 'X')
				len += ft_print_hex(va_arg(vargs, unsigned int), 'X');
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(vargs);
	return (len);
}
/*
int main(void)
{
	int ret1, ret2;
	printf("===== TESTING ft_printf =====\n\n");
	// %c
	printf("=== TEST %%c ======\n");
	ret1 = ft_printf("char: %c\n", 'A');
	ret2 = printf("char: %c\n", 'A');
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("NULL: %c\n", '\0');
	ret2 = printf("NULL: %c\n", '\0');
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("ESPACIO: %c\n", ' ');
	ret2 = printf("ESPACIO: %c\n", ' ');
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("n: %c", '\n');
	ret2 = printf("n: %c", '\n');
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("TAB: %c\n", '\t');
	ret2 = printf("TAB: %c\n", '\t');
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	// %s
	printf("=== TEST %%s ======\n");
	ret1 = ft_printf("string: %s\n", "Hola 42");
	ret2 = printf("string: %s\n", "Hola 42");
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("string vacio: %s\n", "");
	ret2 = printf("string vacio: %s\n", "");
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("NULL: %s\n", "NULL");
	ret2 = printf("NULL: %s\n", "NULL");
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	// %d
	printf("=== TEST %%d ======\n");
	ret1 = ft_printf("42: %d\n", 42);
	ret2 = printf("42: %d\n", 42);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("-42: %d\n", -42);
	ret2 = printf("-42: %d\n", -42);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("INT_MIN: %d\n", INT_MIN);
	ret2 = printf("INT_MIN: %d\n", INT_MIN);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("INT_MAX: %d\n", INT_MAX);
	ret2 = printf("INT_MAX: %d\n", INT_MAX);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("0: %d\n", 0);
	ret2 = printf("0: %d\n", 0);
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	//%i
	printf("=== TEST %%i ======\n");
	ret1 = ft_printf("42: %i\n", 42);
	ret2 = printf("42: %i\n", 42);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("-42: %i\n", -42);
	ret2 = printf("-42: %i\n", -42);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("INT_MIN: %i\n", INT_MIN);
	ret2 = printf("INT_MIN: %i\n", INT_MIN);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("INT_MAX: %i\n", INT_MAX);
	ret2 = printf("INT_MAX: %i\n", INT_MAX);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("0: %i\n", 0);
	ret2 = printf("0: %i\n", 0);
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	// %u
	printf("=== TEST %%u ======\n");
	ret1 = ft_printf("4294967295: %u\n", 4294967295);
	ret2 = printf("4294967295: %u\n", 4294967295U);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("0: %u\n", 0);
	ret2 = printf("0: %u\n", 0);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("INT_MAX: %u\n", INT_MAX);
	ret2 = printf("INT_MAX: %u\n", INT_MAX);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("INT_MIN: %u\n", INT_MIN);
	ret2 = printf("INT_MIN: %u\n", INT_MIN);
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	// %x y %X
	printf("=== TEST %%x %%X ======\n");
	ret1 = ft_printf("HEXA 255: %x\n", 255);
	ret2 = printf("HEXA 255: %x\n", 255);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("HEXA_UP 255: %X\n", 255);
	ret2 = printf("HEXA_UP 255: %X\n", 255);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("HEXA 0: %x\n", 0);
	ret2 = printf("HEXA 0: %x\n", 0);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("HEXA_UP 0: %X\n", 0);
	ret2 = printf("HEXA_UP 0: %X\n", 0);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("HEXA: 4294967295 %x\n", 4294967295);
	ret2 = printf("HEXA: 4294967295 %x\n", 4294967295U);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("HEXA_UP 4294967295: %X\n", 4294967295);
	ret2 = printf("HEXA_UP 4294967295: %X\n", 4294967295U);
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	// %p
	printf("=== TEST %%p ======\n");
	int x = 42;
	ret1 = ft_printf("ptr 42: %p\n", &x);
	ret2 = printf("ptr 42: %p\n", &x);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	ret1 = ft_printf("ptr NULL: %p\n", NULL);
	ret2 = printf("ptr NULL: %p\n", NULL);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	char *str = "Hello";
	ret1 = ft_printf("ptr string: %p\n", str);
	ret2 = printf("ptr string: %p\n", str);
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	// %%
	printf("=== TEST %%%% ======\n");
	ret1 = ft_printf("Percent: %%\n");
	ret2 = printf("Percent: %%\n");
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	// CASOS MIXTOS
	printf("=== TEST CASOS MIXTOOOOOO ===\n");
	ret1 = ft_printf("mix1: %c %s %d\n", 'X', "test", 42);
	ret2 = printf("mix1: %c %s %d\n", 'X', "test", 42);
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	ret1 = ft_printf("mix2: %d %x %u\n", -42, 255, 100);
	ret2 = printf("mix2: %d %x %u\n", -42, 255, 100);
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	int y = 10;
	ret1 = ft_printf("mix3: %p %d %c\n", &y, y, 'A');
	ret2 = printf("mix3: %p %d %c\n", &y, y, 'A');
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	ret1 = ft_printf("mix4: %c %s %d %i %u %x %X %%\n", 'Z', "all", -10, 20, 30U, 40, 50);
	ret2 = printf("mix4: %c %s %d %i %u %x %X %%\n", 'Z', "all", -10, 20, 30U, 40, 50);
	printf("ft: %d | original: %d\n\n", ret1, ret2);

	ret1 = ft_printf("100%% completo: %d%%\n", 100);
	ret2 = printf("100%% completo: %d%%\n", 100);
	printf("ft: %d | original: %d\n\n", ret1, ret2);
	return (0);
}*/