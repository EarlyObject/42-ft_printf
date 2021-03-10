/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:54:22 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/07 17:20:16 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*temp;

	if (!lst)
		return (NULL);
	if (!(temp = ft_lstnew((*f)(lst->content))))
		return (NULL);
	first = temp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (first);
}
