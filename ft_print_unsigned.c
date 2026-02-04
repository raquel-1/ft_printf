/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:51:12 by raqroca-          #+#    #+#             */
/*   Updated: 2026/02/03 16:51:15 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_unsigned(unsigned int n)
{
    unsigned int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_print_unsigned(n / 10);
	}
	len += ft_print_char((n % 10) + '0'); 
	return (len);
}
