/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:07:09 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/26 12:07:32 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
    ft_print_c(t_input *input)
{
    char c;

    c = *input->output;
    if(input->flags[e_minus] == 1)
        ft_putchar_fd(c, 1);
    if(input->width)
    {
        input->length += (input->width - 1);
        input->width--;
        input->pad = (input->flags[e_zero] == 1
                && input->flags[e_minus] != 1) ? '0' : ' ';
        while (input->width-- > 0)
            ft_putchar_fd(input->pad, 1);
    }
    if(input->flags[e_minus] != 1)
        ft_putchar_fd(c, 1);
    input->length++;
}
