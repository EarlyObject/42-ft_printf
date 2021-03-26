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

void
    x_manage_e_minus(t_input *input, int len, int diff)
{
    int m_sign_width;

    if(input->minus_sign)
    {
        ft_putchar_fd('-', 1);
        input->width--;
    }
    if(input->prs_flag)
    {
        if(input->prs > len)
        {
            m_sign_width = input->prs - len;
            while (m_sign_width-- > 0)
                ft_putchar_fd('0', 1);
        }
    }
    while(*input->output)
        ft_print_and_count(input);
    while (diff-- > 0)
    {
        ft_putchar_fd(input->pad, 1);
        input->length++;
    }
}

void
    x_manage_width_and_prs(t_input *input, int len, int diff)
{
    if (input->width)
    {
        if(input->prs_flag)
            input->pad = ' ';
        if(input->minus_sign)
        {
            if(input->pad == '0')
                ft_putchar_fd('-', 1);
            while (diff-- > 0)
                ft_putchar_fd(input->pad, 1);
            if(input->pad == ' ')
                ft_putchar_fd('-', 1);
            input->length += input->width - ft_strlen(input->output);
        }
        else
            while (diff-- > 0)
                ft_putchar_fd(input->pad, 1);
    }
    else
    if(input->minus_sign)
        ft_putchar_fd('-', 1);
    while (input->prs_flag && (input->prs - len++) > 0)
        ft_putchar_fd('0', 1);
    while (*input->output)
        ft_print_and_count(input);
}

void
    ft_print_x(t_input *input)
{
    unsigned long long num;
    int len;
    int diff;

    num = (unsigned int) va_arg(input->arguments,  unsigned long long);
    input->minus_sign = 0;
    if(num < 0)
    {
        input->length++;
        num *= -1;
        input->minus_sign = 1;
    }
    if(num == 0)
    {
        if(input->prs_flag && input->prs == 0)
            input->output = ft_strdup("");
        else
            input->output = ft_strdup("0");
    }
    else
        input->output = ft_itoa_hex(num, *input->format);
    len = ft_strlen(input->output);
    if (input->prs && input->prs > len) {
        diff = input->width - input->prs;
    }
    else
            diff =  input->width - len;
    if(input->minus_sign)
        diff -= 1;
    if(input->flags[e_minus])
        x_manage_e_minus(input, len, diff);
    else
        x_manage_width_and_prs(input, len, diff);
}
