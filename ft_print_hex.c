/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:35:02 by raqroca-          #+#    #+#             */
/*   Updated: 2026/02/04 10:35:04 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	char	char_hex;
	int		len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_hex(n / 16, format);
	}
	if (format == 'x')
	{
		char_hex = HEXA[n % 16];
	}
	if (format == 'X')
	{
		char_hex = HEXA_UP[n % 16];
	}
	len += ft_print_char(char_hex);
	return (len);
}
