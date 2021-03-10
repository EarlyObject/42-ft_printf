/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:01:15 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/09 13:13:35 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int
	count_len(int n)
{
	unsigned int len;

	len = (n <= 0) ? 1 : 0;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char
	*ft_itoa(int n)
{
	char				*p;
	char				sign;
	unsigned int		len;

	sign = (n < 0) ? '-' : '\0';
	len = count_len(n);
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (0);
	p[len] = '\0';
	while (len)
	{
		if (n < 0)
			p[--len] = -(n % 10) + '0';
		else
			p[--len] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		p[len] = sign;
	return (p);
}
