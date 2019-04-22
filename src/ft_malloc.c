#include <ft_malloc.h>

static size_t		get_block_size(size_t size)
{
	if (size <= (int)TINY)
	{
		return (I_SMALL_ZONE);
	}
	else if (size <= (int)SMALL)
	{
		return (I_SMALL_ZONE);
	}
	return (I_LARGE_ZONE);
}

static size_t		align_memory_size(size_t size)
{
	//glibc malloc on x86-64 returns 16-byte-aligned pointers
	return (size != 0 ?
			((size - 1) / MEM_ALIGNMENT + 1) * MEM_ALIGNMENT : MEM_ALIGNMENT);
}

static size_t		*cut_new_block(t_memblock *p_memblock, size_t size)
{

}

static t_memblock	*find_allocated_page_space(size_t size_type, size_t size)
{
	t_memblock		*p_memblock;

	p_memblock = g_zones_array[size_type].memory_empty;
	while (p_memblock)
	{
		if (p_memblock->total_free >= size)
		{
			return cut_new_block(p_memblock, size);
		}
		p_memblock = p_memblock->next_memblock;
	}

	return (t_memblock*)NULL;
}

static t_memblock	*get_free_mem_block(size_t size_type, size_t size)
{
	t_memblock		*p_memblock;

	if (!(p_memblock = find_allocated_page_space(size_type, size)))
	{
		p_memblock = allocate_new_page_memory(size_type, size);
	}

	return p_memblock;
}

void				*ft_malloc(size_t size)
{
	t_memblock			*p_memblock;
	size_t				size_type;

	if (size < 1)
	{
		return (void *)NULL;
	}

	size_type = get_block_size(size);
	size = align_memory_size(size);

	pthread_mutex_lock(&g_mutex);
	p_memblock = get_free_mem_block(size_type, size);
	pthread_mutex_unlock(&g_mutex);
	
	return (void *)(p_memblock +
					align_memory_size(sizeof(t_mem_block_size)));
}
