/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:54:23 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/19 11:54:50 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_manage_input(t_input *input)
{
    int len;
    int diff;
    int printlen;
    int m_sign_width;
    ft_manage_flags(input);
    ft_manage_width(input);
    ft_manage_precision(input);
    ft_manage_format(input);
    len = ft_strlen(input->output);
    diff = input->width - len;
    //manage -sign
    if(input->flags[e_minus])
    {
        m_sign_width = 0;
        while(*input->output)
        {
            ft_putchar_fd(*input->output, 1);
            input->output++;
            input->length++;
            m_sign_width++;
        }
        while (m_sign_width < input->width)
        {
            ft_putchar_fd(input->pad, 1);
            diff--;
            input->length++;
            m_sign_width++;
        }
    }
    else
    {
        if (input->width)
        {
            input->length += input->width - ft_strlen(input->output);
            while (diff > 0)
            {
                ft_putchar_fd(input->pad, 1);
                diff--;
                // input->length++;
            }

        }

        if(input->precision_flag && *input->format == 's')
        {
            printlen = (input->precision < len ? input->precision : len);
            while (*input->output && printlen > 0)
            {
                ft_putchar_fd(*input->output, 1);
                printlen--;
                input->output++;
                input->length++;
            }
        }
        else
        {
            while (*input->output)
            {
                ft_putchar_fd(*input->output, 1);
                input->output++;
                input->length++;
            }
            // input->length -= ft_strlen(input->output);
        }
    }

    input->format++;
}