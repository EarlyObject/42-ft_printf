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
    ft_print_d(t_input *input)
{
    long long num;
    int len;
    int diff;

    if (input->var_type[e_int] == 1) {
        num = (int) va_arg(input->arguments, long long);
    } else {
        num = (unsigned int) va_arg(input->arguments, long long);
    }
    input->minus_sign = 0;
    if(num < 0)
    {
        num *= -1;
        input->minus_sign = 1;
    }
    if(input->prs_flag && num == 0)
        input->output = "";
    else
        input->output = input->var_type[e_int] == 1 ? ft_itoa(num) : ft_uitoa(num);
    len = ft_strlen(input->output);
    diff = (input->prs && input->prs > len) ?
            input->width - input->prs : input->width - len;
    if(input->minus_sign)
        diff -= 1;
    if(input->flags[e_minus])
        ft_mng_e_minus(input, len, diff);
    else
        ft_mng_wp(input, len, diff);

}
