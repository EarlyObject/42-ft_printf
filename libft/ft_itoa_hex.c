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

char* ft_itoa_hex(unsigned long long num, char format)
{
    char *p;
    char base[16] = "0123456789abcdef";
    int len;
    
    unsigned int rmd;
    len = format ? 8 : 14;
    if (!(p = malloc(sizeof(char) * (len + 1))))
        return (0);
    p[len--] = '\0';
    while (num >= 16 && len > 0)
    {
        rmd = num % 16;
        num = num / 16;
        *(p + len--) = (format == 'X' && rmd > 9) ? base[rmd] - 32 : base[rmd];
    }
    *(p + len--) = (format == 'X') ? base[num] - 32 : base[num];
    if (!format)
    {
        while (len > 1)
            *(p + len--) = '0';
        *(p + len--) = 'x';
        *(p + len--) = '0';
    }

    return (p);
}