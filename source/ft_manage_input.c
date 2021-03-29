/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:54:23 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/26 12:08:20 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_manage_input(t_input *input)
{
    ft_manage_flags(input);
    ft_manage_width(input);
    ft_manage_precision(input);
    ft_manage_format(input);
    if(input->var_type[e_string] == 1)
        ft_print_s(input);
	else if(input->var_type[e_char] == 1)
        //ft_print_s(input);
        ft_print_c(input);
    else if(input->var_type[e_int] == 1)
        ft_print_d(input);
    else if(input->var_type[e_u_int] == 1)
        ft_print_d(input);
    else if(input->var_type[e_hex] == 1)
        ft_print_x(input);
    else if(input->var_type[e_pointer] == 1)
        ft_print_p(input);
    else if(input->var_type[e_percentage] == 1)
        ft_print_prcnt(input);
    else
    {
        int len;
        int diff;
        int printlen;
        int m_sign_width;
        len = ft_strlen(input->output);
        diff = input->width - len;

        if(input->flags[e_minus])
        {
            m_sign_width = 0;
            if(input->prs_flag)
            {
                if(input->prs > len)
                {
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
                    while (m_sign_width < input->prs)
                    {
                        ft_putchar_fd(*input->output, 1);
                        input->output++;
                        input->length++;
                        m_sign_width++;
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
                if(input-> prs_flag && input->width > input->prs)
                {
                    int width_dif = input->width - input->prs;
                    if(input->prs > (int)ft_strlen(input->output))
                        width_dif += input->prs - (int)ft_strlen(input->output);
                    input->length += width_dif;
                    while (width_dif > 0)
                    {
                        ft_putchar_fd(input->pad, 1);
                        width_dif--;
                    }
                }
                else
                {
                    input->length += input->width - ft_strlen(input->output);
                    while (diff > 0)
                    {
                        ft_putchar_fd(input->pad, 1);
                        diff--;
                        // input->length++;
                    }
                }
            }
            if(input->prs_flag )
            {
                if (input->prs < len)
                {
                    printlen = input->prs;
                    if(ft_strncmp(input->output, "(null)", 6) == 0 && input->prs == 0)
                    {
                        input->output = "";
                        printlen = 0;
                    }
                }
                else
                {
                    printlen = len;
                }
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
    }
    input->format++;
}