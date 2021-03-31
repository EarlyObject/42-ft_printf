/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:56:24 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/24 08:56:27 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void
	s_manage_e_minus(t_input *input, int len)
{
	int	m_sign_width;

	m_sign_width = 0;
	if (!input->prs_flag || input->prs > len)
	{
		while (*input->output)
		{
			ft_print_and_count(input);
			m_sign_width++;
		}
	}
	else
	{
		while (m_sign_width < input->prs)
		{
			ft_print_and_count(input);
			m_sign_width++;
		}
	}
	while (m_sign_width < input->width)
	{
		ft_count_putchar(input, input->pad);
		m_sign_width++;
	}
}

void
	s_manage_prs(t_input *input, int len)
{
	int	printlen;

	if (input->prs < len)
	{
		printlen = input->prs;
		if (ft_strncmp(input->output, "(null)", 6) == 0 && input->prs == 0)
		{
			input->output = "";
			printlen = 0;
		}
	}
	else
		printlen = len;
	while (*input->output && printlen-- > 0)
		ft_print_and_count(input);
}

void
	s_manage_width(t_input *input, int len, int diff)
{
	int	width_dif;

	if (input->width)
	{
		if (input->prs_flag && input->width > input->prs)
		{
			width_dif = input->width - input->prs;
			if (input->prs > len)
				width_dif += input->prs - len;
			while (width_dif-- > 0)
				ft_count_putchar(input, input->pad);
		}
		else
		{
			while (diff-- > 0)
				ft_count_putchar(input, input->pad);
		}
	}
	if (input->prs_flag)
		s_manage_prs(input, len);
	else
		while (*input->output)
			ft_print_and_count(input);
}

void
	ft_print_s(t_input *input)
{
	int		len;
	int		diff;
	char	*p;

	input->output = va_arg(input->arguments, char *);
	if (input->output == NULL)
		input->output = ft_strdup("(null)");
	else
		input->output = ft_strdup(input->output);
	p = input->output;
	len = ft_strlen(input->output);
	diff = input->width - len;
	if (input->flags[e_minus])
		s_manage_e_minus(input, len);
	else
		s_manage_width(input, len, diff);
	if (p != NULL)
		free(p);
	p = NULL;
}
