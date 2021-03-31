/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prcnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:37:58 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 10:38:02 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void
	ft_print_prcnt(t_input *input)
{
	char	c;

	c = '%';
	input->output = ft_strdup(&c);
	ft_print_c(input);
	free(input->output);
}
