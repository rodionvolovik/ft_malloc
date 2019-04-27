/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <rvolovik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 07:36:21 by rvolovik          #+#    #+#             */
/*   Updated: 2019/04/27 11:13:26 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>
#include <unistd.h>
#include <sys/mman.h>
#include <libft.h>

#include <stdio.h>

pthread_mutex_t		g_mutex = PTHREAD_MUTEX_INITIALIZER;

static size_t		get_block_size_type(size_t size)
{
	if (size <= TINY)
	{
		return (I_TINY_PAGE);
	}
	else if (size <= SMALL)
	{
		return (I_SMALL_PAGE);
	}
	return (I_LARGE_PAGE);
}

static size_t		get_min_page_size(size_t size, size_t size_type)
{
	const unsigned int	const_alignment = 1;
	size_t				allocation_size;
	size_t				system_page_size;

	allocation_size = 0;
	system_page_size = getpagesize();
	if (size_type != I_LARGE_PAGE)
	{
		allocation_size += (size_type == I_TINY_PAGE ? TINY : SMALL) * N_BLOCKS;
	}
	else
	{
		allocation_size += size + sizeof(t_mempage);
	}
	allocation_size = (const_alignment + allocation_size / system_page_size) *
						system_page_size;
	return (allocation_size);
}

t_memblock			*cut_new_memory_block(t_mempage *p_mempage_current,
											size_t size)
{
	t_memblock	*p_new_memblock;
	t_memblock	*p_memblock;
	t_memblock	*p_memblock_lst;

	if (p_mempage_current->p_first_memblock)
	{
		p_memblock = p_mempage_current->p_first_memblock;
		while (p_memblock)
		{
			p_memblock_lst = p_memblock;
			p_memblock = p_memblock->p_next_memblock;
		}
		p_memblock_lst->p_next_memblock = (t_memblock*)((char*)p_memblock_lst +
									p_memblock_lst->size + sizeof(t_memblock));
	}
	else
	{
		p_new_memblock = (t_memblock*)((char*)p_mempage_current +
						sizeof(t_mempage));
		p_mempage_current->p_first_memblock = p_new_memblock;
	}
	p_new_memblock->size = size + TERMINATE_MEM - sizeof(t_memblock);
	p_new_memblock->p_next_memblock = NULL;
	p_new_memblock->p_first_chunk = (char*)p_new_memblock + sizeof(t_memblock);
	p_mempage_current->available_memory -= size + TERMINATE_MEM;
	return (p_new_memblock);
	// p_last_memblock_on_page = NULL;
	// p_memblock = p_mempage_current->p_first_memblock;
	// while (p_memblock)
	// {
	// 	p_last_memblock_on_page = p_memblock;
	// 	p_memblock = p_memblock->p_next_memblock;
	// }
	// if (p_last_memblock_on_page)
	// {
	// 	p_new_memblock = (t_memblock*)((char*)p_last_memblock_on_page +
	// 					p_last_memblock_on_page->size + sizeof(t_memblock));
	// 	p_last_memblock_on_page->p_next_memblock = p_new_memblock;
	// }
	// else
	// {
	// 	p_new_memblock = (t_memblock*)((char*)p_mempage_current +
	// 					sizeof(t_mempage));
	// 	p_mempage_current->p_first_memblock = p_new_memblock;
	// }
	// ft_bzero(p_new_memblock, size + TERMINATE_MEM);
	// p_new_memblock->size = size - sizeof(t_memblock) + 1;
	// p_new_memblock->p_next_memblock = NULL;
	// p_new_memblock->p_first_chunk = (char*)p_new_memblock + sizeof(t_memblock);
	// p_mempage_current->available_memory -= size;
	// return (p_new_memblock);
}

static t_memblock	*check_available_block(size_t size, size_t size_type)
{
	t_mempage	*p_mempage;
	t_memblock	*p_memblock;

	if (g_pages_array[size_type] != NULL)
	{
		p_mempage = g_pages_array[size_type];
		while (p_mempage)
		{
			if (p_mempage->available_memory >= size + sizeof(t_memblock))
			{
				return (cut_new_memory_block(p_mempage, size +
													sizeof(t_memblock)));
			}
			p_mempage = p_mempage->next_page;
		}
	}
	return ((t_memblock*)NULL);
}

static t_mempage	*allocate_new_page(size_t size)
{
	void		*p_new_page;
	t_mempage	*p_new_mempage;

	p_new_page = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC,
				MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (p_new_page == MAP_FAILED)
	{
		return (NULL);
	}
	ft_bzero(p_new_page, size);
	p_new_mempage = (t_mempage*)p_new_page;
	p_new_mempage->available_memory = size - sizeof(t_mempage);
	p_new_mempage->total_memory = size;
	p_new_mempage->next_page = NULL;
	p_new_mempage->p_first_memblock = NULL;
	return ((t_mempage*)p_new_mempage);
}

static int			add_memory_page(size_t size, size_t size_type)
{
	t_mempage	*p_last_mempage;
	t_mempage	*p_mempage;
	t_mempage	*p_new_mempage;

	p_new_mempage = allocate_new_page(get_min_page_size(size, size_type));
	if (g_pages_array[size_type] == NULL)
	{
		g_pages_array[size_type] = p_new_mempage;
	}
	else
	{
		p_mempage = g_pages_array[size_type];
		while (p_mempage)
		{
			p_last_mempage = p_mempage;
			p_mempage = p_mempage->next_page;
		}
		p_last_mempage->next_page = p_new_mempage;
	}
	return (p_new_mempage == NULL ? 0 : 1);
}

void				*malloc(size_t size)
{
	t_memblock			*p_memblock;
	size_t				size_type;

	if (size < 1)
	{
		return (void *)NULL;
	}
	size_type = get_block_size_type(size);
	pthread_mutex_lock(&g_mutex);
	while (!(p_memblock = check_available_block(size, size_type)))
	{
		if (!add_memory_page(size, size_type))
		{
			return (void*)NULL;
		}
	}
	pthread_mutex_unlock(&g_mutex);
	return ((void *)(p_memblock->p_first_chunk));
}
