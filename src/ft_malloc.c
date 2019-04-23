#include <ft_malloc.h>
#include <unistd.h>
#include <sys/mman.h>

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

static size_t		get_min_page_size(size_t size_type)
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
		allocation_size += I_LARGE_PAGE;
	}
	allocation_size = (const_alignment + allocation_size / system_page_size) *
						system_page_size + sizeof(t_mempage);
	
	return allocation_size;
}

static t_memblock	*check_available_block(size_t size_type, size_t size)
{
	t_mempage	*p_mempage;

	if (g_pages_array[size_type])
	{
		p_mempage = g_pages_array[size_type];
		while(p_mempage)
		{
			if (p_mempage->available_memory >= size + sizeof(t_memblock))
			{
				// cut some memory from a free space and save a pointer to it Ex: return fragment_new_block(size_type, size);
			}
			p_mempage = p_mempage->next_page;
		}
	}

	return (t_memblock*)NULL;
}

static t_mempage	*allocate_new_page(size_t size)
{
	void*		p_new_page;
	t_mempage*	p_new_mempage;

	p_new_page = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC,
				MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	
	if (p_new_page == MAP_FAILED)
	{
		return NULL;
	}
	
	p_new_mempage = (t_mempage*)p_new_page;
	p_new_mempage->available_memory = size - sizeof(t_mempage);
	p_new_mempage->total_memory = size;
	p_new_mempage->next_page = NULL;
	p_new_mempage->p_first_memblock = NULL;

	return (t_mempage*)p_new_mempage;
}

static int			add_memory_page(size_t size_type)
{
	t_mempage	*p_mempage;
	t_mempage	*p_last_mempage;

	p_mempage = g_pages_array[size_type];
	while(p_mempage)
	{
		p_last_mempage = p_mempage;
		p_mempage = p_mempage->next_page;
	}

	p_last_mempage->next_page = allocate_new_page(get_min_page_size(size_type));

	return (p_last_mempage->next_page == NULL ? 0 : 1);
}

void				*ft_malloc(size_t size)
{
	t_memblock			*p_memblock;
	size_t				size_type;

	if (size < 1)
	{
		return (void *)NULL;
	}

	size_type = get_block_size_type(size);

	pthread_mutex_lock(&g_mutex);
	while (!(p_memblock = check_available_block(size_type, size)))
	{
		if (!add_memory_page(size_type))
		{
			return (void*)NULL;
		}
	}
	pthread_mutex_unlock(&g_mutex);
	
	return (void *)(p_memblock + sizeof(t_memblock));
}
