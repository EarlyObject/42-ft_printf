/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:37:49 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 10:37:52 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
    ft_print_p(t_input *input)
{
    unsigned long long num;
    int len;
    int diff;

    num = (unsigned long long) va_arg(input->arguments,  void *);
    input->minus_sign = 0;
    if(num < 0)
    {
        num *= -1;
        input->minus_sign = 1;
    }
    input->output = ft_itoa_hex(num, 0);

    len = ft_strlen(input->output);
    if (input->prs && input->prs > len) {
        diff = input->width - input->prs;
    }
    else
            diff =  input->width - len;
    if(input->minus_sign)
        diff -= 1;
    if(input->flags[e_minus])
        ft_mng_e_minus(input, len, diff);
    else
        ft_mng_wp(input, len, diff);
}
