/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:49:47 by rvolovik          #+#    #+#             */
/*   Updated: 2016/11/30 13:49:48 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*begin;

	res = (*f)(lst);
	begin = res;
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			res->next = (*f)(lst);
			res = res->next;
		}
	}
	return (begin);
}
