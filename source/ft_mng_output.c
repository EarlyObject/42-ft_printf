/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:55:37 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/30 16:55:39 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	ft_mng_output(t_input *input)
{
	int	len;
	int	diff;

	len = ft_strlen(input->output);
	if (input->prs && input->prs > len)
		diff = input->width - input->prs;
	else
		diff = input->width - len;
	if (input->minus_sign)
		diff -= 1;
	if (input->flags[e_minus])
		ft_mng_e_minus(input, len, diff);
	else
		ft_mng_wd_prs(input, len, diff);
}
