/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:19:17 by raqroca-          #+#    #+#             */
/*   Updated: 2026/02/03 12:19:18 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_nbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
        return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		len += ft_print_nbr(n / 10);
	}
	len += ft_print_char((n % 10) + '0'); 
	return (len);
}
