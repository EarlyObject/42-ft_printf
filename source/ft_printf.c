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
    t_input *input;
    int len;
    if(!(input = (t_input *)malloc(sizeof(t_input))))
        return (0);
    input->format = format;
    va_start(input->arguments, format);
    input->length = 0;
    while (*input->format)
    {
        while (*input->format && *input->format != '%')
        {
            ft_count_putchar(input, *input->format);
            input->format++;
        }
        if(*input->format && *input->format == '%')
        {
            input->output = NULL;
            input->format++;
            ft_mng_input(input);
           /* if(input->output != NULL)
                free(input->output);*/
        }
    }
    va_end(input->arguments);
    len = input->length;
    free(input);
	return (len);
}

//TODO: implement (errno = EINVAL)?;
