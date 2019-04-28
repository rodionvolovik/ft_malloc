/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <rvolovik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 07:36:21 by rvolovik          #+#    #+#             */
/*   Updated: 2019/04/28 15:34:18 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>
#include <unistd.h>
#include <sys/mman.h>
#include <libft.h>

#include <stdio.h>

pthread_mutex_t		g_mutex = PTHREAD_MUTEX_INITIALIZER;

t_block				*get_last_block(t_block *head)
{
	t_block	*p_block;

	if (!head)
		return (NULL);
	p_block = head;
	while(p_block->next)
	{
		p_block = p_block->next;
	}
	return (p_block);
	
}

t_block				*mmap_request(size_t size)
{
	t_block	*p_block;

	if ((p_block = mmap(0, size, PROT_READ | PROT_WRITE | PROT_EXEC,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
	{
		return (NULL);
	}
	return (p_block);
}

t_block				*mmap_block(t_block **block, size_t size)
{
	// ft_putstr("mmap_block START\n");
	t_block	*p_block;
	t_block *p_block_last;

	p_block = *block;
	if (p_block == NULL)
	{
		p_block = mmap_request(size);
		*block = p_block;
		p_block->size = size;
		// ft_putstr("mmap_block NEW\n");
		return (p_block);
	}
	else
	{
		p_block_last = get_last_block(p_block);
		p_block_last->next = mmap_request(size);
		p_block_last->next->size = size;
		// ft_putstr("mmap_block APPEND\n");
		return (p_block_last->next);
	}
	// ft_putstr("mmap_block END\n");
	return (NULL);
}

t_block				*allocate_memory(size_t size)
{
	// ft_putstr("allocate_memory START\n");
	t_block	*p_block;

	if (size < TINY)
		p_block = mmap_block(&g_memory[I_TINY], TINY * N_BLOCKS);
	else if (size < SMALL)
		p_block = mmap_block(&g_memory[I_SMALL], SMALL * N_BLOCKS);
	else
		p_block = mmap_block(&g_memory[I_LARGE], BLOCK_SIZE(size));
	if (p_block->size - BLOCK_SIZE(size) == 0)
		p_block->next = NULL;
	else
	{
		p_block->next = (t_block*)((void*)p_block + BLOCK_SIZE(size));
		p_block->next->size = p_block->size - BLOCK_SIZE(size) - sizeof(t_block);
		p_block->next->memory = (void*)p_block->next + sizeof(t_block);
		p_block->next->free = 1;
		p_block->next->next = NULL;
	}
	p_block->memory = (void*)p_block + sizeof(t_block);
	p_block->size = size;
	ft_bzero(p_block->memory, p_block->size);
	// ft_putstr("allocate_memory END\n");
	return (p_block);
}

t_block				*cut_block(t_block **block, size_t size)
{
	t_block	*p_block;

	p_block = *block;
	p_block->free = 0;
	p_block->next = (t_block*)((void*)p_block + BLOCK_SIZE(size));
	p_block->next->size = p_block->size - BLOCK_SIZE(size);
	p_block->next->memory = (void*)p_block->next + sizeof(t_block);
	p_block->next->free = 1;
	p_block->next->next = NULL;
	p_block->size = size;

	return p_block;
}

t_block				*find_free_block(t_block** head, size_t size)
{
	t_block	*p_block;

	p_block = *head;
	while(p_block)
	{
		if (p_block->free && p_block->size == size)
		{
			p_block->free = 0;
			ft_bzero(p_block->memory, p_block->size);
			return (p_block);
		}
		p_block = p_block->next;
	}
	p_block = *head;
	while(p_block)
	{
		if (p_block->free && p_block->size > BLOCK_SIZE(size))
		{
			return cut_block(&p_block, size);
		}
		p_block = p_block->next;
	}
	return (NULL);
}

t_block				*find_memory(size_t size)
{
	t_block	*p_block;

	if (size < TINY)
		p_block = find_free_block(&g_memory[I_TINY], size);
	else if (size < SMALL)
		p_block = find_free_block(&g_memory[I_SMALL], size);
	else
		p_block = find_free_block(&g_memory[I_LARGE], size);
	return p_block;
}

void				*malloc(size_t size)
{
	t_block	*p_block;

	if (size < 1)
		return ((void*)NULL);

	pthread_mutex_lock(&g_mutex);
	if (!(p_block = find_memory(size)))
	{
		p_block = allocate_memory(size);
	}
	pthread_mutex_unlock(&g_mutex);
	return ((void*)p_block->memory);
}