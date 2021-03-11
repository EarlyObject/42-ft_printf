/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:05:38 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/11 17:59:10 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list vl; 
	int i = 0, j=0;
	char buff[100] = {0};
	char * str_arg;

	va_start(vl, format);
	while (format && format[i])
	{
		if(format[i] == '%')
		{
			i++;
			if(format[i] == 's')
			{
				str_arg = va_arg(vl, char *);
				ft_strlcpy(&buff[j], str_arg, ft_strlen((char *)str_arg));
				j += ft_strlen((char *)str_arg);
				break;
			}
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