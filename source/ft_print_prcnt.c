/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prcnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:37:58 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 10:38:02 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
    ft_print_prcnt(t_input *input)
{
    /*int len;
    int diff;*/

    char c = '%';
    input->output = ft_strdup(&c);
    ft_print_c(input);
   /* ft_putchar_fd('%', 1);
    input->length++;*/
   /* len = ft_strlen(input->output);
    diff = input->width - len;
    if(input->flags[e_minus])
        s_manage_e_minus(input, len);
    else
        s_manage_width(input, len, diff);*/
}
