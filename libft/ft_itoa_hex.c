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

int get_numlen(unsigned long long int num)
{
    int len;
    unsigned long long tmp;

    len = 0;
    tmp = num;
    if(num != 0)
        while (tmp > 0)
        {
            len++;
            tmp /= 16;
        }
    else
        len = 1;
    return (len);
}

char* ft_itoa_hex(unsigned long long num, char format)
{
    char *p;
    char base[16] = "0123456789abcdef";
    int len;
    unsigned int rmd;

    len = get_numlen(num);
    if(!format)
        len += 2;
    p = ft_make_str(len);
    p[len--] = '\0';
    while (num >= 16 && len > 0)
    {
        rmd = num % 16;
        num = num / 16;
        *(p + len--) = (format == 'X' && rmd > 9) ? base[rmd] - 32 : base[rmd];
    }
    *(p + len--) = (format == 'X' && num > 9) ? base[num] - 32 : base[num];
    if (!format)
    {
        *(p + len--) = 'x';
        *(p + len) = '0';
    }
    return (p);
}
