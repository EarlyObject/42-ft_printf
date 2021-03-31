/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:08:09 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/12 15:11:21 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <errno.h>

enum				e_flags
{
	e_minus,
	e_zero
};

enum				e_var_type
{
	e_char,
	e_string,
	e_pointer,
	e_int,
	e_u_int,
	e_hex,
	e_percentage
};

typedef struct s_input
{
	const char		*format;
	char			*output;
	va_list			arguments;
	int				flags[2];
	int				width;
	int				prs_flag;
	int				prs;
	int				length;
	char			pad;
	int				var_type[7];
	int				minus_sign;
}				t_input;

int		ft_printf(const char *format, ...);
void	ft_mng_input(t_input *input);
void	ft_mng_flags(t_input *input);
void	ft_mng_width(t_input *input);
void	ft_mng_precision(t_input *input);
void	ft_mng_format(t_input *input);
void	ft_print_s(t_input *input);
void	ft_print_c(t_input *input);
void	ft_print_d(t_input *input);
void	ft_print_x(t_input *input);
void	ft_print_p(t_input *input);
void	ft_print_prcnt(t_input *input);
void	ft_print_and_count(t_input *input);
void	ft_mng_wd_prs(t_input *input, int len, int diff);
void	ft_mng_e_minus(t_input *input, int len, int diff);
void	ft_count_putchar(t_input *input, char c);
void	ft_mng_output(t_input *input);

#endif
