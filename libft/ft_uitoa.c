/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:44:26 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/15 19:44:31 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int
	count_ulen(unsigned int n)
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
	*ft_uitoa(unsigned int n)
{
	char				*p;
	unsigned int		len;

	len = count_ulen(n);
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (0);
	p[len] = '\0';
	while (len)
	{
	    p[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (p);
}
