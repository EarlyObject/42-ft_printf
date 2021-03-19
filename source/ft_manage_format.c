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

void ft_manage_format(t_input *input)
{
    char *str_arg;
    int memreserved;

    memreserved = 0;
    str_arg = "";
    if(*input->format == 's')
    {
        str_arg = va_arg(input->arguments, char *);
        input->var_type[e_string] = 1;
    }
    else if (*input->format == 'c')
    {
        char c = (char)va_arg(input->arguments, int);
        str_arg = (char *)malloc(2 * sizeof(char));
        *str_arg = c;
        *(str_arg + 1) = '\0';
        memreserved = 1;
    }
    else if (*input->format  == 'p')
    {
        unsigned long long n = va_arg(input->arguments, unsigned long long);
        str_arg = ft_itoa_hex(n, 0);
    }
    else if (*input->format  == 'd' || *input->format == 'i')
    {
        str_arg = ft_itoa(va_arg(input->arguments, int));
    }
    else if (*input->format == 'u')
    {
        str_arg = ft_uitoa(va_arg(input->arguments, int));
    }
    else if (*input->format == 'X' || *input->format == 'x')
    {
        unsigned long long n = va_arg(input->arguments, unsigned int);
        str_arg = ft_itoa_hex(n, *input->format);
    }
    if(str_arg == NULL)
        str_arg = "(null)";
    input->output = str_arg;
}
