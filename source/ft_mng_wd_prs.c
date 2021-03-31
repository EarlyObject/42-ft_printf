/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_wd_prs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:28:03 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 12:28:05 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void
	ft_mng_wd_prs(t_input *input, int len, int diff)
{
	if (input->width)
	{
		if (input->prs_flag)
			input->pad = ' ';
		if (input->minus_sign)
		{
			if (input->pad == '0')
				ft_count_putchar(input, '-');
			while (diff-- > 0)
				ft_count_putchar(input, input->pad);
			if (input->pad == ' ')
				ft_count_putchar(input, '-');
		}
		else
			while (diff-- > 0)
				ft_count_putchar(input, input->pad);
	}
	else if (input->minus_sign)
		ft_count_putchar(input, '-');
	while (input->prs_flag && input->prs - len++ > 0)
		ft_count_putchar(input, '0');
	while (*input->output)
		ft_print_and_count(input);
}
