/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:56:36 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/24 08:56:38 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

void ft_print_d(t_input *input)
{
    long long num;
    int len;
    int diff;
    int printlen;
    int m_sign_width;
    num = va_arg(input->arguments, int);
    input->minus_sign = 0;
    if(num < 0)
    {
        input->length++;
        num *= -1;
        input->minus_sign = 1;
    }
    input->output = ft_itoa(num);
    len = ft_strlen(input->output);
    if(input->precision_flag && len == 1 && *input->output == '0')
    {
        input->output = "";
        len = 0;
    }
    if(input->precision && input->precision > len)
        diff = input->width - input->precision;
    else
        diff = input->width - len;
    if(input->minus_sign)
        diff -= 1;
    if(input->flags[e_minus])
    {
        if(input->minus_sign)
        {
            ft_putchar_fd('-', 1);
            input->width--;
        }
        m_sign_width = 0;
        if(input->precision_flag)
        {
            if(input->precision > len)
            {
                m_sign_width = input->precision - len;
                while (m_sign_width-- > 0)
                    ft_putchar_fd('0', 1);
                while (*input->output)
                {
                    ft_putchar_fd(*input->output, 1);
                    input->output++;
                    input->length++;
                    m_sign_width++;
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
            }
        }
        else
        {
            while(*input->output)
            {
                ft_putchar_fd(*input->output, 1);
                input->output++;
                input->length++;
                m_sign_width++;
            }
        }
        while (diff>0)
        {
            ft_putchar_fd(input->pad, 1);
            diff--;
            input->length++;
        }
    }
    else
    {
        if (input->width)
        {
            if(input->precision_flag)
                input->pad = ' ';
            if(input->minus_sign)
            {
                if(input->pad == '0')
                {
                    ft_putchar_fd('-', 1);
                    while (diff > 0)
                    {
                        ft_putchar_fd(input->pad, 1);
                        diff--;
                    }
                }
                else if(input->pad == ' ')
                {
                    while (diff > 0)
                    {
                        ft_putchar_fd(input->pad, 1);
                        diff--;
                    }
                    ft_putchar_fd('-', 1);
                }
                else
                {
                    if(input->minus_sign)
                        ft_putchar_fd('-', 1);
                    input->length += input->width - ft_strlen(input->output);
                }
            }
            else
            {
                while (diff > 0)
                {
                    ft_putchar_fd(input->pad, 1);
                    diff--;
                }
            }
        }
        else
        {
            if(input->minus_sign)
                ft_putchar_fd('-', 1);
        }
        if(input->precision_flag )
        {
            m_sign_width = input->precision - len;
            while (m_sign_width-- > 0)
                ft_putchar_fd('0', 1);
            printlen = len;
        }
        while (*input->output)
        {
            ft_putchar_fd(*input->output, 1);
            input->output++;
            input->length++;
        }
    }
}
