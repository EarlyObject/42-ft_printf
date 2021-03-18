/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        *//**/
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
	char *str_arg;
	int strarglen;
	int width;
	int memreserved;
	char pad;
	int minusflag;

    minusflag = 0;
    memreserved = 0;
    va_start(vl, format);
	while (format && format[i])
	{
		if(format[i] == '%')
		{
			i++;
            width = 0;
            while (format[i] == '-' || format[i] == '0')
            {
                if(format[i] == '0')
                {
                    pad = '0';
                }
                else if(format[i] == '-')
                {
                    minusflag = 1;
                }
                i++;
            }
            while (format[i] >= '0' && format[i] <= '9')
            {
                width *= 10;
                width += format[i] - '0';
                i++;
            }
            if(format[i] == '.' )
            {
                //TODO
            }
			if(format[i] == 's')
			{
				str_arg = va_arg(vl, char *);
			}
            else if (format[i] == 'c')
            {
                char c = (char)va_arg(vl, int);
                str_arg = (char *)malloc(2 * sizeof(char));
                *str_arg = c;
                *(str_arg + 1) = '\0';
                memreserved = 1;
            }
            else if (format[i] == 'p')
            {
                unsigned long long n = va_arg(vl, unsigned long long);
                str_arg = ft_itoa_hex(n, 0);
            }
			else if (format[i] == 'd' || format[i] == 'i')
            {
			    str_arg = ft_itoa(va_arg(vl, int));
            }
			else if (format[i] == 'u')
            {
                str_arg = ft_uitoa(va_arg(vl, int));
            }
            else if (format[i] == 'X' || format[i] == 'x')
            {
                unsigned long long n = va_arg(vl, unsigned int);
                str_arg = ft_itoa_hex(n, format[i]);
            }
            else
            {
                //TODO: implement this part
                //errno = EINVAL;
                j = -1;
                str_arg = "";
              //  break;
            }
            if(str_arg == NULL)
                str_arg = "(null)";
            strarglen = ft_strlen(str_arg);
            if (strarglen < width && !minusflag)
            {
                int tlen = width - strarglen;
                while (tlen-- > 0)
                    ft_putchar_fd(pad ? pad : ' ', 1);
            }
            ft_putstr_fd(str_arg,1);
            if(memreserved)
                free(str_arg);
            j += strarglen;
		}
		else
		{
		    ft_putchar_fd(format[i], 1);
			j++;
		}
		i++;
	}
	va_end(vl);
	return (j);
}