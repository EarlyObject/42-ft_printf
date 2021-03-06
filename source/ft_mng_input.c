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

#include "../includes/ft_printf.h"

void
	mng_flg_wdth_prs(t_input *input)
{
	int		i;

	input->output = NULL;
	input->format++;
	ft_mng_flags(input);
	ft_mng_width(input);
	ft_mng_precision(input);
	i = 0;
	while (i < 7)
		input->var_type[i++] = 0;
}

void
	ft_mng_input(t_input *input)
{
	char	*p;

	mng_flg_wdth_prs(input);
	ft_mng_format(input);
	p = input->output;
	if (input->var_type[e_string] == 1)
		ft_print_s(input);
	else if (input->var_type[e_char] == 1)
		ft_print_c(input);
	else if (input->var_type[e_int] == 1 || input->var_type[e_u_int] == 1)
		ft_print_d(input);
	else if (input->var_type[e_hex] == 1)
		ft_print_x(input);
	else if (input->var_type[e_pointer] == 1)
		ft_print_p(input);
	else if (input->var_type[e_percentage] == 1)
		ft_print_prcnt(input);
	else
	{
		return ;
	}
	if (p != NULL)
		free(p);
	input->format++;
}
