/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:05:38 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/12 14:32:33 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	va_list vl; 
	int i = 0, j=0;
	char buff[300] = {0};
	char *str_arg;
	int strarglen;

	va_start(vl, format);
	while (format && format[i])
	{
		if(format[i] == '%')
		{
			i++;
			if(format[i] == 's')
			{
				str_arg = va_arg(vl, char *);

			}
            else if (format[i] == 'c')
            {
                char c = (char)va_arg(vl, int);
                str_arg = &c;
                *(str_arg + 1) = 0;
            }
            else if (format[i] == 'p')
            {
                unsigned long long n = va_arg(vl, unsigned long long);
                str_arg = ft_itoa_hex(n);
            }
			else if (format[i] == 'd' || format[i] == 'i')
            {
			    str_arg = ft_itoa(va_arg(vl, int));
            }
			else if (format[i] == 'u')
            {
                str_arg = ft_uitoa(va_arg(vl, int));
            }

            strarglen = ft_strlen(str_arg);
            ft_strlcpy(&buff[j], str_arg, strarglen + 1);
            j += strarglen;
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	ft_putstr_fd(buff, 1);
	va_end(vl);
	return (j);
}