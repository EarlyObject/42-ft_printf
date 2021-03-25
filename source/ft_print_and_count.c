/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_and_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:17:19 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/25 18:18:01 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void
	ft_print_and_count(t_input *input)
{
	ft_putchar_fd(*input->output, 1);
	input->output++;
	input->length++;
}
