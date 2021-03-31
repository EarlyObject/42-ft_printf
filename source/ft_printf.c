/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:05:38 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/12 14:32:33 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int
	ft_printf(const char *format, ...)
{
	t_input	*input;
	int		len;

	input = (t_input *) ft_calloc(1, sizeof(t_input));
	input->format = format;
	va_start(input->arguments, format);
	input->length = 0;
	while (*input->format)
	{
		while (*input->format && *input->format != '%')
		{
			ft_count_putchar(input, *input->format);
			input->format++;
		}
		if (*input->format && *input->format == '%')
			ft_mng_input(input);
	}
	va_end(input->arguments);
	len = input->length;
	free(input);
	return (len);
}
