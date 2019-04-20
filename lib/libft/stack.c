/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <rvolovik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 20:09:10 by rvolovik          #+#    #+#             */
/*   Updated: 2017/06/01 20:26:49 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_stack	*append(t_stack *head, void *data)
{
	t_stack	*new;
	t_stack	*ptr;

	ptr = NULL;
	new = (t_stack*)malloc(sizeof(t_stack));
	new->content = data;
	new->next = NULL;
	if (!head)
		head = new;
	else
	{
		ptr = head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (head);
}

t_stack	*push(t_stack *head, void *data)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->content = data;
	new->next = head;
	head = new;
	return (head);
}

t_stack	*pop(t_stack **head)
{
	t_stack	*topop;

	topop = *head;
	*head = (*head)->next;
	return (topop);
}
