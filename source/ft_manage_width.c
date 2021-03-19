/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:18:57 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/19 14:18:58 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_manage_width(t_input *input)
{
    input->width = 0;
    while (*input->format >= '0' && *input->format <= '9')
    {
        input->width *= 10;
        input->width += *input->format - '0';
        input->format++;
    }
}