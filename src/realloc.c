/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <rvolovik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 07:36:42 by rvolovik          #+#    #+#             */
/*   Updated: 2019/04/28 15:28:35 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>
#include <libft.h>

void	*realloc(void *ptr, size_t size)
{
	t_block	*p_block;
	t_block	*new_block;


	if (!ptr)
		return (void*)NULL;
	p_block = (void*)ptr - sizeof(t_block);
	if (!(find_allocated_block(p_block, I_TINY, 1) ||
		find_allocated_block(p_block, I_SMALL, 1) ||
		find_allocated_block(p_block, I_LARGE, 1)))
		return (void*)NULL;
	if (p_block->size < size)
	{
		new_block = malloc(size);
		ft_memmove(new_block, ptr, p_block->size);
		free(p_block);
	}
	else
	{
		ft_bzero(p_block + size, p_block->size - size);
		new_block = p_block;
	}
	return new_block;
}
