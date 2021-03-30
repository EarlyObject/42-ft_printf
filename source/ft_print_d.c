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

    if (input->var_type[e_int] == 1)
        num = (int) va_arg(input->arguments, long long);
    else
        num = (unsigned int) va_arg(input->arguments, long long);
    input->minus_sign = 0;
    if(num < 0)
    {
        num *= -1;
        input->minus_sign = 1;
    }
    if(input->prs_flag && num == 0)
        input->output = ft_strdup("");
    else
        input->output = input->var_type[e_int] == 1 ? ft_itoa(num) : ft_uitoa(num);
    ft_mng_output(input);
}
