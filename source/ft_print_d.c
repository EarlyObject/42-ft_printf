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

void print_and_count(t_input *input) {
    ft_putchar_fd(*input->output, 1);
    input->output++;
    input->length++;
}

void manage_e_minus(t_input *input, int len, int diff)
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
        print_and_count(input);
    while (diff-- > 0)
    {
        ft_putchar_fd(input->pad, 1);
        input->length++;
    }
}

void manage_width_and_prs(t_input *input, int len, int diff)
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
        print_and_count(input);
}

void ft_print_d(t_input *input)
{
    long long num;
    int len;
    int diff;

    num = (int)va_arg(input->arguments, long long);
    input->minus_sign = 0;
    if(num < 0)
    {
        input->length++;
        num *= -1;
        input->minus_sign = 1;
    }
    if(input->prs_flag && num == 0)
        input->output = "";
    else
        input->output = ft_itoa(num);
    len = ft_strlen(input->output);
    diff = (input->prs && input->prs > len) ? input->width - input->prs : input->width - len;
    if(input->minus_sign)
        diff -= 1;
    if(input->flags[e_minus])
        manage_e_minus(input, len, diff);
    else
        manage_width_and_prs(input, len, diff);
}
