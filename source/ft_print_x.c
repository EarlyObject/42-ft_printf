/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:56:36 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 10:38:41 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
    ft_print_x(t_input *input)
{
    unsigned long long num;
    char *p;

    num = (unsigned int) va_arg(input->arguments,  unsigned long long);
    input->minus_sign = 0;
    if(num < 0)
    {
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
    p = input->output;
    ft_mng_output(input);
    if(p != NULL)
        free(p);
    p = NULL;
}
