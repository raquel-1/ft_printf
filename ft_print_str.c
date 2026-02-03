/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:00 by raqroca-          #+#    #+#             */
/*   Updated: 2026/02/03 11:38:03 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_str(char *str)
{
    int len;
    int result_char;

    len = 0;
    if (!str)
        return (write(1, "(null)", 6));
    while (*str)
    {
        result_char = ft_print_char(*str);
        if (result_char == -1)
            return (-1);
        len += result_char;
        str++;
    }
    return (len);
}
