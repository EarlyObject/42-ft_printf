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
				strarglen = ft_strlen((char *)str_arg);
			} else if (format[i] == 'd')
            {
			    str_arg = ft_itoa(va_arg(vl, int));
            } else if (format[i] == 'c')
            {
                str_arg = ft_itoa(va_arg(vl, int));
            }
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