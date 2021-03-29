/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_e_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:27:45 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 12:27:50 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
    ft_mng_e_minus(t_input *input, int len, int diff)
{
    int m_sign_width;

    if(input->minus_sign)
    {
        ft_count_putchar(input, '-');
        input->width--;
    }
    if(input->prs_flag)
    {
        if(input->prs > len)
        {
            m_sign_width = input->prs - len;
            while (m_sign_width-- > 0)
                ft_count_putchar(input, '0');
        }
    }
    while(*input->output)
        ft_print_and_count(input);
    while (diff-- > 0)
        ft_count_putchar(input, input->pad);
}