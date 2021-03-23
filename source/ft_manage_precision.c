/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:32:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/19 14:32:15 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_manage_precision(t_input *input)
{
    if(*input->format == '.')
    {
        input->precision_flag = 1;
        input->precision = 0;
        input->format++;
        if(*input->format == '*')
        {
            input->precision = va_arg(input->arguments, int);
            if (input->precision < 0)
            {
                input->precision = 0;
                input->precision_flag = 0;
            }
            input->format++;
        }
        while (*input->format >= '0' && *input->format <= '9')
        {
            input->precision *= 10;
            input->precision += *input->format - '0';
            input->format++;
        }
    }
    else
        input->precision_flag = 0;
}