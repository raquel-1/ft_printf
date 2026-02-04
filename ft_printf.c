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
#include <stdarg.h>
#include <stdio.h>
/*
int sumatorio(int n, ...)
{
    va_list vargs;
    va_start(vargs, n);
    puts("INICIAMOS");
    int ac = 0;
    for(int i = 0; i < n; i++){
        int sig = va_arg(vargs, int);
        printf("siguiente parametro: %d\n", sig);
        ac += sig;
    }
    puts("TERMINAMOS");
    va_end(vargs);
    return (ac);
}

int main(){
    int total = sumatorio(2, 1, 2, 3, 4);
    printf("TOTAL: %d", total);
    return (0);
}*/