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

#include "../includes/ft_printf.h"

void
	ft_print_d(t_input *input)
{
	long long	num;
	char		*p;

	if (input->var_type[e_int] == 1)
		num = (int) va_arg(input->arguments, long long);
	else
		num = (unsigned int) va_arg(input->arguments, long long);
	input->minus_sign = 0;
	if (num < 0)
	{
		num *= -1;
		input->minus_sign = 1;
	}
	if (input->prs_flag && num == 0)
		input->output = ft_strdup("");
	else if (input->var_type[e_int] == 1)
		input->output = ft_itoa(num);
	else
		input->output = ft_uitoa(num);
	p = input->output;
	ft_mng_output(input);
	if (p != NULL)
		free(p);
	p = NULL;
}
