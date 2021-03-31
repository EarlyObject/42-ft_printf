/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:07:09 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/26 12:07:32 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void
	ft_print_c(t_input *input)
{
	char	c;

	c = *input->output;
	if (input->flags[e_minus] == 1)
		ft_count_putchar(input, c);
	if (input->width)
	{
		input->width--;
		if (input->flags[e_zero] == 1
			&& input->flags[e_minus] != 1)
			input->pad = '0';
		else
			input->pad = ' ';
		while (input->width-- > 0)
			ft_count_putchar(input, input->pad);
	}
	if (input->flags[e_minus] != 1)
		ft_count_putchar(input, c);
}
