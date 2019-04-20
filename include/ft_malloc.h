#ifndef FT_MALLOC_FT_MALLOC_H_
# define FT_MALLOC_FT_MALLOC_H_

# include <stdlib.h>

/**
 * Allowed functions
 *
 * mmap(2) - claim and return the memory zones to the system
 * munmap(2) - claim and return the memory zones to the system
 * getpagesize(3)
 * getrlimit(2)
 * lpthread
 */

# define N_BLOCKS 		100
# define N_ZONES		3

typedef enum 			e_mem_block_size
{
						TINY = 512,
						SMALL = 1024
}						t_mem_block_size;

typedef struct 			s_memblock
{
	size_t				size;
	struct s_memblock	*next;
}						t_memblock;

typedef struct			s_memzone
{
	t_mem_block_size	type;
	t_memblock			*ptr;
	t_memblock			*start;
}						t_memzone;

t_memzone				g_zones_array[N_ZONES];

/**
 * -) deallocates the memory allocation pointed to by “ptr”.
 * +) If “ptr” is a NULL pointer, no operation is performed
 */
void    ft_free(void *ptr);
/**
 * -) tries to change the size of the allocation pointed to by “ptr” to “size”, and returns “ptr”.
 * -) If there is not enough room to enlarge the memory allocation pointed to by ptr, realloc() creates a new allocation,
 * 		copies as much of the old data pointed to by “ptr” as will fit to the new allocation, frees the old allocation,
 * 		and returns a pointer to the allocated memory
 * -) If there is an error, the malloc() et realloc() functions return a NULL pointer.
 */
void    *ft_realloc(void *ptr, size_t size);

/**
 * -) allocates “size” bytes of memory and returns a pointer to the allocated memory
 * -) If there is an error, the malloc() et realloc() functions return a NULL pointer.
 */
void    *ft_malloc(size_t size);
/**
 * allows visual on the state of the allocated memory zones.
 *
 * Example:
 * TINY : 0xA0000
 * 0xA0020 - 0xA004A : 42 bytes
 * 0xA006A - 0xA00BE : 84 bytes
 * SMALL : 0xAD000
 * 0xAD020 - 0xADEAD : 3725 bytes
 * LARGE : 0xB0000
 * 0xB0020 - 0xBBEEF : 48847 bytes
 * Total : 52698 bytes
 */
void	show_alloc_mem();

/**
 * displays more details, for example, a history of allocations, or an hexa dump of the allocated zones.
 */
void	show_alloc_mem_ex();

/**
 * BONUS:
 *
 * -) Manage the malloc debug environment variables. You can imitate those from malloc system or invent your own.
 * -) Create a show_alloc_mem_ex() function that displays more details, for example, a history of allocations, or an hexa dump of the allocated zones.
 * -) “Defragment” the freed memory.
 * -) Manage the use of your malloc in a multi-threaded program (so to be “thread safe” using the pthread lib).
 */

#endif  // FT_MALLOC_FT_MALLOC_H_
