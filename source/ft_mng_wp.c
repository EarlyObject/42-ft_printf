/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_wp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:28:03 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 12:28:05 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
    ft_mng_wp(t_input *input, int len, int diff)
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
            //input->length += input->width - ft_strlen(input->output);
           /* if(input->minus_sign)
                input->length += 1;*/
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