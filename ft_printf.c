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

static int	handle_format(va_list vargs, char specifier)
{
	int	len;

	len = 0;
	if (specifier == '%')
		len += ft_print_char('%');
	else if (specifier == 'c')
		len += ft_print_char(va_arg(vargs, int));
	else if (specifier == 's')
		len += ft_print_str(va_arg(vargs, char *));
	else if (specifier == 'p')
		len += ft_print_ptr(va_arg(vargs, void *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_print_nbr(va_arg(vargs, int));
	else if (specifier == 'u')
		len += ft_print_unsigned(va_arg(vargs, unsigned int));
	else if (specifier == 'x')
		len += ft_print_hex(va_arg(vargs, unsigned int), 'x');
	else if (specifier == 'X')
		len += ft_print_hex(va_arg(vargs, unsigned int), 'X');
	return (len);
}

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
			len += handle_format(vargs, format[i]);
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(vargs);
	return (len);
}
