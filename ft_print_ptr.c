/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:27:33 by raqroca-          #+#    #+#             */
/*   Updated: 2026/02/04 12:27:35 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putbase(unsigned long n);

int	ft_print_ptr(void *ptr)
{
	int				len;
	unsigned long	direc;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = 0;
	len += write(1, "0x", 2);
	direc = (unsigned long)ptr;
	len += putbase(direc);
	return (len);
}

static int	putbase(unsigned long n)
{
	char	char_hex;
	int		len;

	len = 0;
	if (n >= 16)
	{
		len += putbase(n / 16);
	}
	char_hex = HEXA[n % 16];
	len += ft_print_char(char_hex);
	return (len);
}
