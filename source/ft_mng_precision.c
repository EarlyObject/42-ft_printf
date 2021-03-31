/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:32:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/19 14:32:15 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void
	ft_mng_precision(t_input *input)
{
	input->prs_flag = 0;
	input->prs = 0;
	if (*input->format == '.')
	{
		input->prs_flag = 1;
		input->format++;
		if (*input->format == '*')
		{
			input->prs = va_arg(input->arguments, int);
			if (input->prs < 0)
			{
				input->prs = 0;
				input->prs_flag = 0;
			}
			input->format++;
		}
		while (*input->format >= '0' && *input->format <= '9')
		{
			input->prs *= 10;
			input->prs += *input->format - '0';
			input->format++;
		}
	}
}
