/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:18:57 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/22 11:12:21 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void
	ft_mng_width(t_input *input)
{
	input->width = 0;
	if (*input->format == '*')
	{
		input->width = va_arg(input->arguments, int);
		if (input->width < 0)
		{
			input->width = input->width * -1;
			input->flags[e_minus] = 1;
			input->pad = ' ';
		}
		input->format++;
	}
	while (*input->format >= '0' && *input->format <= '9'
		   && *input->format != '*')
	{
		input->width *= 10;
		input->width += *input->format - '0';
		input->format++;
	}
}
