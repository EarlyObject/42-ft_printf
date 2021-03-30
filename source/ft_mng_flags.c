/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:45:17 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/19 12:45:18 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
    ft_mng_flags(t_input *input)
{
    input->flags[e_minus] = 0;
    input->flags[e_zero] = 0;
    while (*input->format == '-' || *input->format == '0')
    {
        if (*input->format == '-')
            input->flags[e_minus] = 1;
        else
            input->flags[e_zero] = 1;
        input->format++;
    }
    if(input->flags[e_minus])
        input->flags[e_zero] = 0;
    input->pad = input->flags[e_zero] ? '0' : ' ';
}
