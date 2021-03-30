/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:54:23 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/26 12:08:20 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_mng_input(t_input *input)
{
    int i;
    char *p;

    ft_mng_flags(input);
    ft_mng_width(input);
    ft_mng_precision(input);
    i = 0;
    while (i < 7)
        input->var_type[i++] = 0;
    ft_mng_format(input);
    p = input->output;
    if(input->var_type[e_string] == 1)
        ft_print_s(input);
    else if(input->var_type[e_char] == 1)
        ft_print_c(input);
    else if(input->var_type[e_int] == 1 || input->var_type[e_u_int] == 1)
        ft_print_d(input);
    else if(input->var_type[e_hex] == 1)
        ft_print_x(input);
    else if(input->var_type[e_pointer] == 1)
        ft_print_p(input);
    else if(input->var_type[e_percentage] == 1)
        ft_print_prcnt(input);
    if(p != NULL)
        free(p);
    input->format++;
}