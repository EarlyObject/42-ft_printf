/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:13:07 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/19 13:13:08 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

void ft_manage_format(t_input *input)
{
    char *str_arg;

    str_arg = "";
    if(*input->format == 's')
    {
        input->var_type[e_string] = 1;
        str_arg = va_arg(input->arguments, char *);
    }
    else if (*input->format == 'c')
    {
        input->var_type[e_char] = 1;
        char c = (char)va_arg(input->arguments, int);
        str_arg = ft_strdup(&c);
    }
    else if (*input->format  == 'p')
    {
        unsigned long long n = va_arg(input->arguments, unsigned long long);
        str_arg = ft_itoa_hex(n, 0);
    }

    else if (*input->format  == 'd' || *input->format == 'i')
        input->var_type[e_int] = 1;
    else if (*input->format == 'u')
        input->var_type[e_u_int] = 1;
    else if (*input->format == 'X' || *input->format == 'x')
    {
        input->var_type[e_hex] = 1;
       /* unsigned long long n = va_arg(input->arguments, unsigned int);
        str_arg = ft_itoa_hex(n, *input->format);*/
    }
    if(str_arg == NULL)
        str_arg = "(null)";
    input->output = str_arg;
}
