/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:37:49 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 10:37:52 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void
	ft_print_p(t_input *input)
{
	unsigned long long	num;
	char				*p;

	num = (unsigned long long) va_arg(input->arguments, void *);
	input->minus_sign = 0;
	if (num < 0)
	{
		num *= -1;
		input->minus_sign = 1;
	}
	input->output = ft_itoa_hex(num, 0);
	p = input->output;
	ft_mng_output(input);
	if (p != NULL)
		free(p);
	p = NULL;
}
