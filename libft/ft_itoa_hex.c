/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:24:16 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/16 16:24:21 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char* ft_itoa_hex(unsigned long long number)
{
    char *p;
    char base[16] = "0123456789abcdef";
    int len;
    unsigned int remainder;

    len = 14;
    if (!(p = malloc(sizeof(char) * (len + 1))))
        return (0);
    p[len--] = '\0';
    while (number>= 16)
    {
        remainder = number % 16;
        number = number / 16;
        *(p + len--)= base[remainder];
    }
    *(p + len--) = base[number];
    while (len > 1)
        *(p + len--) = '0';
    *(p + len--) = 'x';
    *(p + len--) = '0';
    return (p);
}