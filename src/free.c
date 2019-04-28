/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <rvolovik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 07:36:37 by rvolovik          #+#    #+#             */
/*   Updated: 2019/04/28 15:26:56 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>
#include <libft.h>
#include <sys/mman.h>

int		find_allocated_block(t_block *block, int index, int make_free)
{
	t_block	*iter;

	iter = g_memory[index];
	while (iter)
	{
		if (iter == block)
		{
			iter->free = make_free;
			if (!make_free)
				ft_bzero(iter->memory, iter->size);
			return (1);
		}
		iter = iter->next;
	}
	return (0);
}

void	unmap_large(t_block **block)
{
	t_block	*to_remove;
	t_block	*p_previous;
	t_block	*iter;

	to_remove = *block;
	iter = g_memory[I_LARGE];
	if (g_memory[I_LARGE] == to_remove)
	{
		g_memory[I_LARGE] = NULL;
	}
	while (iter)
	{
		if (iter == to_remove)
		{
			p_previous->next = iter->next;
			break;
		}
		p_previous = iter;
		iter = iter->next;
	}
	munmap(to_remove, BLOCK_SIZE(to_remove->size));
	return;
}

void	free_block(t_block **block)
{
	t_block	*p_block;
	
	p_block = *block;
	if (find_allocated_block(p_block, I_TINY, 0) || find_allocated_block(p_block, I_SMALL, 0))
	{
		return;
	}
	else if (find_allocated_block(p_block, I_LARGE, 0))
	{
		unmap_large(&p_block);
	}
	return;
}

void	free(void *ptr)
{
	t_block	*p_block;

	if (ptr != NULL)
	{
		p_block = (void*)ptr - sizeof(t_block);
		free_block(&p_block);
	}
	return;
}
